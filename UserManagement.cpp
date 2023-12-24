#include "UserManagement.h"

UserManagement::UserManagement(DataBaseConnection* connection) : connection(connection)
{

	connection->getDataBase()->prepare("getUserName", "SELECT user_name FROM \"Users\" WHERE user_id = $1;");
	connection->getDataBase()->prepare("getUserId", "SELECT user_id FROM \"Users\" WHERE user_name = $1;"); 
	connection->getDataBase()->prepare("getUsersByRole", "SELECT user_name FROM \"Users\" WHERE role_id = $1;");
	connection->getDataBase()->prepare("getProjectInvoledUsers", "SELECT DISTINCT user_name FROM \"Users\"\
        JOIN \"Tasks\" ON \"Tasks\".assignee_id = \"Users\".user_id WHERE project_id = $1");

}



QString UserManagement::getUserName(int userId)
{
	pqxx::transaction transaction(*connection->getDataBase());

	pqxx::result result = transaction.exec_prepared("getUserName", userId);

	return QString(result[0][0].is_null() ? "" : result[0][0].as<std::string>().c_str());

}

int UserManagement::getUserId(QString userName)
{
	pqxx::transaction transaction(*connection->getDataBase());

	pqxx::result result = transaction.exec_prepared("getUserId", userName.toStdString());

	return result[0][0].is_null() ? -1 : result[0][0].as<int>();

}



QStandardItemModel* UserManagement::getProjectUsers(int projectId) {

	pqxx::transaction transaction(*connection->getDataBase());

	pqxx::result result = transaction.exec_prepared("getProjectInvoledUsers", projectId);

	return convertToModel(result);


}

QStandardItemModel* UserManagement::getUsersByRole(UserManagement::Role role) {

	pqxx::transaction transaction(*connection->getDataBase());

	pqxx::result result = transaction.exec_prepared("getUsersByRole", static_cast<int>(role));

	return convertToModel(result);


}
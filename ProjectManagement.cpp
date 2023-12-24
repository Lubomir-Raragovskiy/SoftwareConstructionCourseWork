#include "ProjectManagement.h"
#include <QMessageBox>




ProjectManagement::ProjectManagement(DataBaseConnection* connection) : connection(connection)
{

    connection->getDataBase()->prepare("getProjectsList", "SELECT project_name FROM \"Projects\";");
    connection->getDataBase()->prepare("getProjectByName", "SELECT project_id, description, start_date, end_date, current_version, project_manager FROM \"Projects\" WHERE project_name = $1;");
    connection->getDataBase()->prepare("getTaskByName", "SELECT task_id, project_id, description, deadline, assignee_id, active FROM \"Tasks\" WHERE task_name = $1;");
    connection->getDataBase()->prepare("getProjectId", "SELECT project_id FROM \"Projects\" WHERE project_name = $1;");
    connection->getDataBase()->prepare("getTaskId", "SELECT task_id FROM \"Tasks\" WHERE task_name = $1;");
    connection->getDataBase()->prepare("getProjectName", "SELECT project_name FROM \"Projects\" WHERE project_id = $1;");
    connection->getDataBase()->prepare("getTasksList", "SELECT task_name, active  FROM \"Tasks\" WHERE project_id = $1;");
    connection->getDataBase()->prepare("addProject", "INSERT INTO \"Projects\"(project_name) VALUES($1);");
    connection->getDataBase()->prepare("removeProject", "DELETE FROM \"Projects\" WHERE project_id = $1;");
    connection->getDataBase()->prepare("removeTask", "DELETE FROM \"Tasks\" WHERE task_id = $1;");
    connection->getDataBase()->prepare("addTask", "INSERT INTO \"Tasks\"(task_name, project_id) VALUES($1, $2);");
    connection->getDataBase()->prepare("changeTaskStatus", "UPDATE \"Tasks\" SET active = $1 WHERE task_id = $2;");
    connection->getDataBase()->prepare("updateTask", "UPDATE \"Tasks\"\
        SET task_name = COALESCE($2, task_name), deadline = CAST(COALESCE($3  , deadline) AS DATE), description = COALESCE($4, description), \
        assignee_id = CAST(COALESCE($5, assignee_id) AS int), project_id = CAST(COALESCE($6, project_id) AS int)\
        WHERE task_id = $1");
   

    connection->getDataBase()->prepare("updateProject", "UPDATE \"Projects\"\
        SET project_name = COALESCE($2, project_name), description = COALESCE($3, description), \
        current_version = COALESCE($4, current_version), project_manager = CAST(COALESCE($5, project_id) AS int)\
        WHERE project_id = $1");
   

}



QStandardItemModel* ProjectManagement::getProjectsList() {


    
    pqxx::transaction transaction(*connection->getDataBase());

    pqxx::result result = transaction.exec_prepared("getProjectsList");

    return convertToModel(result);

}

QStandardItemModel* ProjectManagement::getProjectTasks(int projectId)
{
    pqxx::transaction transaction(*connection->getDataBase());

    pqxx::result result = transaction.exec_prepared("getTasksList", projectId);

    return convertToModel(result);
}
 
Project ProjectManagement::getProjectByName(QString projectName) {

    pqxx::transaction transaction(*connection->getDataBase());

    pqxx::result result = transaction.exec_prepared("getProjectByName", projectName.toStdString());

    return Project(result[0][0].as<int>(), projectName, 
        result[0][1].is_null() ? "" : result[0][1].as<std::string>().c_str(),
        result[0][2].is_null() ? "" : result[0][2].as<std::string>().c_str(),
        result[0][3].is_null() ? "" : result[0][3].as<std::string>().c_str(),
        result[0][4].is_null() ? "" : result[0][4].as<std::string>().c_str(),
        result[0][5].is_null() ? -1 : result[0][5].as<int>()) ;

}

Task ProjectManagement::getTaskByName(QString taskName) {

    pqxx::transaction transaction(*connection->getDataBase());

    pqxx::result result = transaction.exec_prepared("getTaskByName", taskName.toStdString());

    return Task(result[0][0].as<int>(),
        result[0][1].is_null() ? -1 : result[0][1].as<int>(),
        taskName,
        result[0][2].is_null() ? "" : result[0][2].as<std::string>().c_str(),
        result[0][3].is_null() ? "" : result[0][3].as<std::string>().c_str(),
        result[0][4].is_null() ? -1 : result[0][4].as<int>(),
        result[0][5].is_null() ? 1 : result[0][5].as<bool>());

}


QString ProjectManagement::getProjectName(int projectId) {


    pqxx::transaction transaction(*connection->getDataBase());

    pqxx::result result = transaction.exec_prepared("getProjectName", projectId);

    return result[0][0].is_null() ? "" : result[0][0].as<std::string>().c_str();


}

int ProjectManagement::getProjectId(QString projectName) {


    pqxx::transaction transaction(*connection->getDataBase());

    pqxx::result result = transaction.exec_prepared("getProjectId", projectName.toStdString());

    transaction.commit();

    return result[0][0].is_null() ? -1 : result[0][0].as<int>();


}

int ProjectManagement::getTaskId(QString taskName) {


    pqxx::transaction transaction(*connection->getDataBase());

    pqxx::result result = transaction.exec_prepared("getTaskId", taskName.toStdString());

    return result[0][0].is_null() ? -1 : result[0][0].as<int>();


}

void ProjectManagement::addTask(QString taskName, QString projectName) {

    int projectId = getProjectId(projectName);

    pqxx::transaction transaction(*connection->getDataBase());

    transaction.exec_prepared("addTask", taskName.toStdString(), projectId);
    transaction.commit();
}

void ProjectManagement::changeTaskStatus(QString taskName, bool status) {


    

    int taskId = getTaskId(taskName);


    pqxx::transaction transaction(*connection->getDataBase());

    transaction.exec_prepared("changeTaskStatus", status, taskId);
    transaction.commit();

}

void ProjectManagement::removeTask(QString taskName) {

    int tasktId = getTaskId(taskName);


    pqxx::transaction transaction(*connection->getDataBase());

    transaction.exec_prepared("removeTask", tasktId);
    transaction.commit();

}


void ProjectManagement::addProject(QString projectName) {

    pqxx::transaction transaction(*connection->getDataBase());

    transaction.exec_prepared("addProject", projectName.toStdString());
    transaction.commit();
}

void ProjectManagement::removeProject(QString projectName) {

        int projectId = getProjectId(projectName);


        pqxx::transaction transaction(*connection->getDataBase());

        transaction.exec_prepared("removeProject", projectId);
        transaction.commit();

}



void ProjectManagement::updateTask(int taskId, QString taskName, QString deadline, QString description, int userId, int projectId) {

    pqxx::transaction transaction(*connection->getDataBase());

    transaction.exec_prepared("updateTask", taskId, taskName.toStdString(), deadline.toStdString(), description.toStdString(), userId, projectId);
    transaction.commit();
}




void ProjectManagement::updateProject(int projectId, QString projectName, QString description, QString version, int projectManager) {

    pqxx::transaction transaction(*connection->getDataBase());

    transaction.exec_prepared("updateProject", projectId, projectName.toStdString(), description.toStdString(), version.toStdString(),  projectManager);
    transaction.commit();
}



Project::Project(int project_id, QString project_name, QString description, QString start_time, QString end_time, QString current_version, int project_manager) :
    project_id(project_id), project_name(project_name), description(description), start_time(start_time),
    end_time(end_time), current_version(current_version), project_manager(project_manager)
{}

Task::Task(int task_id, int project_id, QString task_name, QString description, QString deadline, int assignee_id, bool active) :
    task_id(task_id), project_id(project_id), task_name(task_name), description(description), deadline(deadline), 
    assignee_id(assignee_id), active(active)
{}

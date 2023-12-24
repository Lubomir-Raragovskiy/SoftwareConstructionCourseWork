#pragma once

#include <Database/DataBaseConnection.h>



class UserManagement
{
	DataBaseConnection* connection;

public:
	UserManagement(DataBaseConnection* connection);

	enum class Role {
		Admin = 1,
		Client,
		ProjectManager,
		TechSpecialist

	};



	QString getUserName(int userId);

	int getUserId(QString userName);

	QStandardItemModel* getProjectUsers(int projectId);

	QStandardItemModel* getUsersByRole(Role role);

	

};


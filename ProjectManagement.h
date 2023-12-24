#pragma once
#include <Database/DataBaseConnection.h>
#include <QStandardItemModel>
#include <QString>



struct Project {

	int project_id;
	QString project_name;
	QString description;
	QString start_time;
	QString end_time;
	QString current_version;
	int project_manager;

	Project(int project_id, QString project_name, QString description, QString start_time, QString end_time, QString current_version, int project_manager);

};


struct Task {

	int task_id;
	int project_id;
	QString task_name;
	QString description;
	QString deadline;
	int assignee_id;
	bool active;
	

	Task(int task_id, int project_id, QString task_name, QString description, QString deadline, int assignee_id, bool active);

};



class ProjectManagement
{
	DataBaseConnection* connection;
	

	

public:
	
	ProjectManagement(DataBaseConnection* connection);
	QStandardItemModel* getProjectsList();
	QStandardItemModel* getProjectTasks(int projectId);
	Project getProjectByName(QString projectName);

	Task getTaskByName(QString taskName);

	QString getProjectName(int projectId);

	int getProjectId(QString projectName);

	int getTaskId(QString taskName);

	void addTask(QString taskName, QString projectName);

	void changeTaskStatus(QString taskName, bool status);

	void removeTask(QString taskName);

	void addProject(QString projectName);

	void removeProject(QString projectName);

	void updateTask(int taskId, QString taskName, QString deadline, QString description, int userId, int projectId);

	void updateProject(int projectId, QString projectName, QString description, QString version, int projectManager);


	
};


#include "mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    admission(connection->connectDataBase()),
    projectManagement(connection->connectDataBase()),
    userManagement(connection->connectDataBase())
{
    ui->setupUi(this);
    

    onGoToEntry();

    QObject::connect(ui->entry->rootObject(), SIGNAL(logIn(QString, QString)), this, SLOT(onLogIn(QString, QString)));
    QObject::connect(ui->entry->rootObject(), SIGNAL(signUp(QString, QString)), this, SLOT(onSignUp(QString, QString)));
    QObject::connect(ui->projects->rootObject(), SIGNAL(currentProjectChanged(QString)), this, SLOT(onCurrentProjectChanged(QString)));
    QObject::connect(ui->projects->rootObject(), SIGNAL(goToProject(QString)), this, SLOT(onGoToProject(QString)));
    QObject::connect(ui->projects->rootObject(), SIGNAL(goToTask(QString)), this, SLOT(onGoToTask(QString)));
    QObject::connect(ui->projects->rootObject(), SIGNAL(addProject(QString)), this, SLOT(onAddProject(QString)));
    QObject::connect(ui->projects->rootObject(), SIGNAL(removeProject(QString)), this, SLOT(onRemoveProject(QString)));
    QObject::connect(ui->project->rootObject(), SIGNAL(addTask(QString, QString)), this, SLOT(onAddTask(QString, QString)));
    QObject::connect(ui->project->rootObject(), SIGNAL(completeTask(QString, QString)), this, SLOT(onCompleteTask(QString, QString)));
    QObject::connect(ui->project->rootObject(), SIGNAL(restoreTask(QString, QString)), this, SLOT(onRestoreTask(QString, QString)));
    QObject::connect(ui->project->rootObject(), SIGNAL(removeTask(QString, QString)), this, SLOT(onRemoveTask(QString, QString)));
    QObject::connect(ui->task->rootObject(), SIGNAL(saveTask(int, QString, QString, QString, QString, QString)), this, SLOT(onSaveTask(int, QString, QString, QString, QString, QString)));
    QObject::connect(ui->project->rootObject(), SIGNAL(saveProject(int, QString, QString, QString, QString)), this, SLOT(onSaveProject(int, QString, QString, QString, QString)));
    QObject::connect(ui->task->rootObject(), SIGNAL(back()), this, SLOT(onGoToProjects()));
    QObject::connect(ui->project->rootObject(), SIGNAL(back()), this, SLOT(onGoToProjects()));
    QObject::connect(ui->projects->rootObject(), SIGNAL(back()), this, SLOT(onGoToEntry()));
    
   
   
    

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onGoToEntry()
{
    
    ui->currentPage->setCurrentWidget(ui->entryPage);
}


void MainWindow::onLogIn(QString login, QString password)
{
    currentUser = admission.logIn(login, password);
    if (currentUser != -1) {
        onGoToProjects();
    }
    
}

void MainWindow::onSignUp(QString login, QString password)
{
    admission.signUp(login, password);

    QMessageBox::information(this, "Account created", "You will automatically log in");

    onLogIn(login, password);
}

void MainWindow::onCurrentProjectChanged(QString projectName) {

        Project project = projectManagement.getProjectByName(projectName);

        ui->projects->rootContext()->setContextProperty("_description", project.description);
        ui->projects->rootContext()->setContextProperty("_tasks", projectManagement.getProjectTasks(project.project_id));
}

void MainWindow::onGoToProject(QString projectName) {

    ui->currentPage->setCurrentWidget(ui->projectPage);
    Project project = projectManagement.getProjectByName(projectName);
    ui->project->rootContext()->setContextProperty("_projectId", project.project_id);
    ui->project->rootContext()->setContextProperty("_projectName", project.project_name);
    ui->project->rootContext()->setContextProperty("_currentVersion", project.current_version);
    ui->project->rootContext()->setContextProperty("_description", project.description);
    ui->project->rootContext()->setContextProperty("_projectManager", userManagement.getUsersByRole(UserManagement::Role::ProjectManager));
    ui->project->rootContext()->setContextProperty("_currentPM", userManagement.getUserName(project.project_manager));
    ui->project->rootContext()->setContextProperty("_users", userManagement.getProjectUsers(project.project_id));
    ui->project->rootContext()->setContextProperty("_activeTasks", filterModel(projectManagement.getProjectTasks(project.project_id), 1, "t"));
    ui->project->rootContext()->setContextProperty("_completedTask", filterModel(projectManagement.getProjectTasks(project.project_id), 1, "f"));

    
}

void MainWindow::onGoToProjects() {

    ui->currentPage->setCurrentWidget(ui->projectsPage);
    ui->projects->rootContext()->setContextProperty("_projects", projectManagement.getProjectsList());

}


void MainWindow::onGoToTask(QString taskName) {

    ui->currentPage->setCurrentWidget(ui->taskPage);

    Task task = projectManagement.getTaskByName(taskName);
    ui->task->rootContext()->setContextProperty("_taskId", task.task_id);
    ui->task->rootContext()->setContextProperty("_taskName", taskName);
    ui->task->rootContext()->setContextProperty("_deadline", task.deadline);
    ui->task->rootContext()->setContextProperty("_description", task.description);
    ui->task->rootContext()->setContextProperty("_currentProject", projectManagement.getProjectName(task.project_id));
    ui->task->rootContext()->setContextProperty("_currentUser", userManagement.getUserName(task.assignee_id));
    ui->task->rootContext()->setContextProperty("_project", projectManagement.getProjectsList());
    ui->task->rootContext()->setContextProperty("_user", userManagement.getUsersByRole(UserManagement::Role::TechSpecialist));

}

void MainWindow::onAddProject(QString projectName) {


    projectManagement.addProject(projectName);
    ui->projects->rootContext()->setContextProperty("_projects", projectManagement.getProjectsList());

}

void MainWindow::onRemoveProject(QString projectName) {

    projectManagement.removeProject(projectName);
    ui->projects->rootContext()->setContextProperty("_projects", projectManagement.getProjectsList());


}

void MainWindow::onAddTask(QString taskName, QString projectName) {


    projectManagement.addTask(taskName, projectName);
    onGoToProject(projectName);

}

void MainWindow::onCompleteTask(QString taskName, QString projectName) {


    projectManagement.changeTaskStatus(taskName, false);
    onGoToProject(projectName);


}

void MainWindow::onRestoreTask(QString taskName, QString projectName) {

    projectManagement.changeTaskStatus(taskName, true);
    onGoToProject(projectName);


}

void MainWindow::onRemoveTask(QString taskName, QString projectName) {


    projectManagement.removeTask(taskName);
    onGoToProject(projectName);


}


void MainWindow::onSaveTask(int taskId, QString taskName, QString deadline, QString description, QString userName, QString projectName) {


        projectManagement.updateTask(taskId, taskName, deadline, description, userManagement.getUserId(userName), projectManagement.getProjectId(projectName));

    onGoToTask(taskName);

}

void MainWindow::onSaveProject(int projectId, QString projectName,  QString description, QString version, QString projectManager) {


    projectManagement.updateProject(projectId, projectName, description, version, userManagement.getUserId(projectManager));

    onGoToProject(projectName);

}

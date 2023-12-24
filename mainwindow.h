#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuickWidget>
#include <QQmlContext>
#include <QQuickItem>
#include <QSortFilterProxyModel>
#include "Database/DataBaseConnection.h"
#include "UserAdmission.h"
#include "ProjectManagement.h"
#include "ui_mainwindow.h"
#include "UserManagement.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   
   

    
public slots:
    void onLogIn(QString login, QString password);
    void onSignUp(QString login, QString password);

    void onGoToProjects();

    void onCurrentProjectChanged(QString projectName);

    void onGoToProject(QString projectName);

    void onGoToTask(QString projectName);

    void onAddProject(QString projectName);

    void onRemoveProject(QString projectName);
    void onSaveTask(int taskId, QString taskName, QString deadline, QString description, QString project, QString projectManager);
    void onAddTask(QString taskName, QString projectName);
    void onCompleteTask(QString taskName, QString projectName);
    void onRestoreTask(QString taskName, QString projectName);
    void onRemoveTask(QString taskName, QString projectName);
    void onSaveProject(int projectId, QString projecName, QString description, QString version, QString projectManager);
    void onGoToEntry();

private:
    Ui::MainWindow *ui;
    DataBaseConnection* connection;
    UserAdmission admission;
    ProjectManagement projectManagement;
    UserManagement userManagement;
    int currentUser;
 
};
#endif // MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *currentPage;
    QWidget *entryPage;
    QHBoxLayout *horizontalLayout_2;
    QQuickWidget *entry;
    QWidget *projectsPage;
    QHBoxLayout *horizontalLayout_3;
    QQuickWidget *projects;
    QWidget *projectPage;
    QHBoxLayout *horizontalLayout_4;
    QQuickWidget *project;
    QWidget *tasksPage;
    QHBoxLayout *horizontalLayout_6;
    QQuickWidget *tasks;
    QWidget *taskPage;
    QHBoxLayout *horizontalLayout_5;
    QQuickWidget *task;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1069, 721);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color : rgb(5, 5, 5)\n"
"}\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        currentPage = new QStackedWidget(centralwidget);
        currentPage->setObjectName("currentPage");
        currentPage->setLineWidth(0);
        entryPage = new QWidget();
        entryPage->setObjectName("entryPage");
        horizontalLayout_2 = new QHBoxLayout(entryPage);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        entry = new QQuickWidget(entryPage);
        entry->setObjectName("entry");
        entry->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(entry->sizePolicy().hasHeightForWidth());
        entry->setSizePolicy(sizePolicy);
        entry->setResizeMode(QQuickWidget::SizeRootObjectToView);
        entry->setSource(QUrl(QString::fromUtf8("file:///D:/CoursuWork/GUI/EntryPage.qml")));

        horizontalLayout_2->addWidget(entry);

        currentPage->addWidget(entryPage);
        projectsPage = new QWidget();
        projectsPage->setObjectName("projectsPage");
        horizontalLayout_3 = new QHBoxLayout(projectsPage);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        projects = new QQuickWidget(projectsPage);
        projects->setObjectName("projects");
        projects->setResizeMode(QQuickWidget::SizeRootObjectToView);
        projects->setSource(QUrl(QString::fromUtf8("file:///D:/CoursuWork/GUI/Projects.qml")));

        horizontalLayout_3->addWidget(projects);

        currentPage->addWidget(projectsPage);
        projectPage = new QWidget();
        projectPage->setObjectName("projectPage");
        horizontalLayout_4 = new QHBoxLayout(projectPage);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        project = new QQuickWidget(projectPage);
        project->setObjectName("project");
        project->setResizeMode(QQuickWidget::SizeRootObjectToView);
        project->setSource(QUrl(QString::fromUtf8("file:///D:/CoursuWork/GUI/Project.qml")));

        horizontalLayout_4->addWidget(project);

        currentPage->addWidget(projectPage);
        tasksPage = new QWidget();
        tasksPage->setObjectName("tasksPage");
        horizontalLayout_6 = new QHBoxLayout(tasksPage);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        tasks = new QQuickWidget(tasksPage);
        tasks->setObjectName("tasks");
        tasks->setResizeMode(QQuickWidget::SizeRootObjectToView);
        tasks->setSource(QUrl(QString::fromUtf8("file:///D:/CoursuWork/GUI/Tasks.qml")));

        horizontalLayout_6->addWidget(tasks);

        currentPage->addWidget(tasksPage);
        taskPage = new QWidget();
        taskPage->setObjectName("taskPage");
        horizontalLayout_5 = new QHBoxLayout(taskPage);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        task = new QQuickWidget(taskPage);
        task->setObjectName("task");
        task->setResizeMode(QQuickWidget::SizeRootObjectToView);
        task->setSource(QUrl(QString::fromUtf8("file:///D:/CoursuWork/GUI/Task.qml")));

        horizontalLayout_5->addWidget(task);

        currentPage->addWidget(taskPage);

        horizontalLayout->addWidget(currentPage);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1069, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        currentPage->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

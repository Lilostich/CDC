#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <QString>
#include <QFile>
#include <QDir>

const QString testPath = "var/CDC/Tests";
const QString listPath = "./CDC/Lists";
const QString projectsPath = "./CDC/Projects";
const QString taskPath = "./Tasks";
const QString taskDirName = "Tasks";

class file_manager
{
public:
    file_manager();

    static QString file_name(QString name){return name + ".meta";}

    static bool have_test(QString name);
    static bool have_list(QString name);
    static bool have_project(QString name);
    static bool have_run(QString name);
    static bool have_task(QString name);

    static void create_test(QString name);
    static void create_list(QString name);
    static void create_project(QString name);
    static void create_run(QString name,QString project);
    static void create_task(QString name);

    static void delete_test(QString name);

    static void delete_list(QString name);
    //static void delete_project(QString name);
    //static void delete_run(QString name,QString project);
    //static void delete_task(QString name);

    static QJsonObject read_test(QString name);
    static QJsonObject read_list(QString name);
    static QJsonObject read_run(QString name);
    static QJsonObject read_task(QString name);
    static QJsonObject read_task_from_project(QString task_name,QString project_name);

    static void write_test(QString name     ,QJsonObject & data);
    static void write_list(QString name     ,QJsonObject & data);
    static void write_run(QString name      ,QJsonObject & data);
    static void write_task(QString name     ,QJsonObject & data);

    static QStringList get_all_tests();
    static QStringList get_all_lists();
    static QStringList get_all_projects();
    static QStringList get_all_tasks();
    static QStringList get_all_runs();

    static QStringList get_tasks(QString project_name);
    static QStringList get_runs(QString project_name);

    static QString get_project_of_run(QString run_name);


};

#endif // FILE_MANAGER_H

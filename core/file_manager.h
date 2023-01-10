#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <QString>
#include <QFile>
#include <QDir>

const QString testPath = "/var/lib/CDC/Tests";
const QString listPath = "/var/lib/CDC/Lists";
const QString runPath = "/var/lib/CDC/Run";
const QString reportPath = "/var/lib/CDC/Reports";
const QString projectsPath = "/var/lib/CDC/Projects";
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
    static void create_run(QString name);
    static void create_task(QString name);

    static void delete_test(QString name);

    static void delete_list(QString name);
    //static void delete_project(QString name);
    static void delete_run(QString name,QString project);
    static void delete_run(QString name);
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

    static QJsonObject exec_save_report_one(QString py_script, QString name_test);
    static QJsonObject exec_save_report_some_list(QStringList py_scripts, QStringList names_test, QString name_list);

    static void exec_script(QString py_script);
    static void save_report(QString filname, QJsonObject obj);

    static QString actual_time();
};

#endif // FILE_MANAGER_H

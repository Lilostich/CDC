#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <QString>
#include <QFile>
#include <QDir>

const QString testPath = "./CDC/Tests";
const QString listPath = "./CDC/Lists";
const QString projectsPath = "./CDC/Projects";
const QString taskPath = "./Tasks";


class file_manager
{
public:
    file_manager();

    static bool have_test(QString name);
    static bool have_list(QString name);
    static bool have_project(QString name);
    static bool have_run(QString name);
    static bool have_task(QString name);

    static QByteArray read_test(QString name);
    static QByteArray read_list(QString name);
    static QByteArray read_run(QString name);
    static QByteArray read_task(QString name);

    static void write_test(QString name     ,QByteArray && data);
    static void write_list(QString name     ,QByteArray && data);
    static void write_run(QString name      ,QByteArray && data);
    static void write_task(QString name     ,QByteArray && data);

    static QStringList get_all_tests();
    static QStringList get_all_lists();
    static QStringList get_all_projects();
    static QStringList get_all_tasks();
    static QStringList get_all_runs();

    static QStringList get_tasks(QString project_name);
    static QStringList get_runs(QString project_name);


};

#endif // FILE_MANAGER_H

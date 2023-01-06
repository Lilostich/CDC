#include "file_manager.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <stdlib.h>
#include <cstdlib>

file_manager::file_manager()
{

}

bool file_manager::have_test(QString testName)
{

    return QFile(testPath + "/" + file_name(testName)).exists();
}

bool file_manager::have_list(QString name)
{
    return QFile(listPath + "/" + file_name(name)).exists();
}

bool file_manager::have_project(QString name)
{
    return QDir(projectsPath + "/" + name).exists();
}

bool file_manager::have_run(QString name)
{
    QDir dir(projectsPath);
    QStringList projects = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    for(int i = 0; i < projects.size(); i++){
        if(QFile(projectsPath + "/" + projects[i] + "/" + taskPath + "/" +file_name(name)).exists())
            return true;
    }
    return false;
}

bool file_manager::have_task(QString name)
{
    return have_run(name);
}

void file_manager::create_test(QString name)
{
    system((QString("touch ") + "./" + testPath + "/" + file_name(name)).toStdString().c_str());
}

void file_manager::create_list(QString name)
{
    system((QString("touch ") + "./" + listPath + "/" + file_name(name)).toStdString().c_str());
}

void file_manager::create_project(QString name)
{
    QDir dir(projectsPath);
    dir.mkdir(name);
    dir.cd(name);
    dir.mkdir(taskDirName);
}

void file_manager::delete_test(QString name)
{
    QFile(testPath + "/" + file_name(name)).remove();
}

void file_manager::delete_list(QString name)
{
    QFile(listPath + "/" + file_name(name)).remove();
}

QJsonObject file_manager::read_test(QString name)
{
    QFile file(testPath+ "/" + file_name(name));
    if (file.exists()){
        file.open(QFile::ReadOnly);
        QJsonDocument doc {QJsonDocument::fromJson(file.readAll())};
        file.close();
        return doc.object();
    } else
        qFatal(QString("file of test is not exist %1").arg(name).toStdString().c_str());
}

QJsonObject file_manager::read_list(QString name)
{
    QFile file(listPath + "/" + file_name(name));
    if (file.exists()){
        file.open(QFile::ReadOnly);
        QJsonDocument doc {QJsonDocument::fromJson(file.readAll())};
        file.close();
        return doc.object();
    } else
        qFatal(QString("file of list is not exist %1").arg(name).toStdString().c_str());

}

QJsonObject file_manager::read_run(QString name)
{
    QDir dir(projectsPath);
    QStringList projects = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    QString run_full_name = "";
    for(int i = 0; i < projects.size(); i++){
        QDir dir(projectsPath + "/" + projects[i] + "/" + taskPath);
        QStringList tasks = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        for(int j = 0; j < tasks.size(); j++){
            if(tasks[i] == name){
                run_full_name = projectsPath + "/" + projects[i] + "/" + taskPath + "/" + tasks[i];
                break;
            }
        }
        if (run_full_name != "")
            break;
    }
    QFile file(run_full_name);
    file.open(QFile::ReadOnly);
    QJsonDocument doc {QJsonDocument::fromJson(file.readAll())};
    file.close();
    return doc.object();
}

QJsonObject file_manager::read_task(QString name)
{
    return read_run(name);
}

void file_manager::write_test(QString name, QJsonObject &data)
{
    QFile file(testPath+ "/" + file_name(name));
//    if (!file.exists()){
//        file.open(QFile::WriteOnly | QFile::NewOnly);
//        qDebug(QString("create new file %1").arg(file_name(name)).toStdString().c_str());
//    } else {
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    if (!file.isOpen()){
        qDebug("file not open");
        file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::NewOnly);
        if (!file.isOpen())
            qDebug("file not open again");
    }

    QJsonDocument doc;
    doc.setObject(data);
    file.write(doc.toJson());
    file.close();
}

void file_manager::write_list(QString name, QJsonObject &data)
{
    QFile file(listPath+ "/" + file_name(name));
    if (file.exists()){
        qFatal(QString("file for write not exist %1").arg(file_name(name)).toStdString().c_str());
        return;
    }
    file.open(QFile::WriteOnly);
    QJsonDocument doc;
    doc.setObject(data);
    file.write(doc.toJson());
    file.close();
}

void file_manager::write_run(QString name, QJsonObject &data)
{
    // TODO переписать под хедер
    QDir dir(projectsPath);
    QStringList projects = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    QString run_full_name = "";
    for(int i = 0; i < projects.size(); i++){
        QDir dir(projectsPath + "/" + projects[i] + "/" + taskPath);
        QStringList tasks = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        for(int j = 0; j < tasks.size(); j++){
            if(tasks[i] == name){
                run_full_name = projectsPath + "/" + projects[i] + "/" + taskPath + "/" + tasks[i];
                break;
            }
        }
        if (run_full_name != "")
            break;
    }
    QFile file(run_full_name);
    file.open(QFile::WriteOnly);
    QJsonDocument doc;
    doc.setObject(data);
    file.write(doc.toJson());
}

void file_manager::write_task(QString name, QJsonObject &data)
{
    write_run(name,data);
}

QStringList file_manager::get_all_tests()
{
    QDir dir(testPath);
    auto allFiles = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
    QStringList files;
    for (auto &info : allFiles){
        if (info.suffix() == "meta"){
            files.push_back(info.baseName());

        }
    }
    qDebug("TESTING NOW");
    qDebug(files.at(0).toStdString().c_str());
    return files;
}

QStringList file_manager::get_all_lists()
{
    QDir dir(listPath);
    auto allFiles = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
    QStringList files;
    for (auto &info : allFiles){
        if (info.suffix() == "meta"){
            files.push_back(info.baseName());

        }
    }
    qDebug(files.at(0).toStdString().c_str());
    return files;
}

QStringList file_manager::get_all_projects()
{
    QDir dir(projectsPath);
    return dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
}

QStringList file_manager::get_all_tasks()
{
    QDir dir(projectsPath);
    QStringList all_tasks;
    QStringList projects = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for(int i = 0; i < projects.size(); i++){
        QDir dir(projectsPath + "/" + projects[i] + "/" + taskPath);
        QStringList tasks = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        for(int j = 0; j < tasks.size(); j++){
            all_tasks.push_back(projectsPath + "/" + projects[i] + "/" + taskPath + "/" + tasks[j]);
        }
    }
    return all_tasks;
}

QStringList file_manager::get_all_runs()
{
    return get_all_tasks();
}

QStringList file_manager::get_tasks(QString project_name)
{
    if (have_project(project_name)){
        return QDir(projectsPath + "/" + project_name + "/" + taskPath).entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    }
    else
        qFatal("project not exists");
    return QStringList();
}

QStringList file_manager::get_runs(QString project_name)
{
    return get_tasks(project_name);
}

QString file_manager::get_project_of_run(QString run_name)
{
    QStringList projects = get_all_projects();
    for ( auto proj_name : projects){
        if (get_runs(proj_name).contains(run_name)){
            return proj_name;
        }
    }
    qDebug("No run with this name");
}



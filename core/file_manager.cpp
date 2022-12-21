#include "file_manager.h"

file_manager::file_manager()
{

}

bool file_manager::have_test(QString testName)
{
    QDir dir(testPath);
    QStringList list = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);

    for(int i = 0; i < list.size(); i++){
        if(list[i] == testName)
            return true;
    }
    return false;
}

bool file_manager::have_list(QString name)
{
    QDir dir(listPath);
    QStringList list = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);

    for(int i = 0; i < list.size(); i++){
        if(list[i] == name)
            return true;
    }
    return false;
}

bool file_manager::have_project(QString name)
{
    QDir dir(projectsPath);
    QStringList list = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    for(int i = 0; i < list.size(); i++){
        if(list[i] == name)
            return true;
    }
    return false;
}

bool file_manager::have_run(QString name)
{
    QDir dir(projectsPath);
    QStringList projects = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    for(int i = 0; i < projects.size(); i++){
        QDir dir(projectsPath + "/" + projects[i] + "/" + taskPath);
        QStringList tasks = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        for(int j = 0; j < tasks.size(); j++){
            if(tasks[i] == name)
                return true;
        }

    }
    return false;
}

bool file_manager::have_task(QString name)
{
    QDir dir(projectsPath);
    QStringList projects = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    for(int i = 0; i < projects.size(); i++){
        QDir dir(projectsPath + "/" + projects[i] + "/" + taskPath);
        QStringList tasks = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        for(int j = 0; j < tasks.size(); j++){
            if(tasks[i] == name)
                return true;
        }

    }
    return false;
}

QByteArray file_manager::read_test(QString name)
{
    QDir dir(testPath);
    QStringList list = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
    int i;
    for(i = 0; i < list.size(); i++){
        if(list[i] == name)
            break;
    }
    QFile file(testPath+ "/" + list[i]);
    file.open(QFile::ReadOnly);
    return file.readAll();
}

QByteArray file_manager::read_list(QString name)
{
    QDir dir(listPath);
    QStringList list = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);

    int i;
    for(i = 0; i < list.size(); i++){
        if(list[i] == name)
            break;
    }
    QFile file(listPath+ "/" + list[i]);
    file.open(QFile::ReadOnly);
    return file.readAll();

}

QByteArray file_manager::read_run(QString name)
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
    return file.readAll();
}

QByteArray file_manager::read_task(QString name)
{
    return read_run(name);
}

void file_manager::write_test(QString name, QByteArray &&data)
{
    QDir dir(testPath);
    QStringList list = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
    int i;
    for(i = 0; i < list.size(); i++){
        if(list[i] == name)
            break;
    }
    QFile file(testPath+ "/" + list[i]);
    file.open(QFile::WriteOnly);
    file.write(data);
}

void file_manager::write_list(QString name, QByteArray &&data)
{
    QDir dir(listPath);
    QStringList list = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);

    int i;
    for(i = 0; i < list.size(); i++){
        if(list[i] == name)
            break;
    }
    QFile file(listPath+ "/" + list[i]);
    file.open(QFile::WriteOnly);
    file.write(data);
}

void file_manager::write_run(QString name, QByteArray &&data)
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
    file.open(QFile::WriteOnly);
    file.write(data);
}

void file_manager::write_task(QString name, QByteArray &&data)
{
    write_run(name,std::move(data));
}

QStringList file_manager::get_all_tests()
{
    QDir dir(testPath);
    return dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
}

QStringList file_manager::get_all_lists()
{
    QDir dir(listPath);
    return dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
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
    return QStringList();
}

QStringList file_manager::get_runs(QString project_name)
{
    return get_tasks(project_name);
}



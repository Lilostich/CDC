#include "test_omnimanager.h"
#include <QDir>
#include "Options.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

std::string getFileName(std::string name){
    return name + ".meta";
}

void deleteFile(std::string fullFileName){
    system(QString("rm %1").arg(fullFileName.c_str()).toStdString().c_str());
}

Test_omnimanager::Test_omnimanager()
{

}

QByteArray Test_omnimanager::open_read_list_file(std::string listFile)
{
    QFile metaFile((LIST_PATH + getFileName(listFile)).c_str());
    return metaFile.readAll();
}

QByteArray Test_omnimanager::open_read_test_file(std::string testFile)
{
    QFile metaFile((TEST_PATH + getFileName(testFile)).c_str());
    return metaFile.readAll();
}

QByteArray Test_omnimanager::open_read_run_file(std::string runFile)
{
    // TODO поиск мета файла рана и остальное как в тесте/наборе
    return QByteArray();
}

void Test_omnimanager::write_list_file(std::string listFile, QByteArray &&data)
{
    QFile metaFile((LIST_PATH + getFileName(listFile)).c_str());
    metaFile.write(data);
}

void Test_omnimanager::write_test_file(std::string testFile, QByteArray &&data)
{
    QFile metaFile((TEST_PATH + getFileName(testFile)).c_str());
    metaFile.write(data);
}

void Test_omnimanager::write_test_run(std::string runFile, QByteArray &&data)
{
    // TODO поиск мета файла рана
}

// открыть / редактировать / записать
void Test_omnimanager::add_test_to_list(std::string test_name, std::string list_name)
{
    QByteArray metaList = open_read_list_file(list_name);

    QJsonDocument metaListDoc(QJsonDocument::fromJson(metaList));
    QJsonObject obj(metaListDoc.object());
    QJsonValue v;
    QVariant var;
    v.toString().toStdString();
    QJsonArray tests = obj.find("tests").value().toArray();
    for (int i = 0; i < tests.size(); i++){
        if (tests[i].toString().toStdString() == test_name)
            return;
    }
    tests.append(QString(test_name.c_str()));
    obj["tests"] = tests;

    metaListDoc.setObject(obj);

    write_list_file(getFileName(list_name),metaListDoc.toJson());
}

// открыть / редактировать / записать
void Test_omnimanager::add_test_to_run(std::string test_name, std::string run_name)
{
    QByteArray metaRun = open_read_run_file(run_name);

    QJsonDocument metaRunDoc(QJsonDocument::fromJson(metaRun));
    QJsonObject obj(metaRunDoc.object());

    QJsonArray tests = obj.find("tests").value().toArray();
    for (int i = 0; i < tests.size(); i++){
        if (tests[i].toString().toStdString() == test_name)
            return;
    }
    tests.append(QString(test_name.c_str()));
    obj["tests"] = tests;

    metaRunDoc.setObject(obj);

    write_test_run(getFileName(run_name),metaRunDoc.toJson());
}

// открыть / редактировать / записать
void Test_omnimanager::add_list_to_run(std::string list_name, std::string run_name)
{
    QByteArray metaRun = open_read_run_file(run_name);

    QJsonDocument metaRunDoc(QJsonDocument::fromJson(metaRun));
    QJsonObject obj(metaRunDoc.object());

    QJsonArray tests = obj.find("lists").value().toArray();
    for (int i = 0; i < tests.size(); i++){
        if (tests[i].toString().toStdString() == list_name)
            return;
    }
    tests.append(QString(list_name.c_str()));
    obj["lists"] = tests;

    metaRunDoc.setObject(obj);

    write_test_run(getFileName(run_name),metaRunDoc.toJson());
}

// удаление всего мета файла
void Test_omnimanager::delete_test(std::string test_name)
{
    QDir dir(tests_path.c_str());
    QString fileName(getFileName(test_name).c_str());
    deleteFile(QString(dir.path() + "/" + fileName).toStdString());
}

// открыть / редактировать / записать
void Test_omnimanager::delete_test_from_list(std::string test_name, std::string list_name)
{
    QByteArray metaTest = open_read_test_file(test_name);
    QByteArray metaList = open_read_list_file(list_name);

    QJsonDocument metaListDoc(QJsonDocument::fromJson(metaList));
    QJsonObject obj(metaListDoc.object());

    QJsonArray tests = obj.find("tests").value().toArray();
    for (int i = 0; i < tests.size(); i++){
        if (tests[i].toString().toStdString() == test_name){
            tests.removeAt(i);
            break;
        }
    }

    obj["tests"] = tests;

    metaListDoc.setObject(obj);

    write_list_file(getFileName(list_name),metaListDoc.toJson());

}

// открыть / редактировать / записать
void Test_omnimanager::delete_test_from_run(std::string test_name, std::string run_name)
{
    QByteArray metaRun = open_read_run_file(run_name);

    QJsonDocument metaRunDoc(QJsonDocument::fromJson(metaRun));
    QJsonObject obj(metaRunDoc.object());

    QJsonArray tests = obj.find("tests").value().toArray();
    for (int i = 0; i < tests.size(); i++){
        if (tests[i].toString().toStdString() == test_name){
            tests.removeAt(i);
            break;
        }
    }

    obj["tests"] = tests;

    metaRunDoc.setObject(obj);

    write_test_run(getFileName(run_name),metaRunDoc.toJson());
}

// удаление всего мета файла
void Test_omnimanager::delete_list(std::string list_name)
{
    QDir dir(tests_path.c_str());
    QString fileName(getFileName(list_name).c_str());
    deleteFile(QString(dir.path() + "/" + fileName).toStdString());
}

// открыть / редактировать / записать
void Test_omnimanager::delete_list_from_run(std::string list_name,std::string run_name)
{
    QByteArray metaRun = open_read_run_file(run_name);

    QJsonDocument metaRunDoc(QJsonDocument::fromJson(metaRun));
    QJsonObject obj(metaRunDoc.object());

    QJsonArray tests = obj.find("lists").value().toArray();
    for (int i = 0; i < tests.size(); i++){
        if (tests[i].toString().toStdString() == list_name){
            tests.removeAt(i);
            break;
        }
    }

    obj["lists"] = tests;

    metaRunDoc.setObject(obj);

    write_test_run(getFileName(run_name),metaRunDoc.toJson());
}

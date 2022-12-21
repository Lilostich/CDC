#include "test_manager.h"
#include <fstream>
#include <QString>
#include <ctime>
#include <QDir>

Test_manager::Test_manager()
{

}

// NOTE функция создает файл и записывает в него то что скрипт напишет в стандартный вывод
void Test_manager::run_auto_test(std::string test_name)
{
    QString command("python %1 >> %2");
    QString resultFileName("result_test_%1.txt");
    QString scriptFileName("%1.py");

    resultFileName = resultFileName.arg(QString(test_name.c_str()));
    scriptFileName = scriptFileName.arg(QString(test_name.c_str()));
    command = command.arg(scriptFileName).arg(resultFileName);

    system(command.toStdString().c_str());
}

void Test_manager::save_manual_test(std::string test_name,std::string data)
{
    //  >>> echo "<data>" > <test_name>
    system(QString("echo \"%1\" > %2").arg(data.c_str()).arg(test_name.c_str()).toStdString().c_str());
}

QStringList Test_manager::get_lists()
{
    std::string str(lists_path);
    QDir dir(str.c_str());
    QStringList files = dir.entryList();
    return files;
}

QStringList Test_manager::get_tests()
{
    std::string str(tests_path);
    QDir dir(str.c_str());
    QStringList files = dir.entryList();
    return files;
}

QStringList Test_manager::get_runs()
{
    std::string str(task_path);
    QDir dir(str.c_str());
    QStringList files = dir.entryList();
    return files;
}

void Test_manager::create_session(std::string session_name)
{
    std::ofstream fout;
    time_t dataTime;
    time(&dataTime);
    QString fileNameTemp("session %1.txt");
    fileNameTemp = fileNameTemp.arg(ctime(&dataTime));

    fout.open(fileNameTemp.toStdString().c_str());
    // TODO файл сессии открыт, провести необходимые действия при создании

    fout.close();
}

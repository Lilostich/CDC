#include "test_manager.h"
#include <fstream>
#include <QString>
#include <ctime>

Test_manager::Test_manager()
{

}

void Test_manager::create_session(std::string session_name)
{
    std::ofstream fout;
    time_t dataTime;
    time(&dataTime);
    QString fileNameTemp("session %1.txt");
    fileNameTemp = fileNameTemp.arg(ctime(&dataTime));

    fout.open(fileNameTemp.toStdString().c_str());
    // TODO some action

    fout.close();
}

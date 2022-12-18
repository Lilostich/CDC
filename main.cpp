#include "mainwindow.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    system("python hello_world.py > result_testing");
//    std::cout << result << std::endl;
    MainWindow w;
    w.show();
    return a.exec();
}

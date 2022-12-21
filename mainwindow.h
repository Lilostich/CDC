#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include "gui//admining.h"
#include "gui/auto_testing.h"
#include "gui/handtestingform.h"
#include "gui/hand_testing_details.h"
#include "gui/test_cases.h"
#include "gui/login.h"
#include "gui/report.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    int getLevel(){return level_sec;}

public slots:
    void active();

private:
    int level_sec;
    Ui::MainWindow *ui;
    QDockWidget *_admining;
    QDockWidget *_autoTesting;
    QDockWidget *_handTesting;
    QDockWidget *_testCases;
    Login * _login;
};
#endif // MAINWINDOW_H

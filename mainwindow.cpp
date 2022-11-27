#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _admining = new QDockWidget("Администрирование");
    _autoTesting = new QDockWidget("Авто тестыы");
    _handTesting = new QDockWidget("Ручные тесты");
    _testCases = new QDockWidget("Тестовые наборы");

    _admining->setWidget(new admining());
    _autoTesting->setWidget(new autoTesting());
    _handTesting->setWidget(new HandTestingForm());
    _testCases->setWidget(new TestCases());

    this->addDockWidget(Qt::TopDockWidgetArea,_admining);
    this->addDockWidget(Qt::TopDockWidgetArea,_autoTesting);
    this->addDockWidget(Qt::TopDockWidgetArea,_handTesting);
    this->addDockWidget(Qt::TopDockWidgetArea,_testCases);
}

MainWindow::~MainWindow()
{
    delete ui;
}


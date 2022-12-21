#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->hide();
    _login = new Login();
    _login->show();
    _admining = new QDockWidget("Администрирование");
    _autoTesting = new QDockWidget("Тест менеджер");
    _handTesting = new QDockWidget("Редактор тестов");
    _testCases = new QDockWidget("Отчетность");

    _admining->setWidget(new admining());
    _autoTesting->setWidget(new TestCases());
    _handTesting->setWidget(new HandTestingDetails());
    _testCases->setWidget(new report());

    connect(_login,SIGNAL(successEnter()),
            this,SLOT(active()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::active()
{
    this->show();
    _login->hide();
    this->addDockWidget(Qt::TopDockWidgetArea,_admining);
    this->addDockWidget(Qt::TopDockWidgetArea,_autoTesting);
    this->addDockWidget(Qt::TopDockWidgetArea,_handTesting);
    this->addDockWidget(Qt::TopDockWidgetArea,_testCases);
}


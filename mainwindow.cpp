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

    QAction *authorize = new QAction("Сменить аккаунт");
    ui->menuFile->addAction(authorize);
    connect(authorize,&QAction::triggered,
            this,&MainWindow::go_login);
    connect(_login,SIGNAL(successEnter()),
            this,SLOT(active()));

    this->addDockWidget(Qt::TopDockWidgetArea,_admining);
    this->addDockWidget(Qt::TopDockWidgetArea,_autoTesting);
    this->addDockWidget(Qt::TopDockWidgetArea,_handTesting);
    this->addDockWidget(Qt::TopDockWidgetArea,_testCases);
    _admining->hide();
//    this->dock
    _autoTesting->hide();
    _handTesting->hide();
    _testCases->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::active()
{
    this->show();
    _login->hide();
    _admining->show();
//    this->dock
    _autoTesting->show();
    _handTesting->show();
    _testCases->show();

}

void MainWindow::go_login()
{
    _admining->hide();
//    this->dock
    _autoTesting->hide();
    _handTesting->hide();
    _testCases->hide();
    _login->show();
}


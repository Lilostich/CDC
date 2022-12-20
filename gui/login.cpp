#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    registration = new Registration();
    changing = new ChangePassword();
    connect(registration,SIGNAL(close_me()),
            this,SLOT(show_me()));
    connect(changing,SIGNAL(close_me()),
            this,SLOT(show_me()));
}

Login::~Login()
{
    delete ui;
}

void Login::show_me()
{
    this->show();
    registration->hide();
    changing->hide();
}

void Login::on_button_regestration_clicked()
{
    // TODO открыть окно регистрации
    registration->show();
    this->hide();
}


void Login::on_button_enter_clicked()
{
    // TODO проверка файла
    if(1)
        successEnter();
}


void Login::on_button_change_password_clicked()
{
    changing->show();
    this->hide();
}


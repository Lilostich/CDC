#include "login.h"
#include "ui_login.h"
#include <QIcon>
#include <QJsonDocument>
#include <QJsonObject>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
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
    registration->clear_fields();
    this->hide();
}


void Login::on_button_enter_clicked()
{

    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    CDC::Secure sec("CDC.cfg");
    if(sec.Enter(login.toStdString(),password.toStdString()))
        successEnter();
    else {
        msg.showMessage("Пароль или логин недействительны.");
    }
}


void Login::on_button_change_password_clicked()
{
    changing->clear_fields();
    changing->show();
    this->hide();
}


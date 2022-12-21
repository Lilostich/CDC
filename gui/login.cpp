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
    // TODO проверка файла
    QFile file("fileName");
    file.open(QIODevice::ReadOnly);

    QByteArray bytes = file.readAll();
    QJsonDocument doc;
    doc = QJsonDocument::fromJson(bytes);
    QJsonObject obj = doc.object();
    QString pass; // Пароль в файле

    if(obj.find("pass") != obj.end()){
        pass = obj["pass"].toString();
    }

    static int i = 0;
    if(i == 0)
        successEnter();
    else {
        msg.showMessage("Пароль или логин недействительны.");
        msg.setWindowTitle("Ошибка");
        msg.show();
    }
    i++;
}


void Login::on_button_change_password_clicked()
{
    changing->clear_fields();
    changing->show();
    this->hide();
}


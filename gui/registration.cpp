#include "registration.h"
#include "ui_registration.h"
#include "core/Secure.hpp"

Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    ui->pass1->setEchoMode(QLineEdit::Password);
    ui->pass2->setEchoMode(QLineEdit::Password);
}

void Registration::clear_fields()
{
    ui->pass1->setText("");
    ui->pass2->setText("");
    ui->login_edit->setText("");
    ui->mail_edit->setText("");
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_but_reg_clicked()
{
    printf("cancel but\n");
    if (ui->pass1->text() != ui->pass2->text()){
        msg.showMessage("Ошибка, пароли не совпадают");
        return;
    } else {
        QRegExp mailMask("[a-zA-Z0-9]+@[a-zA-Z]+\\.[a-z]+");
        if (!mailMask.exactMatch(ui->mail_edit->text()))
        {
            msg.showMessage("Некоректная почта");
            return;
        }
    }

    QString name = ui->login_edit->text();
    QString pass = ui->pass1->text();
    CDC::Secure sec("CDC.cfg");
    if(!sec.Register(name.toStdString(),pass.toStdString())){
        msg.showMessage("Ошибка");
        return;
    }
    close();
}


void Registration::on_but_cancel_clicked()
{
    printf("cancel but\n");
    close();
}

void Registration::closeEvent(QCloseEvent *e){
    printf("close event\n");
    close_me();
    e->ignore();
}


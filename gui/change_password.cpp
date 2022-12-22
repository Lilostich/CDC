#include "change_password.h"
#include "ui_change_password.h"
#include <QCloseEvent>
#include "core/Secure.hpp"

ChangePassword::ChangePassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
    ui->old_pass_edit->setEchoMode(QLineEdit::Password);
    ui->new_pass_edit1->setEchoMode(QLineEdit::Password);
    ui->new_pass_edit2->setEchoMode(QLineEdit::Password);
    ui->label_4->setText("");
}

ChangePassword::~ChangePassword()
{
    delete ui;
}

void ChangePassword::clear_fields()
{
    ui->login_edit->setText("");
    ui->old_pass_edit->setText("");
    ui->new_pass_edit1->setText("");
    ui->new_pass_edit2->setText("");
}

void ChangePassword::on_but_apply_clicked()
{
    // label_4 для сообщений проверки
    // TODO проверка совпадения паролей новых
    if(ui->new_pass_edit1->text() != ui->new_pass_edit2->text()){
        msg.showMessage("Пароли не совпадают");
        return;
    }
    QString name = ui->login_edit->text();
    QString pass = ui->new_pass_edit1->text();

    CDC::Secure sec("CDC.cfg");
    if(!sec.Register(name.toStdString(),pass.toStdString())){
        msg.showMessage("Ошибка");
        return;
    }
    close();
}

void ChangePassword::closeEvent(QCloseEvent *e){
    close_me();
    e->ignore();
}


void ChangePassword::on_but_cancel_clicked()
{
    close();
}


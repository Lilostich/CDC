#include "edit_pass.h"
#include "ui_edit_pass.h"

edit_pass::edit_pass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edit_pass)
{
    ui->setupUi(this);
    ui->pass_edit->setEchoMode(QLineEdit::Password);
    ui->check_pass_edit->setEchoMode(QLineEdit::Password);
}

edit_pass::~edit_pass()
{
    delete ui;
}

void edit_pass::on_cancel_clicked()
{
    close();
}

void edit_pass::on_save_clicked()
{
    close();
}

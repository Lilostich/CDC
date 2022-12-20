#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    ui->pass1->setEchoMode(QLineEdit::Password);
    ui->pass2->setEchoMode(QLineEdit::Password);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_but_reg_clicked()
{
    printf("cancel but\n");
    // TODO rewrite info
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


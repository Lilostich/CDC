#include "send_form.h"
#include "ui_send_form.h"

send_form::send_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::send_form)
{
    ui->setupUi(this);
}

send_form::~send_form()
{
    delete ui;
}

// close
void send_form::on_pushButton_clicked()
{
    close();
}

// выполнить
void send_form::on_pushButton_2_clicked()
{
    // TODO действия соответствующие нажатию кнопки выполнить
    close();
}

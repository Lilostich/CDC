#include "admining_details.h"
#include "ui_admining_details.h"

adminingDetails::adminingDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminingDetails)
{
    ui->setupUi(this);
    edit_pass_form = new edit_pass;
    connect(edit_pass_form,SIGNAL(close_me()),
            this,SLOT(close_slot()));
}

adminingDetails::~adminingDetails()
{
    delete ui;
}

void adminingDetails::fill(QString name, QString login, QString mail, QString role)
{
    nice_end = false;
    ui->mail_edit->setText(mail);
    ui->name_edit->setText(name);
    ui->login_edit->setText(login);
    ui->comboBox_role->clear();

    ui->comboBox_role->addItems(roles);
    if (roles[0] == role)
        ui->comboBox_role->setCurrentIndex(0);
    else if (roles[1] == role)
        ui->comboBox_role->setCurrentIndex(1);
    else if (roles[2] == role)
        ui->comboBox_role->setCurrentIndex(2);
    else
        ui->comboBox_role->setCurrentIndex(0);
}

QString adminingDetails::getName(){return ui->name_edit->text();}

QString adminingDetails::getLogin() { return ui->login_edit->text(); }

QString adminingDetails::getMail() { return ui->mail_edit->text(); }

QString adminingDetails::getRole() { return ui->comboBox_role->currentText(); }

void adminingDetails::close_slot()
{
    this->edit_pass_form->hide();
}

void adminingDetails::on_pushButton_clicked()
{
    edit_pass_form->show();
}

void adminingDetails::on_exec_clicked()
{
    close();
}

void adminingDetails::on_pushButton_2_clicked()
{
    nice_end = true;
    close();
}

void adminingDetails::closeEvent(QCloseEvent *e){
    close_me();
    e->ignore();
}

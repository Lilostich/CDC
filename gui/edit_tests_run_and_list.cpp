#include "edit_tests_run_and_list.h"
#include "ui_edit_tests_run_and_list.h"

edit_tests_run_and_list::edit_tests_run_and_list(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edit_tests_run_and_list)
{
    ui->setupUi(this);
}

edit_tests_run_and_list::~edit_tests_run_and_list()
{
    delete ui;
}

void edit_tests_run_and_list::list_variant()
{
    isItList = true;
    this->setWindowTitle("Редактирование тест набора");
    ui->desc_label->setText("Название тест набора");
    ui->number_label->setText("Номер тест набора");
}

void edit_tests_run_and_list::run_variant()
{
    isItList = false;
    this->setWindowTitle("Редактирование тест рана");
    ui->desc_label->setText("Название тест рана");
    ui->number_label->setText("Номер тест рана");
}

void edit_tests_run_and_list::on_delete_2_clicked()
{
    close();
    // TODO удаление файла набора/рана
}

void edit_tests_run_and_list::on_create_clicked()
{
    close();
    // TODO создание файла набора/рана
}

void edit_tests_run_and_list::on_plus_clicked()
{

}

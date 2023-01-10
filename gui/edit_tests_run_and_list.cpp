#include "edit_tests_run_and_list.h"
#include "ui_edit_tests_run_and_list.h"
#include "core/file_manager.h"

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
    qDebug("Start list_variant");
    isItList = true;
    this->setWindowTitle("Редактирование тест набора");
    ui->combobox->clear();
    ui->combobox->addItems(file_manager::get_all_lists());
    ui->desc_label->setText("Название нового тест набора");
    ui->number_label->setText("Номер тест набора");
    qDebug("End list_variant");
}

void edit_tests_run_and_list::run_variant()
{
    isItList = false;
    this->setWindowTitle("Редактирование тест рана");
    ui->combobox->clear();
    ui->combobox->addItems(file_manager::get_all_runs());
    ui->desc_label->setText("Название нового тест рана");
    ui->number_label->setText("Номер тест рана");
}

void edit_tests_run_and_list::on_delete_2_clicked()
{
    QString name = ui->combobox->currentText();
    if (name == ""){
        qDebug("empty test/run name");
        return;
    } else {
        if (this->isItList)
            file_manager::delete_list(name);
        else
            file_manager::delete_run(name);
    }

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
    QString name = ui->desc_edit->text();
    if (name == ""){
        qDebug("empty test/run name");
        return;
    } else {
        if (this->isItList)
            file_manager::create_list(name);
        else
            file_manager::create_run(name);
    }

    QString addedName = ui->desc_edit->text();

    // TODO добавить ран\лист
}

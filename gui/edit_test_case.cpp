#include "edit_test_case.h"
#include "ui_edit_test_case.h"
#include "core/test_case.h"
#include <ctime>
#include <time.h>

Edit_test_case::Edit_test_case(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Edit_test_case)
{
    ui->setupUi(this);
    ui->status->addItems({"Finished","Started","not Started"});
    ui->status->setCurrentIndex(2);
}

Edit_test_case::~Edit_test_case()
{
    delete ui;
}

void Edit_test_case::fill(QString name = "")
{
    if (name == ""){
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->data_creation->setText("");
        ui->path_script_edit->setText("");
    } else {
    TestCase new_test(name);
    ui->lineEdit->setText(new_test.get(TestCase::value::name).toString());
    ui->lineEdit_2->setText(new_test.get(TestCase::value::description).toString());
    ui->data_creation->setText(new_test.get(TestCase::value::date_creation).toString());
    ui->path_script_edit->setText(new_test.get(TestCase::value::pyScript).toString());
    }
}

void Edit_test_case::closeEvent(QCloseEvent *e){
    close_me();
    e->ignore();
}

void Edit_test_case::on_end_testing_clicked()
{
    ui->status->setCurrentIndex(0);
    time_t tim;
    time(&tim);
    ui->data_testing->setText(ctime(&tim));
    close();
}

void Edit_test_case::on_delete_2_clicked()
{
    file_manager::delete_test(ui->lineEdit->text());

    close();
}

void Edit_test_case::on_save_clicked()
{
    TestCase new_test;
    new_test.set(TestCase::value::name,ui->lineEdit->text());
    qDebug(QString("test name for save %1").arg(ui->lineEdit->text()).toStdString().c_str());
    new_test.set(TestCase::value::description,ui->lineEdit_2->text());
    new_test.set(TestCase::value::date_creation,ui->data_creation->text());
    new_test.set(TestCase::value::pyScript,ui->path_script_edit->text());

    new_test.save(ui->lineEdit->text());
    close();
}

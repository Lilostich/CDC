#include "edit_test_case.h"
#include "ui_edit_test_case.h"

Edit_test_case::Edit_test_case(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Edit_test_case)
{
    ui->setupUi(this);
}

Edit_test_case::~Edit_test_case()
{
    delete ui;
}

void Edit_test_case::closeEvent(QCloseEvent *e){
    close_me();
    e->ignore();
}

void Edit_test_case::on_end_testing_clicked()
{
    close();
}

void Edit_test_case::on_delete_2_clicked()
{
    close();
}

void Edit_test_case::on_save_clicked()
{
    close();
}

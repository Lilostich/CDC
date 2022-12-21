#include "hand_testing_details.h"
#include "ui_hand_testing_details.h"

HandTestingDetails::HandTestingDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HandTestingDetails)
{
    ui->setupUi(this);
    edit_form = new Edit_test_case;
    connect(edit_form,SIGNAL(close_me()),
            this,SLOT(close_slot()));
    list_and_run_form = new edit_tests_run_and_list;
    connect(list_and_run_form,SIGNAL(close_me()),
            this,SLOT(close_slot()));

}

HandTestingDetails::~HandTestingDetails()
{
    delete ui;
}

void HandTestingDetails::fill(const QTableWidgetItem *item)
{
    QString itemID  = item->text();
    this->setWindowTitle(itemID);
    // TODO filling
}

void HandTestingDetails::on_save_button_clicked()
{
    edit_form->show();
    // TODO переслать в форму пустые параметры
}

void HandTestingDetails::on_pushButton_2_clicked()
{
    list_and_run_form->run_variant();
    list_and_run_form->show();
}

void HandTestingDetails::on_pushButton_3_clicked()
{
    list_and_run_form->list_variant();
    list_and_run_form->show();
}

// редактировать тест
void HandTestingDetails::on_pushButton_clicked()
{
    edit_form->show();
    // TODO переслать в форму актуальные параметры
}

void HandTestingDetails::on_comboBox_currentIndexChanged(int index)
{

}

void HandTestingDetails::on_comboBox_currentIndexChanged(const QString &arg1)
{

}

void HandTestingDetails::close_slot()
{
    edit_form->hide();
    list_and_run_form->hide();
}

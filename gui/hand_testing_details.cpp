#include "hand_testing_details.h"
#include "ui_hand_testing_details.h"
#include "core/file_manager.h"
#include <QJsonDocument>
#include <QJsonObject>
#include "core/test_case.h"

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
    ui->comboBox->addItems(file_manager::get_all_tests());
    QString test_name = ui->comboBox->currentText();
    add_mode = 0;
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
    edit_form->fill("");
    add_mode = 1;
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
    edit_form->fill(ui->comboBox->currentText());
    // TODO переслать в форму актуальные параметры
}

void HandTestingDetails::on_comboBox_currentIndexChanged(int index)
{

}

void HandTestingDetails::on_comboBox_currentIndexChanged(const QString &arg1)
{
    TestCase test(arg1);

    ui->comment->setText(test.get(TestCase::value::pyScript).toString());
    ui->name->setText(test.get(TestCase::value::name).toString());
    ui->data_testing->setText(test.get(TestCase::value::date_creation).toString());
    ui->descryption->setText(test.get(TestCase::value::description).toString());
}

void HandTestingDetails::close_slot()
{
    edit_form->hide();
    list_and_run_form->hide();

    ui->comboBox->clear();
    ui->comboBox->addItems(file_manager::get_all_tests());

}

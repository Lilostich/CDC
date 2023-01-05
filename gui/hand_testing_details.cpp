#include "hand_testing_details.h"
#include "ui_hand_testing_details.h"
#include "core/file_manager.h"
#include <QJsonDocument>
#include <QJsonObject>

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
    // TODO переслать в форму актуальные параметры
}

void HandTestingDetails::on_comboBox_currentIndexChanged(int index)
{

}

void HandTestingDetails::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QJsonObject obj = file_manager::read_test(arg1);
    ui->status->addItem(obj["Status"].toString());
    ui->comment->setText(obj["Comment"].toString());
    ui->name->setText(obj["ID"].toString());
    ui->data_testing->setText(obj["Deadline"].toString());
    ui->descryption->setText(obj["Host"].toString());
}

void HandTestingDetails::close_slot()
{
//    edit_form->hide();
//    list_and_run_form->hide();
//    if(add_mode){
//        add_mode = 0;
//        QJsonDocument doc;
////        ui->status->addItem()
//        QString status = "";
//        QString comment = ui->comment->toPlainText();
//        QString name = "";//ui->
//        QString data = ui->data_testing->text();
//        QString host = ui->descryption->text();
//        QJsonObject obj;
//        printf("1\n");
//        obj["Status"] = status;
//        obj["comment"] = comment;
//        obj["ID"] = name;
//        obj["Deadline"] = data;
//        obj["Host"] = host;
//        printf("2\n");
//        doc.setObject(obj);
//        file_manager::write_test(name,doc.toJson());
//    }
//    ui->comboBox->clear();
//    ui->comboBox->addItems(file_manager::get_all_tests());

}

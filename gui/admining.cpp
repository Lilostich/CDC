#include "gui/admining.h"
#include "ui_admining.h"

admining::admining(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admining)
{
    ui->setupUi(this);
    this->_details = new adminingDetails;
    connect(_details,SIGNAL(close_me()),
            this,SLOT(close_slot()));
}

admining::~admining()
{
    delete ui;
}

void admining::close_slot()
{
    if (this->_details->get_Nice()){
        switch (add_mode) {
        case -2:
            break;
        case -1:
            ui->tableWidget->insertRow(0);
            ui->tableWidget->setItem(0,0,new QTableWidgetItem(_details->getName()));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem(_details->getLogin()));
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(_details->getMail()));
            ui->tableWidget->setItem(0,3,new QTableWidgetItem(_details->getRole()));
            break;
        default:
            ui->tableWidget->setItem(add_mode,0,new QTableWidgetItem(_details->getName()));
            ui->tableWidget->setItem(add_mode,1,new QTableWidgetItem(_details->getLogin()));
            ui->tableWidget->setItem(add_mode,2,new QTableWidgetItem(_details->getMail()));
            ui->tableWidget->setItem(add_mode,3,new QTableWidgetItem(_details->getRole()));
            break;
        }
        add_mode = -2;
    }
    _details->hide();
}

void admining::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
//    _details->fill(item);
//    _details->show();
}


void admining::on_pushButton_4_clicked()
{

}

void admining::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    add_mode = index.row();

    printf("row is %d",index.row());
    printf("coloumn is %d",index.row());

    QString name = ui->tableWidget->item(index.row(),0)->text();
    QString login = ui->tableWidget->item(index.row(),1)->text();
    QString mail = ui->tableWidget->item(index.row(),2)->text();
    QString role = ui->tableWidget->item(index.row(),3)->text();
    _details->fill(name,login,mail,role);
    _details->show();
    // по индексу
}

void admining::on_pushButton_2_clicked()
{
    _details->show();
    add_mode = -1;
    _details->fill("Имя","Логин","Почта","Роль");
}

void admining::on_pushButton_clicked()
{
    int row = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(row);
}

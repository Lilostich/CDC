#include "admining.h"
#include "ui_admining.h"

admining::admining(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admining)
{
    ui->setupUi(this);
}

admining::~admining()
{
    delete ui;
}

void admining::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    if (_details = nullptr)
        _details = new adminingDetails();
    _details->fill(item);
    _details->show();
}


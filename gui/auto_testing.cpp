#include "auto_testing.h"
#include "ui_auto_testing.h"

autoTesting::autoTesting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::autoTesting)
{
    ui->setupUi(this);
}

autoTesting::~autoTesting()
{
    delete ui;
}

void autoTesting::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    if (_details == nullptr)
        _details = new autoTestingDetails;;
    _details->fill(item);
    _details->show();
}


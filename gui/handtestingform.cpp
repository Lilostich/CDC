#include "handtestingform.h"
#include "ui_handtestingform.h"

HandTestingForm::HandTestingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HandTestingForm),
    _details(nullptr)
{
    ui->setupUi(this);
}

HandTestingForm::~HandTestingForm()
{
    delete ui;
}

void HandTestingForm::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    if (_details == nullptr)
        _details = new HandTestingDetails();
    _details->fill(item);
    _details->show();
}


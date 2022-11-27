#include "auto_testing_details.h"
#include "ui_auto_testing_details.h"

autoTestingDetails::autoTestingDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::autoTestingDetails)
{
    ui->setupUi(this);
}

autoTestingDetails::~autoTestingDetails()
{
    delete ui;
}

void autoTestingDetails::fill(const QTableWidgetItem *item)
{
    // TODO добавить заполнение формы
}

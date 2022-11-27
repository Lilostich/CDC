#include "admining_details.h"
#include "ui_admining_details.h"

adminingDetails::adminingDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminingDetails)
{
    ui->setupUi(this);
}

adminingDetails::~adminingDetails()
{
    delete ui;
}

void adminingDetails::fill(const QTableWidgetItem *item)
{
    // TODO заполнить форму
}

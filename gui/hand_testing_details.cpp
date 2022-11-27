#include "hand_testing_details.h"
#include "ui_hand_testing_details.h"

HandTestingDetails::HandTestingDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HandTestingDetails)
{
    ui->setupUi(this);
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

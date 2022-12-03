#include "test_cases.h"
#include "ui_test_cases.h"

TestCases::TestCases(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestCases)
{
    ui->setupUi(this);
}

TestCases::~TestCases()
{
    delete ui;
}

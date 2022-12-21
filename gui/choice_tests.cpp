#include "choice_tests.h"
#include "ui_choice_tests.h"

Choice_tests::Choice_tests(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Choice_tests)
{
    ui->setupUi(this);
}

Choice_tests::~Choice_tests()
{
    delete ui;
}


void Choice_tests::on_cancel_clicked()
{
    close();
}

void Choice_tests::on_apply_clicked()
{
    close();
}

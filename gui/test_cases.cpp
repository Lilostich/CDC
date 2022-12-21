#include "test_cases.h"
#include "ui_test_cases.h"

TestCases::TestCases(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestCases)
{
    ui->setupUi(this);
    choice_form = new Choice_tests;
    connect(choice_form, SIGNAL(close_me()),
            this,SLOT(close_slot()));
}

TestCases::~TestCases()
{
    delete ui;
}

// выбрать тест раны
void TestCases::on_chose_test_runs_clicked()
{
    choice_form->show();
}

// выбрат тест списки
void TestCases::on_chose_list_clicked()
{
    choice_form->show();
}

void TestCases::close_slot()
{
    choice_form->hide();
}

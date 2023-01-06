#include "test_cases.h"
#include "ui_test_cases.h"
#include "core/file_manager.h"
#include "core/test_case.h"
#include <QTableWidget>

TestCases::TestCases(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestCases)
{
    ui->setupUi(this);
    choice_form = new Choice_tests;
    connect(choice_form, SIGNAL(close_me()),
            this,SLOT(close_slot()));
    ui->comboBox->clear();
    ui->comboBox->addItems(file_manager::get_all_runs());
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

void TestCases::on_comboBox_currentIndexChanged(const QString &arg1)
{
    // TODO подсосать новые тесты
    fill_table_values(arg1);
}

void TestCases::fill_table_values(const QString run_name)
{
    TestRun run(run_name);
    QStringList lists = run.get(TestRun::value::lists).toStringList();
    QStringList solo_tests = run.get(TestRun::value::tests).toStringList();

    ui->tableWidget->clear();
    for(auto &list_name : lists){
        TestSuite list(list_name);
        QStringList tests = list.get(TestSuite::value::tests).toStringList();
        for(auto &test_name : tests){
            TestCase current_test(test_name);
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            QTableWidgetItem item;
            item.setData(Qt::DisplayRole,run_name);
            ui->tableWidget->setItem(ui->tableWidget->rowCount(),0,item.clone());
            item.setData(Qt::DisplayRole,list_name);
            ui->tableWidget->setItem(ui->tableWidget->rowCount(),1,item.clone());
            item.setData(Qt::DisplayRole,test_name);
            ui->tableWidget->setItem(ui->tableWidget->rowCount(),2,item.clone());
        }
    }
}


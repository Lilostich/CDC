#include "report.h"
#include "ui_report.h"
#include "core/file_manager.h"

report::report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::report)
{
    ui->setupUi(this);
    sendForm = new send_form;
    connect(sendForm,SIGNAL(close_me()),
            this,SLOT(close_slot()));
}

report::~report()
{
    delete ui;
}

// вывести все проекты
void report::on_pushButton_clicked()
{
    QStringList projects = file_manager::get_all_projects();
    // TODO вывод куда?
}

// вывести все задачи по проекту
void report::on_pushButton_2_clicked()
{
    // TODO куда вывести
    QString project_name = "";
    QStringList tasks = file_manager::get_tasks(project_name);
}

// вывести результаты по тест рану
void report::on_pushButton_4_clicked()
{

}

// отправка тестрана по задаче
void report::on_pushButton_3_clicked()
{

}

// отправка резлультатов тестрана по задаче
void report::on_pushButton_6_clicked()
{

}

// отправка TaskID
void report::on_pushButton_7_clicked()
{

}

// закрыть задачу
void report::on_pushButton_5_clicked()
{

}

// вывести нераспределенные задачи
void report::on_pushButton_8_clicked()
{

}

// отправить результаты сессии
void report::on_pushButton_9_clicked()
{
    // TODO форма
    sendForm->show();
}

// выйти из системы
void report::on_pushButton_10_clicked()
{
    // TODO заново авторизация из меню сверху
}

//выгрузить файл
void report::on_pushButton_12_clicked()
{

}

// запустить выбранные тесты
void report::on_pushButton_11_clicked()
{

}

void report::close_slot()
{
    sendForm->hide();
}

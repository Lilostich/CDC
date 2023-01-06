#include "report.h"
#include "ui_report.h"
#include "core/file_manager.h"

// #include "core/Project.hpp"
#include "core/task_manager.h"
#include "core/Secure.hpp"

report::report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::report)
{
    ui->setupUi(this);
    sendForm = new send_form;
    connect(sendForm,SIGNAL(close_me()),
            this,SLOT(close_slot()));
    ui->comboBox->clear();
    ui->comboBox->addItems(file_manager::get_all_projects());
    ui->comboBox_2->clear();
    ui->comboBox_2->addItems(file_manager::get_all_runs());
    ui->comboBox_3->clear();
    ui->comboBox_4->clear();
    ui->comboBox_5->clear();
    ui->comboBox_6->clear();

}

report::~report()
{
    delete ui;
}

// вывести все проекты
void report::on_pushButton_clicked()
{
    // QStringList projects = file_manager::get_all_projects();
    // TODO вывод куда?
    Task_manager TaskMan("CDC.cfg");
    std::string Output = TaskMan.print_list_project();
}

// вывести все задачи по проекту
void report::on_pushButton_2_clicked()
{
    // TODO куда вывести и как берется проект из поля?
    QString project_name = "";
    // QStringList tasks = file_manager::get_tasks(project_name);
    Task_manager TaskMan("CDC.cfg");
    std::string Output = TaskMan.print_list_task(project_name.toStdString());
}

// вывести результаты по тест рану
void report::on_pushButton_4_clicked()
{
    // TODO: куда вывести и как будет передаваться проект, задача и ран?
    std::string Project = "";
    std::string Task = "";
    std::string Run = "";

    Task_manager TaskMan("CDC.cfg");
    std::string Output = TaskMan.print_run(Project, Task, Run);
}

// отправка (выгрзука) тестрана по задаче
void report::on_pushButton_3_clicked()
{
    // TODO: куда вывести и как будет передаваться проект, задача и ран?
    std::string Project = "";
    std::string Task = "";
    std::string Run = "";

    Task_manager TaskMan("CDC.cfg");
    TaskMan.UploadRun(Project, Task, Run);
}

// отправка (выгрзука) резлультатов тестрана по задаче
void report::on_pushButton_6_clicked()
{
    // TODO: куда вывести и как будет передаваться проект, задача и лог?
    std::string Project = "";
    std::string Task = "";
    std::string Log = "";

    Task_manager TaskMan("CDC.cfg");
    TaskMan.UploadResults(Project, Task, Log);

}

// отправка (выгрзука) TaskID
void report::on_pushButton_7_clicked()
{
    // TODO: куда вывести и как будет передаваться проект, задача?
    std::string Project = "";
    std::string Task = "";

    Task_manager TaskMan("CDC.cfg");
    TaskMan.UploadTaskID(Project, Task);

}

// закрыть задачу
void report::on_pushButton_5_clicked()
{
    // TODO: куда вывести и как будет передаваться проект, задача?
    std::string Project = "";
    std::string Task = "";

    Task_manager TaskMan("CDC.cfg");
    TaskMan.close_task(Project, Task);
}

// вывести нераспределенные задачи (Убираем)
void report::on_pushButton_8_clicked()
{

}

// отправить результаты сессии (Этим занимается отправка результатов рана - Убираем)
void report::on_pushButton_9_clicked()
{
    // TODO форма
    sendForm->show();
}


// выйти из системы
void report::on_pushButton_10_clicked()
{
    // TODO заново авторизация из меню сверху
    // Раскоментить, когда будет возможная передача по ссылке
    //CDC::Secure* SecManager = InputSecManager; // Передача по ссылке?
    //SecManager->Exit(0); // 0 - просто удалить запись о входе, 1 - еще закрыть прогу
}

//выгрузить файл (все данные выгружаются в файлах выше - Убираем)
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

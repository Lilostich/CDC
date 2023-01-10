#include "gui/admining.h"
#include "ui_admining.h"

admining::admining(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admining)
{
    ui->setupUi(this);
    this->_details = new adminingDetails;
    connect(_details,SIGNAL(close_me()),
            this,SLOT(close_slot()));

    CDC::Admin admin("CDC.cfg");
    QStringList users = admin.ListUsers();
    for (auto &user : users){
        qDebug(user.toStdString().c_str());
        QStringList user_data{admin.UserInfo(user.toStdString())};
        if (user_data.size() < 3)
            user_data = QStringList{"no info", "no info", "no info"};
        QString name,login,have_pass,role;

        for (auto & str : user_data)
            qDebug(str.toStdString().c_str());

        login = user;
        name = user_data[0];
        role = user_data[1];
        have_pass = user_data[2];
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(name));
        ui->tableWidget->setItem(0,1,new QTableWidgetItem(login));
        ui->tableWidget->setItem(0,2,new QTableWidgetItem(role));
        ui->tableWidget->setItem(0,3,new QTableWidgetItem(have_pass));
    }
}

admining::~admining()
{
    delete ui;
}

void admining::close_slot()
{
    if (this->_details->get_Nice()){
        switch (add_mode) {
        case -2:
            break;
        case -1:
            ui->tableWidget->insertRow(0);
            ui->tableWidget->setItem(0,0,new QTableWidgetItem(_details->getName()));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem(_details->getLogin()));
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(_details->getMail()));
            ui->tableWidget->setItem(0,3,new QTableWidgetItem(_details->getRole()));
        {
            CDC::Admin admin_panel("CDC.cfg");
            if (_details->getRole() == "Тестировщик"){
                admin_panel.AddUser(_details->getLogin().toStdString(),2);
            }
            if (_details->getRole() == "Тест-аналитик"){
                admin_panel.AddUser(_details->getLogin().toStdString(),1);
            }
            if (_details->getRole() == "Администратор"){
                admin_panel.AddUser(_details->getLogin().toStdString(),0);
            }
        }
            break;
        default:
            ui->tableWidget->setItem(add_mode,0,new QTableWidgetItem(_details->getName()));
            ui->tableWidget->setItem(add_mode,1,new QTableWidgetItem(_details->getLogin()));
            ui->tableWidget->setItem(add_mode,2,new QTableWidgetItem(_details->getMail()));
            ui->tableWidget->setItem(add_mode,3,new QTableWidgetItem(_details->getRole()));
        {
            CDC::Admin adm("CDC.cfg");
            adm.SetLevel(ui->tableWidget->item(add_mode,1)->text().toStdString(),
                         ui->tableWidget->item(add_mode,3)->text().toUShort());
        }
            break;

        }
        add_mode = -2;
    }
    _details->hide();
}

// FIXME -  больше не нужно
void admining::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
//    _details->fill(item);
//    _details->show();
}


void admining::on_pushButton_4_clicked()
{

}

void admining::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    add_mode = index.row();

    printf("row is %d",index.row());
    printf("coloumn is %d",index.row());

    QString name = ui->tableWidget->item(index.row(),0)->text();
    QString login = ui->tableWidget->item(index.row(),1)->text();
    QString mail = ui->tableWidget->item(index.row(),2)->text();
    QString role = ui->tableWidget->item(index.row(),3)->text();
    _details->fill(name,login,mail,role);
    _details->show();
    // по индексу
}

void admining::on_pushButton_2_clicked()
{
    _details->show();
    add_mode = -1;
    _details->fill("Имя","Логин","Почта","Роль");
}

void admining::on_pushButton_clicked()
{
    int row = ui->tableWidget->currentRow();
    CDC::Admin adminPanel("CDC.cfg");
    std::cerr << ui->tableWidget->item(row,1)->text().toStdString() << endl;
    adminPanel.DeleteUser(ui->tableWidget->item(row,1)->text().toStdString());
    ui->tableWidget->removeRow(row);
}

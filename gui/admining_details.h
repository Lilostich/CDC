#ifndef ADMINING_DETAILS_H
#define ADMINING_DETAILS_H

#include <QWidget>
#include <QTableWidgetItem>
#include "gui/edit_pass.h"

namespace Ui {
class adminingDetails;
}

class adminingDetails : public QWidget
{
    Q_OBJECT

public:
    explicit adminingDetails(QWidget *parent = nullptr);
    ~adminingDetails();    
    void fill(QString name, QString login, QString mail, QString role);

    QString getName();
    QString getLogin();
    QString getMail();
    QString getRole();
    bool get_Nice(){return nice_end;}
signals:
    void close_me();

private slots:
    void close_slot();

    void on_pushButton_clicked();

    void on_exec_clicked();

    void on_pushButton_2_clicked();

protected:
    void closeEvent(QCloseEvent *e);

private:
    Ui::adminingDetails *ui;
    edit_pass *edit_pass_form;
    const QStringList roles = {"Тестировщик","Тест-аналитик","Администратор"};
    bool nice_end;
};

#endif // ADMINING_DETAILS_H

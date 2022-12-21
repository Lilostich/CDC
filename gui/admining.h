#ifndef ADMINING_H
#define ADMINING_H

#include <QWidget>
#include <QTableWidgetItem>

#include "admining_details.h"
#include "gui/admining_details.h"

namespace Ui {
class admining;
}

class admining : public QWidget
{
    Q_OBJECT

public:
    explicit admining(QWidget *parent = nullptr);
    ~admining();

private slots:
    void close_slot();
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

    void on_pushButton_4_clicked();

    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::admining *ui;
    adminingDetails *_details;
    int add_mode;//-2 - none; -1 - add; 0+ - index of record
};

#endif // ADMINING_H

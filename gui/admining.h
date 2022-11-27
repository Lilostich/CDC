#ifndef ADMINING_H
#define ADMINING_H

#include <QWidget>
#include <QTableWidgetItem>

#include "admining_details.h"

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
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::admining *ui;
    adminingDetails *_details;
};

#endif // ADMINING_H

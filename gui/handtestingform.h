#ifndef HANDTESTINGFORM_H
#define HANDTESTINGFORM_H

#include <QWidget>
#include <QTableWidgetItem>

#include "hand_testing_details.h"

namespace Ui {
class HandTestingForm;
}

class HandTestingForm : public QWidget
{
    Q_OBJECT

public:
    explicit HandTestingForm(QWidget *parent = nullptr);
    ~HandTestingForm();

private slots:
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::HandTestingForm *ui;
    HandTestingDetails *_details;
};

#endif // HANDTESTINGFORM_H

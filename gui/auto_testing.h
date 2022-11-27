#ifndef AUTO_TESTING_H
#define AUTO_TESTING_H

#include <QWidget>
#include <QTableWidgetItem>

#include "auto_testing_details.h"

namespace Ui {
class autoTesting;
}

class autoTesting : public QWidget
{
    Q_OBJECT

public:
    explicit autoTesting(QWidget *parent = nullptr);
    ~autoTesting();

private slots:
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::autoTesting *ui;
    autoTestingDetails *_details;
};

#endif // AUTO_TESTING_H

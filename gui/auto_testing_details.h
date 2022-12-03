#ifndef AUTO_TESTING_DETAILS_H
#define AUTO_TESTING_DETAILS_H

#include <QWidget>
#include <QTableWidgetItem>

namespace Ui {
class autoTestingDetails;
}

class autoTestingDetails : public QWidget
{
    Q_OBJECT

public:
    explicit autoTestingDetails(QWidget *parent = nullptr);
    ~autoTestingDetails();
    void fill(const QTableWidgetItem *item);
private:
    Ui::autoTestingDetails *ui;
};

#endif // AUTO_TESTING_DETAILS_H

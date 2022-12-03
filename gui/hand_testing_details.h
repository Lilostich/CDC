#ifndef HAND_TESTING_DETAILS_H
#define HAND_TESTING_DETAILS_H

#include <QWidget>
#include <QTableWidgetItem>

namespace Ui {
class HandTestingDetails;
}

class HandTestingDetails : public QWidget
{
    Q_OBJECT

public:
    explicit HandTestingDetails(QWidget *parent = nullptr);
    ~HandTestingDetails();
    void fill(const QTableWidgetItem *item);
private:
    Ui::HandTestingDetails *ui;
};

#endif // HAND_TESTING_DETAILS_H

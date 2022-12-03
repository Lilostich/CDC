#ifndef ADMINING_DETAILS_H
#define ADMINING_DETAILS_H

#include <QWidget>
#include  <QTableWidgetItem>

namespace Ui {
class adminingDetails;
}

class adminingDetails : public QWidget
{
    Q_OBJECT

public:
    explicit adminingDetails(QWidget *parent = nullptr);
    ~adminingDetails();
    void fill(const QTableWidgetItem *item);
private:
    Ui::adminingDetails *ui;
};

#endif // ADMINING_DETAILS_H

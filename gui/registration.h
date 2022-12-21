#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QCloseEvent>
#include <QErrorMessage>

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    void clear_fields();
    ~Registration();
signals:
    void close_me();

private slots:
    void on_but_reg_clicked();

    void on_but_cancel_clicked();

private:
    Ui::Registration *ui;
    QErrorMessage msg;

protected:
    void closeEvent ( QCloseEvent * e );

};

#endif // REGISTRATION_H

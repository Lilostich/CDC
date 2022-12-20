#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();
signals:
    void close_me();

private slots:
    void on_but_reg_clicked();

    void on_but_cancel_clicked();

private:
    Ui::Registration *ui;

protected:
    void closeEvent ( QCloseEvent * e );

};

#endif // REGISTRATION_H

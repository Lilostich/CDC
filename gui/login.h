#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "registration.h"
#include "change_password.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
signals:
    void successEnter();

private slots:
    void show_me();
    void on_button_regestration_clicked();

    void on_button_enter_clicked();

    void on_button_change_password_clicked();

private:
    Ui::Login *ui;
    Registration *registration;
    ChangePassword *changing;
};

#endif // LOGIN_H

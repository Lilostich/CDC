#ifndef CHANGE_PASSWORD_H
#define CHANGE_PASSWORD_H

#include <QWidget>

namespace Ui {
class ChangePassword;
}

class ChangePassword : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePassword(QWidget *parent = nullptr);
    ~ChangePassword();

signals:
    void close_me();

private slots:
    void on_but_apply_clicked();

    void on_but_cancel_clicked();

private:
    Ui::ChangePassword *ui;

protected:
    void closeEvent(QCloseEvent *e);
};

#endif // CHANGE_PASSWORD_H

#ifndef SEND_FORM_H
#define SEND_FORM_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class send_form;
}

class send_form : public QWidget
{
    Q_OBJECT

signals:
    void close_me();

public:
    explicit send_form(QWidget *parent = nullptr);
    ~send_form();

protected:
    void closeEvent(QCloseEvent *e){
        close_me();
        e->ignore();
    }

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::send_form *ui;
};

#endif // SEND_FORM_H

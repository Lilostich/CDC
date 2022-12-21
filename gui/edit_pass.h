#ifndef EDIT_PASS_H
#define EDIT_PASS_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class edit_pass;
}

class edit_pass : public QWidget
{
    Q_OBJECT

public:
    explicit edit_pass(QWidget *parent = nullptr);
    ~edit_pass();

signals:
    void close_me();

protected:
    void closeEvent(QCloseEvent *e){
        close_me();
        e->ignore();
    }

private slots:
    void on_cancel_clicked();

    void on_save_clicked();

private:
    Ui::edit_pass *ui;
};

#endif // EDIT_PASS_H

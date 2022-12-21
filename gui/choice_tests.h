#ifndef CHOICE_TESTS_H
#define CHOICE_TESTS_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class Choice_tests;
}

class Choice_tests : public QWidget
{
    Q_OBJECT

public:
    explicit Choice_tests(QWidget *parent = nullptr);
    ~Choice_tests();

signals:
    void close_me();

protected:
    void closeEvent(QCloseEvent *e){
        close_me();
        e->ignore();
    }


private slots:
    void on_cancel_clicked();

    void on_apply_clicked();

private:
    Ui::Choice_tests *ui;
};

#endif // CHOICE_TESTS_H

#ifndef EDIT_TESTS_RUN_AND_LIST_H
#define EDIT_TESTS_RUN_AND_LIST_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class edit_tests_run_and_list;
}

class edit_tests_run_and_list : public QWidget
{
    Q_OBJECT

public:
    explicit edit_tests_run_and_list(QWidget *parent = nullptr);
    ~edit_tests_run_and_list();
    void list_variant();
    void run_variant();
signals:
    void close_me();

protected:
    void closeEvent(QCloseEvent *e) {
        printf("Закртие редактирования\n");
        close_me();
        e->ignore();
    }

private slots:
    void on_delete_2_clicked();

    void on_create_clicked();

    void on_plus_clicked();

private:
    Ui::edit_tests_run_and_list *ui;
    bool isItList;
};

#endif // EDIT_TESTS_RUN_AND_LIST_H

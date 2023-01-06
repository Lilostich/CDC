#ifndef EDIT_TEST_CASE_H
#define EDIT_TEST_CASE_H

#include <QWidget>
#include <QCloseEvent>
#include "core/file_manager.h"

namespace Ui {
class Edit_test_case;
}

class Edit_test_case : public QWidget
{
    Q_OBJECT

public:
    explicit Edit_test_case(QWidget *parent = nullptr);
    ~Edit_test_case();
    void fill(QString);

signals:
    void close_me();

private:
    Ui::Edit_test_case *ui;

protected:
    void closeEvent(QCloseEvent *e);
private slots:
    void on_end_testing_clicked();
    void on_delete_2_clicked();
    void on_save_clicked();



};

#endif // EDIT_TEST_CASE_H

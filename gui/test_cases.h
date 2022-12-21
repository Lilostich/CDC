#ifndef TEST_CASES_H
#define TEST_CASES_H

#include <QWidget>
#include "gui/choice_tests.h"

namespace Ui {
class TestCases;
}

class TestCases : public QWidget
{
    Q_OBJECT

public:
    explicit TestCases(QWidget *parent = nullptr);
    ~TestCases();

private slots:
    void on_chose_test_runs_clicked();

    void on_chose_list_clicked();
    void close_slot();
private:
    Ui::TestCases *ui;
    Choice_tests *choice_form;
};

#endif // TEST_CASES_H

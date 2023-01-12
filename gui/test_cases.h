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
    void fillTable();
    void updateCombo();
private slots:
    void on_chose_test_runs_clicked();

    void on_chose_list_clicked();
    void close_slot();
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void fill_table_values(const QString run_name);
    void on_hand_test_clicked();

    void on_auto_test_clicked();

    void on_end_testing_clicked();

    void on_tableWidget_cellActivated(int row, int column);

    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::TestCases *ui;
    Choice_tests *choice_form;
    QString active_test;
    QString role;
};

#endif // TEST_CASES_H

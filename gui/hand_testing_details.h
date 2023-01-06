#ifndef HAND_TESTING_DETAILS_H
#define HAND_TESTING_DETAILS_H

#include <QWidget>
#include <QTableWidgetItem>
#include "gui/edit_test_case.h"
#include "gui/edit_tests_run_and_list.h"

namespace Ui {
class HandTestingDetails;
}

class HandTestingDetails : public QWidget
{
    Q_OBJECT

public:
    explicit HandTestingDetails(QWidget *parent = nullptr);
    ~HandTestingDetails();
    void fill(const QTableWidgetItem *item);

private slots:
    // Кнопка "Добавить тест"
    void on_save_button_clicked();
    // Кнопка "Редактировать тест ран"
    void on_pushButton_2_clicked();
    // Кнопка "Редактировать тест набор"
    void on_pushButton_3_clicked();
    // Кнопка "Редактировать тест"
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);
    // Смена в комбобоксе активной позиции (перечисление тестов)
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void close_slot();

private:
    Ui::HandTestingDetails *ui;
    Edit_test_case *edit_form;
    edit_tests_run_and_list *list_and_run_form;
    int add_mode;
protected:

};

#endif // HAND_TESTING_DETAILS_H

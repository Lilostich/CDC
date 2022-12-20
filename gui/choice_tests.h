#ifndef CHOICE_TESTS_H
#define CHOICE_TESTS_H

#include <QWidget>

namespace Ui {
class Choice_tests;
}

class Choice_tests : public QWidget
{
    Q_OBJECT

public:
    explicit Choice_tests(QWidget *parent = nullptr);
    ~Choice_tests();

private:
    Ui::Choice_tests *ui;
};

#endif // CHOICE_TESTS_H

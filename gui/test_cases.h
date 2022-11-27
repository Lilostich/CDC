#ifndef TEST_CASES_H
#define TEST_CASES_H

#include <QWidget>

namespace Ui {
class TestCases;
}

class TestCases : public QWidget
{
    Q_OBJECT

public:
    explicit TestCases(QWidget *parent = nullptr);
    ~TestCases();

private:
    Ui::TestCases *ui;
};

#endif // TEST_CASES_H

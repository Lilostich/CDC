#ifndef ADDING_FORM_H
#define ADDING_FORM_H

// TODO Выпилить из проекта

#include <QWidget>

namespace Ui {
class AddingForm;
}

class AddingForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddingForm(QWidget *parent = nullptr);
    ~AddingForm();

private:
    Ui::AddingForm *ui;
};

#endif // ADDING_FORM_H

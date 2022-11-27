#include "adding_form.h"
#include "ui_adding_form.h"

AddingForm::AddingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddingForm)
{
    ui->setupUi(this);
}

AddingForm::~AddingForm()
{
    delete ui;
}

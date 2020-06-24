#include "linedialog.h"
#include "ui_linedialog.h"
#include <vector>

LineDialog::LineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LineDialog)
{
    ui->setupUi(this);
}

LineDialog::~LineDialog()
{
    delete ui;
}

void LineDialog::on_SubmitBtn_clicked()
{
    this->close();
}
int LineDialog::getNum(){
    return ui->lineEdit->text().toInt();
}

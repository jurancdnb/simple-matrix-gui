#include "elementlog.h"
#include "ui_elementlog.h"
#include "matrix.h"
ElementLog::ElementLog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ElementLog)
{
    ui->setupUi(this);
}

ElementLog::~ElementLog()
{
    delete ui;
}

void ElementLog::on_SubmitBtn_clicked()
{
    this->close();
}
int ElementLog::getRowinput()
{
    int s = ui->RowNum->text().toInt();
    return s;
}
int ElementLog::getColinput()
{
    int s = ui->ColNum->text().toInt();
    return s;
}
double ElementLog::getEleinput()
{
    std::string s = ui->ValNum->text().toStdString();
    double num=std::stod(s);
    return num;
}



#include "loginlog.h"
#include "ui_loginlog.h"

Loginlog::Loginlog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Loginlog)
{
    ui->setupUi(this);
}

Loginlog::~Loginlog()
{
    delete ui;
}

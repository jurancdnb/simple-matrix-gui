#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_LoginBtn_clicked()
{
    if(ui->lineEdit->text()==tr("cdnb") && ui->lineEdit_2->text()==tr("xznb")){
            accept();
    }
    else{
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error"),QMessageBox::Yes);
    }
}

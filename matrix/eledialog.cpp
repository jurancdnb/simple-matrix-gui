#include "eledialog.h"
#include "ui_eledialog.h"

EleDialog::EleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EleDialog)
{
    ui->setupUi(this);
}

EleDialog::~EleDialog()
{
    delete ui;
}

void EleDialog::on_pushButton_clicked()
{
    this->close();
}

int EleDialog::getRowinput()
{
    int s = ui->RowEdit->text().toInt();
    return s;
}
int EleDialog::getColinput()
{
    int s=ui->ColEdit->text().toInt();
    return s;
}

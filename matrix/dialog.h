#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "matrix.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Matrix matrix;
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_SubmitBtn_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

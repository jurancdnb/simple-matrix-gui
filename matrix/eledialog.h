#ifndef ELEDIALOG_H
#define ELEDIALOG_H

#include <QDialog>

namespace Ui {
class EleDialog;
}

class EleDialog : public QDialog
{
    Q_OBJECT

public:
    int getRowinput();
    int getColinput();
    explicit EleDialog(QWidget *parent = nullptr);
    ~EleDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::EleDialog *ui;
};

#endif // ELEDIALOG_H

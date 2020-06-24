#ifndef LINEDIALOG_H
#define LINEDIALOG_H

#include <QDialog>

namespace Ui {
class LineDialog;
}

class LineDialog : public QDialog
{
    Q_OBJECT

public:
    int getNum();
    explicit LineDialog(QWidget *parent = nullptr);
    ~LineDialog();

private slots:
    void on_SubmitBtn_clicked();

private:
    Ui::LineDialog *ui;
};

#endif // LINEDIALOG_H

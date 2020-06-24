#ifndef ELEMENTLOG_H
#define ELEMENTLOG_H

#include <QDialog>

namespace Ui {
class ElementLog;
}

class ElementLog : public QDialog
{
    Q_OBJECT

public:
    explicit ElementLog(QWidget *parent = nullptr);
    ~ElementLog();
    int getRowinput();
    int getColinput();
    double getEleinput();

private slots:
    void on_SubmitBtn_clicked();

private:
    Ui::ElementLog *ui;
};

#endif // ELEMENTLOG_H

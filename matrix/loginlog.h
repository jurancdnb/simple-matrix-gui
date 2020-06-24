#ifndef LOGINLOG_H
#define LOGINLOG_H

#include <QDialog>

namespace Ui {
class Loginlog;
}

class Loginlog : public QDialog
{
    Q_OBJECT

public:
    explicit Loginlog(QWidget *parent = nullptr);
    ~Loginlog();

private:
    Ui::Loginlog *ui;
};

#endif // LOGINLOG_H

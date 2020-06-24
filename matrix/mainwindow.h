#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <matrix.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Matrix mat;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_CreateBtn_clicked();

    void on_DisplayBtn_clicked();

    void on_pushButton_clicked();

    void on_InverseBtn_clicked();

    void on_pushButton_2_clicked();

    void on_MinusBtn_clicked();

    void on_MultBtn_clicked();

    void on_Ele_ChangeBtn_clicked();

    void on_pushButton_3_clicked();

    void on_colSelectBtn_clicked();

    void on_ShowEleBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "elementlog.h"
#include "linedialog.h"
#include "eledialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_CreateBtn_clicked()
{
    Dialog *dlg=new Dialog;
    dlg->setWindowTitle("新建矩阵");
    dlg->exec();
    this->mat=dlg->matrix;
}

void MainWindow::on_DisplayBtn_clicked()
{
    string s=this->mat.to_string();
    QString matText=QString::fromStdString(s);
    ui->textBrowser->setText(matText);
    ui->textBrowser->show();
}

void MainWindow::on_pushButton_clicked()
{
    this->mat.Transpose();
    string s=this->mat.to_string();
    cout<<s<<endl;
    QString matText=QString::fromStdString(s);
    ui->textBrowser->setText(matText);
    ui->textBrowser->show();
}

void MainWindow::on_InverseBtn_clicked()
{
    double **a=this->mat.inverse();
    string s;
    if(a==NULL){
        s="not a square matrix";
    }
    else{
        s=this->mat.to_string(a);
    }
    QString matText=QString::fromStdString(s);
    ui->textBrowser->setText(matText);
    ui->textBrowser->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog *dlg=new Dialog;
    dlg->setWindowTitle("矩阵输入");
    dlg->exec();
    double **a=this->mat.add(this->mat,dlg->matrix);
    string s;
    if(a==NULL){
        s="the sizes of two matrixs are not equal";
    }
    else{
        s=this->mat.to_string(a);
    }
    QString matText=QString::fromStdString(s);
    ui->textBrowser->setText(matText);
    ui->textBrowser->show();
}

void MainWindow::on_MinusBtn_clicked()
{
    Dialog *dlg=new Dialog;
    dlg->setWindowTitle("矩阵输入");
    dlg->exec();
    double **a=this->mat.minus(this->mat,dlg->matrix);
    string s;
    if(a==NULL){
        s="the sizes of two matrixs are not equal";
    }
    else{
        s=this->mat.to_string(a);
    }
    QString matText=QString::fromStdString(s);
    ui->textBrowser->setText(matText);
    ui->textBrowser->show();

}

void MainWindow::on_MultBtn_clicked()
{
    Dialog *dlg=new Dialog;
    dlg->setWindowTitle("矩阵输入");
    dlg->exec();
    double **a=this->mat.multiple(this->mat,dlg->matrix);
    string s;
    if(a==NULL){
        s="Can't multiple mat1 with mat2,beacuase the length of mat1 is not equal to the width of mat2";
    }
    else{
        s=this->mat.to_string(this->mat.row,dlg->matrix.column,a);
    }
    QString matText=QString::fromStdString(s);
    ui->textBrowser->setText(matText);
    ui->textBrowser->show();
}

void MainWindow::on_Ele_ChangeBtn_clicked()
{
    ElementLog *dlg=new ElementLog;
    dlg->setWindowTitle("参数输入");
    dlg->exec();
    int row=dlg->getRowinput();
    int col=dlg->getColinput();
    int num=dlg->getEleinput();
    bool flag=this->mat.SetElement(row,col,num);
    if(flag){
        string s=this->mat.to_string();
        QString matText=QString::fromStdString(s);
        ui->textBrowser->setText(matText);
        ui->textBrowser->show();
    }
    else{
        string s="index out of range";
        QString matText=QString::fromStdString(s);
        ui->textBrowser->setText(matText);
        ui->textBrowser->show();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    LineDialog *dlg=new LineDialog;
    dlg->setWindowTitle("参数输入");
    dlg->exec();
    int row=dlg->getNum();
    string s=this->mat.getRow(row);
    QString matText=QString::fromStdString(s);
    ui->textBrowser->setText(matText);
    ui->textBrowser->show();
}

void MainWindow::on_colSelectBtn_clicked()
{
    LineDialog *dlg=new LineDialog;
    dlg->setWindowTitle("参数输入");
    dlg->exec();
    int col=dlg->getNum();
    string s=this->mat.getCol(col);
    QString matText=QString::fromStdString(s);
    ui->textBrowser->setText(matText);
    ui->textBrowser->show();
}

void MainWindow::on_ShowEleBtn_clicked()
{
    EleDialog *dlg=new EleDialog;
    dlg->setWindowTitle("参数输入");
    dlg->exec();
    int row=dlg->getRowinput();
    int col=dlg->getColinput();
    string s=this->mat.getElement(row,col);
    QString matText=QString::fromStdString(s);
    ui->textBrowser->setText(matText);
    ui->textBrowser->show();
}


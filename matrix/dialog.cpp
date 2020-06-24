#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <string>
#include <regex>
#include "matrix.h"
using namespace std;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_SubmitBtn_clicked()
{
    int row=ui->RowEdit->text().toInt();        //获取行数
    int col=ui->ColEdit->text().toInt();        //获取列数
    QString matrix=ui->MatEdit->toPlainText();  //获取输入文本
    string s=matrix.toStdString();
    double **mat=new double*;
    std::regex p("\\s");
    std::regex q("\\n");
    std::smatch m;
    std::regex_replace(s,p," ");                //去除文本中换行符
    //根据空格位置进行分词
    std::sregex_token_iterator pos(s.begin(), s.end(), p, -1);
    decltype(pos) end;
    for(int i=0;i<row;i++){                     //初始化矩阵
        mat[i]=new double[col];
        for(int j=0;j<col;j++){
            mat[i][j]=stod((pos++)->str());
        }
    }
    this->matrix=Matrix(row,col,mat);
    this->close();
}

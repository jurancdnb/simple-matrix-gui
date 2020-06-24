#include <iostream>
#include <regex>
#include <string>
#include <assert.h>
#include <limits>
#include "matrix.h"
using namespace std;
Matrix::Matrix(){                           //无参数构造Matrix类对象
    row=0;
    column=0;
    matrix=NULL;
}
Matrix::Matrix(int r,int c,double **mat){   //通过输入行列数及矩阵内具体元素值进行对象构造
    row=r;
    column=c;
    matrix=new double*;
    for(int i=0;i<r;i++){                   //通过循环设置矩阵元素
        matrix[i]=new double[c];
        for(int j=0;j<c;j++){
            matrix[i][j]=mat[i][j];
        }
    }
}
//在控制台输出矩阵元素
void Matrix::Display(int row,int column,double **mat){
    int i=0,j=0;
    for(i=0;i<row;i++){                     //循环输出矩阵内元素
        for(j=0;j<column;j++){
            cout<<mat[i][j]<<' ';
        }
        cout<<endl;
    }
}
//返回矩阵mat1与矩阵mat2相加后的结果矩阵
double** Matrix::add(Matrix mat1,Matrix mat2){
    //判断两矩阵大小是否相同
    if(mat1.row!=mat2.row || mat1.column!=mat2.column){
        cout<<"the sizes of two matrixs are not equal"<<endl;
        return NULL;
    }
    double **array=new double*;             //创建空二维double型数组用于记录相加后的结果
    for(int i=0;i<mat1.row;i++){            //循环完成相加操作
        array[i]=new double[mat1.column];
        for(int j=0;j<mat1.column;j++){
            array[i][j]=mat1.matrix[i][j]+mat2.matrix[i][j];
        }
    }
    //mat1.Display(mat1.row,mat1.column,array);
    return array;
}
//返回矩阵mat1与矩阵mat2相减后的结果矩阵
double** Matrix::minus(Matrix mat1,Matrix mat2){
    //判断两矩阵大小是否相同
    if(mat1.row!=mat2.row || mat1.column!=mat2.column){
        cout<<"the sizes of two matrixs are not equal"<<endl;
        return NULL;
    }
    double **array=new double*;             //创建空二维double型数组用于记录相减后的结果
    for(int i=0;i<mat1.row;i++){            //循环完成相减操作
        array[i]=new double[mat1.column];
        for(int j=0;j<mat1.column;j++){
            array[i][j]=mat1.matrix[i][j]-mat2.matrix[i][j];
        }
    }
    //mat1.Display(mat1.row,mat1.column,array);
    return array;
}
//返回矩阵mat1与矩阵mat2相乘后的结果矩阵
double** Matrix::multiple(Matrix mat1,Matrix mat2){
    //判断矩阵mat1的列数是否与矩阵mat2的行数
    if(mat1.column!=mat2.row){
        cout<<"Can't multiple mat1 with mat2"<<endl;
        return NULL;
    }
    double **array=new double*;             //创建空二维double型数组用于记录相乘后的结果
    for(int i=0;i<mat1.row;i++){            //循环完成相乘操作
        array[i]=new double[mat2.column];
        for(int j=0;j<mat2.column;j++){
            int sum=0;
            for(int k=0;k<mat1.column;k++){
                sum+=mat1.matrix[i][k]*mat2.matrix[k][j];
            }
            array[i][j]=sum;
        }
    }
    //mat1.Display(mat1.row,mat2.column,array);
    return array;
}
//对矩阵进行转置
void Matrix::Transpose(){
    double array[column][row];              //创建空二维double型数组用于记录转置后数据
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            array[j][i]=matrix[i][j];
        }
    }
    delete matrix;
    int temp=0;                             //交换行、列数
    temp=this->row;
    this->row=this->column;
    this->column=temp;
    cout<<row<<" "<<column<<endl;
    matrix=new double*;
    for(int i=0;i<row;i++){                 //对对象内矩阵值进行更改
        matrix[i]=new double[column];
        for(int j=0;j<column;j++){
            matrix[i][j]=array[i][j];
        }
    }
    //this->Display(row,column,matrix);
}
//利用LUP分解法对矩阵进行分解，作为矩阵求逆的辅助函数
void Matrix::LUP_Decomposition(int *P[],double *L[],double *U[]){
    int n=this->row;                        //记录矩阵阶数
    int *position=new int[n];
    for(int i=0;i<n;i++){
        position[i]=i;
    }
    double **A=new double*;
    for(int i = 0;i < n;i++){               //拷贝矩阵
        A[i]=new double[n];
        for(int j= 0;j < n;j++){
            A[i][j]=this->matrix[i][j];
        }
    }
    for(int k=0;k<n;k++){                   //选取从第k行k列下的最大元素
        double max_row_element=-99999;
        int max_row_index=k;
        for(int i=k;i<n;i++){
            if(abs(A[i][k])>max_row_element){
                max_row_element=abs(A[i][k]);
                max_row_index=i;
            }
        }
        if(max_row_element==0){             //判断矩阵是否满秩
            cout<<"singular matrix"<<endl;
            return;
        }
        int tmp=0;
        tmp=position[k];
        position[k]=position[max_row_index];//记录最大元素下标
        position[max_row_index]=tmp;
        for(int i=0;i<n;i++){               //高斯消元法
            double tmp;
            tmp=A[k][i];
            A[k][i]=A[max_row_index][i];
            A[max_row_index][i]=tmp;
        }
        for(int i=k+1;i<n;i++){
            A[i][k]/=A[k][k];
            for(int j=k+1;j<n;j++){
                A[i][j]-=A[i][k]*A[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==position[i]){
                P[i][j]=1;
            }
            else{
                P[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                L[i][j]=1;
            }
            else if(i>j){
                L[i][j]=A[i][j];
            }
            else{
                L[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<=j){
                U[i][j]=A[i][j];
            }
            else{
                U[i][j]=0;
            }
        }
    }
}
//利用LUP分解法对逆矩阵分列求解,求出AX=E的每一个解向量
double* Matrix::LUP_Solve(double *L[],double *U[],int *position,double *b){
    int n=this->row;
    double *x=new double[n];
    double *y=new double[n];
    for(int i=0;i<n;i++){
        double partial_sum=0;
        for(int j=0;j<i;j++){
            partial_sum+=L[i][j]*y[j];
        }
        y[i]=b[position[i]]-partial_sum;
    }
    for(int i=n-1;i>=0;i--){
        double partial_sum=0;
        for(int j=i+1;j<n;j++){
            partial_sum+=U[i][j]*x[j];
        }
        x[i]=(y[i]-partial_sum)/U[i][i];
    }
    return x;
}
//对矩阵进行求逆
double** Matrix::inverse(){
    //判断矩阵行列数是否相同
    if(row!=column){
        cout<<"Not a square matrix"<<endl;
        return NULL;
    }
    int n=row;
    double **L=new double*;     //初始化LUP辅助矩阵
    double **U=new double*;
    double **A_i=new double*;
    int **P=new int*;
    for(int i=0;i<n;i++){
        L[i]=new double[n];
        U[i]=new double[n];
        A_i[i]=new double[n];
        P[i]=new int[n];
    }
    int *position=new int[n];
    LUP_Decomposition(P,L,U);   //LUP分解

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(P[i][j]==1){
                position[i]=j;
            }
        }
    }

    double **E=new double*;     //单位矩阵为解
    for(int i=0;i<n;i++){
        E[i]=new double[n];
        for(int j=0;j<n;j++){
            if(i==j){
                E[i][j]=1;
            }
            else{
                E[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        double *x=NULL;
        x=LUP_Solve(L,U,position,E[i]);
        for(int j=0;j<n;j++){
            A_i[j][i]=x[j];
        }
    }
    Display(n,n,A_i);
    delete L;
    delete U;
    delete P;
    return A_i;
}
//按照指定精度保留小数将double型转换为string型
std::string DoubleToString(const double value, unsigned int precisionAfterPoint){
    std::ostringstream out;
    // 清除默认精度
    out.precision(std::numeric_limits<double>::digits10);
    out << value;

    std::string res = std::move(out.str());
    auto pos = res.find('.');
    if (pos == std::string::npos)
        return res;

    auto splitLen = pos + 1 + precisionAfterPoint;
    if (res.size() <= splitLen)
        return res;

    return res.substr(0, splitLen);
}
//将矩阵内元素转换成字符串形式，便于在GUI显示
std::string Matrix::to_string(){
    string res="";
    for(int i=0;i<this->row;i++){
        for(int j=0;j<this->column;j++){
            res=res+DoubleToString(this->matrix[i][j],2)+" ";
        }
        res+="\n";
    }
    return res;
}
//将double型二维数组转换为字符串形式，便于在GUI显示
std::string Matrix::to_string(double **a){
    string res="";
    for(int i=0;i<this->row;i++){
        for(int j=0;j<this->column;j++){
            res=res+DoubleToString(a[i][j],2)+" ";
        }
        res+="\n";
    }
    return res;
}
//将double型二维数组转换成字符串形式，便于在GUI显示
std::string Matrix::to_string(int row,int column,double **a){
    string res="";
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            res=res+DoubleToString(a[i][j],2)+" ";
        }
        res+="\n";
    }
    return res;
}
//将第row行第col列的元素赋值为val
bool Matrix::SetElement(int Row,int col,double val){
    if((Row>row || col>column) ||(Row<0 || col<0)){
        return false;
    }
    Row-=1;
    col-=1;
    this->matrix[Row][col]=val;
    return true;
}
//将第row行第col列的元素取出
std::string Matrix::getElement(int Row,int col){
    if((Row>row || col>column) ||(Row<0 || col<0)){
        return "index out of range";
    }
    Row-=1;
    col-=1;
    string s=DoubleToString(matrix[Row][col],2);
    return s;
}
//获取对应行的所有元素并以字符串形式返回
std::string Matrix::getRow(int Row){
    if(Row>row || Row<0){
        return "index out of range";
    }
    Row=Row-1;
    string res;
    for(int j=0;j<this->column;j++){
        res=res+DoubleToString(this->matrix[Row][j],2)+" ";
    }
    return res;
}
//获取对应列的所有元素并以字符串形式返回
std::string Matrix::getCol(int col){
    if(col>column || col<0){
        return "index out of range";
    }
    col=col-1;
    string res;
    for(int i=0;i<this->row;i++){
        res=res+DoubleToString(this->matrix[i][col],2)+"\n";
    }
    return res;
}

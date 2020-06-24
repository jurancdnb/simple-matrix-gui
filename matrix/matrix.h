#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;
//按照指定精度保留小数将double型转换为string型
std::string DoubleToString(const double value, unsigned int precisionAfterPoint);
class Matrix{
    public:
        int row;
        int column;
        double **matrix;
        Matrix();                                       //无参数构造函数
        Matrix(int row,int column,double **mat);        //通过输入行列数及矩阵内具体元素值进行对象构造
        void Display(int row,int column,double **mat);  //在控制台输出矩阵元素
        double** add(Matrix mat1,Matrix mat2);          //返回矩阵mat1与矩阵mat2相加后的结果矩阵
        double** minus(Matrix mat1,Matrix mat2);        //返回矩阵mat1与矩阵mat2相减后的结果矩阵
        double** multiple(Matrix mat1,Matrix mat2);     //返回矩阵mat1与矩阵mat2相乘后的结果矩阵
        void Transpose();                               //对矩阵进行转置
        double** inverse();                             //对矩阵进行求逆
        //利用LUP分解法对矩阵进行分解，作为矩阵求逆的辅助函数
        void LUP_Decomposition(int *P[],double *L[],double *U[]);
        //利用LUP分解法对逆矩阵分列求解
        double* LUP_Solve(double *L[],double *U[],int *position,double *b);
        std::string to_string();                        //将矩阵内元素转换成字符串形式，便于在GUI显示
        std::string to_string(double **a);              //将double型二维数组转换为字符串形式，便于在GUI显示
        //将double型二维数组转换成字符串形式，便于在GUI显示
        std::string to_string(int row,int column,double **a);
        bool SetElement(int Row,int col,double val);    //将第row行第col列的元素赋值为val
        std::string getElement(int Row,int col);        //将第row行第col列的元素取出
        std::string getRow(int Row);                    //获取对应行的所有元素并以字符串形式返回
        std::string getCol(int col);                    //获取对应列的所有元素并以字符串形式返回
};
#endif // MATRIX_H

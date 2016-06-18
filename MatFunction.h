//
//  MatFunction.h
//  calcu
//
//  Created by 缪晴朗 on 16/6/13.
//  Copyright © 2016年 缪晴朗. All rights reserved.
//

#ifndef MatFunction_h
#define MatFunction_h

#include <stdio.h>
#include "matrix.h"

Matrix RAND(int row, int column);
//定义一个名为“MatName”的N*M的随机矩阵，矩阵中每个元素为一个[0,1]的随机数。
Matrix EYE(int number);//定义一个名为“MatName”的N*N的零矩阵。
Matrix ZEROS(int row, int colum);//定义一个名为“MatName”的N*N的单位矩阵


//用于逗号与分号的处理 分别为向右整合矩阵与向下整合矩阵
Matrix MIXRIGHT(Matrix left,Matrix right);
Matrix MIXDOWN(Matrix up,Matrix down);

//二类函数 以函数名打头
Matrix MULTIPLY(Matrix one,Matrix two);
Matrix DIVISION(Matrix one,Matrix two);
Matrix MULTIPLY_N(Matrix one,double two);
Matrix DIVISION_N(Matrix one,double two);//one divise two
Matrix PLUS(Matrix one,Matrix two);
Matrix SUB(Matrix one,Matrix two);

double SUM(Matrix MatA);
double MAX(Matrix MatA);
double MIN(Matrix MatA);

Matrix ROUND(Matrix MatA);
Matrix UPPER(Matrix MatA);
Matrix LOWER(Matrix MatA);


double DET(Matrix MatA);//计算方阵的行列式


double RANK(Matrix MatA);//计算矩阵的秩


Matrix POWER(Matrix MatA,int k);//计算n次幂
Matrix TURN(Matrix MatA);//转置矩阵
Matrix RREF_Trape(Matrix MatA);//通过列主元消去法 化为阶梯性矩阵
Matrix RREF(Matrix MatA);//化为行最简型

Matrix COLON_1(int start,int end); //冒号
Matrix COLON_2(int start,int step,int end);

Matrix COFACTOR(Matrix MatA,int x,int y);//求出矩阵余子式
Matrix ADJOINT(Matrix MatA);//求出矩阵的伴随矩阵
Matrix REVERSE(Matrix MatA);//求出矩阵的逆
#endif /* MatFunction_h */

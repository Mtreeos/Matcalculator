//
//  MatFunction.c
//  calcu
//
//  Created by 缪晴朗 on 16/6/13.
//  Copyright © 2016年 缪晴朗. All rights reserved.
//

#include "MatFunction.h"
#include "matrix.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

Matrix RAND(int row, int column){
    Matrix node;
    int i;int j;
    srand((unsigned) time(NULL));
    node.row = row;
    node.column = column;
    
    node.mat = (double **)malloc(row*sizeof(double*));
    for(i = 0;i < row;i++) node.mat[i] = (double*)malloc(column*sizeof(double));
    
    node.next = NULL;
    for(i = 0;i<row;i++)
        for(j = 0;j < column;j++){
            node.mat[i][j] = (double)rand()/RAND_MAX;
        }
    return node;
}

Matrix EYE(int number){
    Matrix node;
    int i;int j;
    srand((unsigned) time(NULL));
    node.row = number;
    node.column = number;
    
    node.mat = (double **)malloc(number*sizeof(double*));
    for(i = 0;i<number;i++) node.mat[i] = (double*)malloc(number*sizeof(double));
    
    node.next = NULL;
    for(i = 0;i<number;i++)
        for(j = 0;j < number;j++){
            if(i == j) node.mat[i][j] = 1;
            else node.mat[i][j] = 0;
        }
    return node;
}
Matrix ZEROS(int row, int column){
    Matrix node;
    int i;int j;
    srand((unsigned) time(NULL));
    node.row = row;
    node.column = column;
    
    node.mat = (double **)malloc(row*sizeof(double*));
    for(i = 0;i < row ;i++) node.mat[i] = (double*)malloc(column*sizeof(double));
    
    node.next = NULL;
    for(i = 0;i<row;i++)
        for(j = 0;j < column;j++){
            node.mat[i][j] = 0;
        }
    return node;
}
Matrix MIXRIGHT(Matrix left,Matrix right){
    Matrix result;
    int i,x,y,row;
    if(left.row==right.row){
        row = left.row;
        result.column = left.column + right.column;
        result.row = row;
        
        result.mat = (double **)malloc(row*sizeof(double*));
        for(i = 0;i < row;i++)
            result.mat[i] = (double*)malloc(result.column*sizeof(double));
        
        
        for(y = 0;y< row;y++){
            for(x = 0;x< left.column;x++)
                result.mat[y][x] = left.mat[y][x];
            for(x = left.column;x<result.column;x++)
                result.mat[y][x] = right.mat[y][x-left.column];
        }
    }
    //else(报错)
    return result;
}
Matrix MIXDOWN(Matrix up,Matrix down){
    Matrix result;
    int i,x,y;
    
    if(up.column == down.column){
        result.row = up.row + down.row;
        result.column = up.column;
        
        result.mat = (double **)malloc(result.row*sizeof(double*));
        for(i = 0;i<result.row;i++)
            result.mat[i] = (double*)malloc(result.column*sizeof(double));
        
        for(x = 0;x < result.column;x++){
            for(y = 0; y<up.row ; y++)
                result.mat[y][x] = up.mat[y][x];
            for(y = up.row ; y<result.row ; y++)
                result.mat[y][x] = down.mat[y-up.row][x];
        }
        
    }
    //else 报错
    return result;
}

Matrix DIVISION(Matrix one,Matrix two){
    Matrix temp;
    
    temp = MULTIPLY(one, REVERSE(two));
    
    return temp;
}

Matrix MULTIPLY(Matrix one,Matrix two){
    Matrix temp;
    temp.row = one.row;
    temp.column = two.column;
    int i,x,y;
    
    temp.mat = (double**)malloc(sizeof(double*)*temp.row);
    for(i = 0;i<temp.row;i++) temp.mat[i] = malloc(sizeof(double)*temp.column);
    
    if(one.column == two.row){
        int k = one.column;
        for(y = 0;y<temp.row;y++)
            for(x = 0;x<temp.column;x++)
            {
                for(i=0;i<k;i++)
                    temp.mat[y][x] += one.mat[y][i]*two.mat[i][x];
            }
    }
    return temp;
    //else wrong
}

Matrix MULTIPLY_N(Matrix one,double two){
    Matrix temp;
    temp.row = one.row;
    temp.column = one.column;
    int i,x,y;
    
    temp.mat = (double**)malloc(sizeof(double*)*temp.row);
    for(i = 0;i<temp.row;i++) temp.mat[i] = malloc(sizeof(double)*temp.column);
    
    for(y = 0;y<temp.row;y++)
        for(x = 0;x<temp.column;x++)
            temp.mat[y][x] = one.mat[y][x]*two;
    return temp;
}

Matrix DIVISION_N(Matrix one,double two){
    Matrix temp;
    temp.row = one.row;
    temp.column = one.column;
    int i,x,y;
    
    temp.mat = (double**)malloc(sizeof(double*)*temp.row);
    for(i = 0;i<temp.row;i++) temp.mat[i] = malloc(sizeof(double)*temp.column);
    
    for(y = 0;y<temp.row;y++)
        for(x = 0;x<temp.column;x++)
            temp.mat[y][x] = one.mat[y][x]/two;
    return temp;
}//one divise two

Matrix PLUS(Matrix one,Matrix two){
    Matrix temp;
    
    temp.row = one.row;
    temp.column = two.column;
    int i,x,y;
    
    temp.mat = (double**)malloc(sizeof(double*)*temp.row);
    for(i = 0;i<temp.row;i++) temp.mat[i] = malloc(sizeof(double)*temp.column);
    
    if(one.column == two.column&&one.row == two.row){
        for(y = 0;y<temp.row;y++)
            for(x = 0;x<temp.column;x++)
                temp.mat[y][x] = one.mat[y][x]+two.mat[y][x];
    }
    
    return temp;
}
Matrix SUB(Matrix one,Matrix two){
    Matrix temp;
    
    temp.row = one.row;
    temp.column = two.column;
    int i,x,y;
    
    temp.mat = (double**)malloc(sizeof(double*)*temp.row);
    for(i = 0;i<temp.row;i++) temp.mat[i] = malloc(sizeof(double)*temp.column);
    
    if(one.column == two.column&&one.row == two.row){
        for(y = 0;y<temp.row;y++)
            for(x = 0;x<temp.column;x++)
                temp.mat[y][x] = one.mat[y][x]-two.mat[y][x];
    }
    
    return temp;
}

double SUM(Matrix MatA){
    double total;
    int y;int x;
    
    for(y = 0;y<MatA.row;y++)
        for(x = 0;x<MatA.column;x++)
            total += MatA.mat[y][x];
    
    return total;
}

double MAX(Matrix MatA){
    double max;
    int y ; int x;
    max = MatA.mat[0][0];
    
    for(y = 0;y<MatA.row;y++)
        for(x = 0;x<MatA.column;x++)
            if(max < MatA.mat[y][x])
                max = MatA.mat[y][x];
    
    return  max;
}

double MIN(Matrix MatA){
    double min;
    int y ; int x;
    min = MatA.mat[0][0];
    
    for(y = 0;y<MatA.row;y++)
        for(x = 0;x<MatA.column;x++)
            if(min > MatA.mat[y][x])
                min = MatA.mat[y][x];
    
    return  min;
}

Matrix ROUND(Matrix MatA){
    Matrix temp;
    
    temp.row = MatA.row;
    temp.column = MatA.column;
    int i,x,y;
    
    temp.mat = (double**)malloc(sizeof(double*)*temp.row);
    for(i = 0;i<temp.row;i++) temp.mat[i] = malloc(sizeof(double)*temp.column);
    
    for(y = 0;y<temp.row;y++)
        for(x = 0;x<temp.column;x++)
            temp.mat[y][x] = round(MatA.mat[y][x]);
    
    return temp;
}
Matrix UPPER(Matrix MatA){
    Matrix temp;
    
    temp.row = MatA.row;
    temp.column = MatA.column;
    int i,x,y;
    
    temp.mat = (double**)malloc(sizeof(double*)*temp.row);
    for(i = 0;i<temp.row;i++) temp.mat[i] = malloc(sizeof(double)*temp.column);
    
    for(y = 0;y<temp.row;y++)
        for(x = 0;x<temp.column;x++)
            temp.mat[y][x] = ceil(MatA.mat[y][x]);
    
    return temp;
}
Matrix LOWER(Matrix MatA){
    Matrix temp;
    
    temp.row = MatA.row;
    temp.column = MatA.column;
    int i,x,y;
    
    temp.mat = (double**)malloc(sizeof(double*)*temp.row);
    for(i = 0;i<temp.row;i++) temp.mat[i] = malloc(sizeof(double)*temp.column);
    
    for(y = 0;y<temp.row;y++)
        for(x = 0;x<temp.column;x++)
            temp.mat[y][x] = floor(MatA.mat[y][x]);
    
    return temp;
}


Matrix POWER(Matrix MatA,int n);//次幂
Matrix TURN_ZZ(Matrix MatA);//转置矩阵

Matrix RREF_Trape(Matrix MatA){//化为阶梯性矩阵 若加上注释的代码 将会进行列主元的选择 防止a[k][k]过小时 对数值分析产生巨大影响
    Matrix temp;
//    Matrix TempVector;
    double m[BIG][BIG];
    
    temp.row = MatA.row;
    temp.column = MatA.column;
//    int t;
    int i,j,k,R,C;
//    double max;
    int y,x;
    
    R=MatA.row - 1;
    C=MatA.column -1;
    
    temp.mat = (double**)malloc(sizeof(double*)*temp.row);
    for(i = 0;i<temp.row;i++) temp.mat[i] = malloc(sizeof(double)*temp.column);
    
    for(y=0;y<=R;y++)
        for(x=0;x<=C;x++)
            temp.mat[y][x] = MatA.mat[y][x];//将原矩阵拷贝给temp
    
//    TempVector.row = 1;
//    TempVector.column = MatA.column;
//    
//    TempVector.mat = (double**)malloc(sizeof(double*)*TempVector.row);
//    for(i = 0;i<TempVector.row;i++)
//        TempVector.mat[i] = malloc(sizeof(double)*TempVector.column);
    
    for(k = 0;k<=R-1;k++){
        
        //加个判断 即此时第k列数值均为零
        
        if(temp.mat[k][k] == 0) continue;
        
        else{

//        max = temp.mat[k][k];
//        for(i=k;i<=R;i++){
//            if(max < temp.mat[i][k])
//                max = temp.mat[i][k];
//        }
//        for(i=k;i<=R;i++){
//            if(max == temp.mat[i][k])
//                break;
//        }
//        
//        //交换第i行与第k行 它们共有0->C列 t代表当前位置列数
//        for(t=0;t<=C;t++){
//            TempVector.mat[0][t]=temp.mat[k][t];
//            temp.mat[k][t] = temp.mat[i][t];
//            temp.mat[i][t] = TempVector.mat[0][t];
//        }
//        
        
        for(i = k+1;i <= R;i++){
            m[i][k] = temp.mat[i][k]/temp.mat[k][k];
            temp.mat[i][k] = 0;
            for(j = k+1;j <= C;j++)
                temp.mat[i][j] -= m[i][k]*temp.mat[k][j];
        }
        }
    }
    return temp;
};

Matrix RREF(Matrix MatA){//化为行最简型
    Matrix temp;
    int i,k,t;
    temp =RREF_Trape(MatA);
    double m = 0;
    
    for(i = 0;i < temp.row;i++){
        for (k = 0; k<temp.column ;k++ ) {
            if(temp.mat[i][k]!=0)
            {   m = temp.mat[i][k];
                for(t = k;t < temp.column;t++)
                    temp.mat[i][t] /= m;
                break;
            }
        }
    }
    return temp;
}

double DET(Matrix MatA){//行列式
    Matrix temp;
    int i,k;
    double result = 1;
    temp = RREF_Trape(MatA);
    
    k = temp.row;
    for(i = 0;i < k;i++)
            result *= temp.mat[i][i];
    return result;
}

Matrix COFACTOR(Matrix MatA,int ROW,int COLUMN){
    Matrix temp;
    
    temp.row = MatA.row - 1;
    temp.column = MatA.column - 1;
    int i,x,y;
    
    temp.mat = (double**)malloc(sizeof(double*)*temp.row);
    for(i = 0;i<temp.row;i++) temp.mat[i] = malloc(sizeof(double)*temp.column);
    
    for(y = 0;y<temp.row;y++)
        for(x = 0;x<temp.column;x++)
        {
            if(y < ROW&&x<COLUMN)
                temp.mat[y][x] = MatA.mat[y][x];
            else if(y < ROW&&x>=COLUMN)
                temp.mat[y][x] = MatA.mat[y][x+1];
            else if(y >= ROW&&x<COLUMN)
                temp.mat[y][x] = MatA.mat[y+1][x];
            else temp.mat[y][x] = MatA.mat[y+1][x+1];
        }
    
    return temp;
}

Matrix ADJOINT(Matrix MatA){
    Matrix temp;
    
    temp.row = MatA.row;
    temp.column = MatA.column;
    int i,x,y;
    
    temp.mat = (double**)malloc(sizeof(double*)*temp.row);
    for(i = 0;i<temp.row;i++) temp.mat[i] = malloc(sizeof(double)*temp.column);
        
    for(y = 0;y<temp.row;y++)
        for(x = 0;x<temp.column;x++)
        {
            temp.mat[x][y] = pow(-1, x+y) * DET(COFACTOR(MatA, y, x));
        }
    return temp;
}

Matrix REVERSE(Matrix MatA){//计算矩阵的逆
    Matrix temp;
    
    temp = DIVISION_N(ADJOINT(MatA), DET(MatA));
    
//    temp.row = MatA.row;
//    temp.column = MatA.column;
//    int i,x,y;
//    
//    temp.mat = (double**)malloc(sizeof(double*)*temp.row);
//    for(i = 0;i<temp.row;i++) temp.mat[i] = malloc(sizeof(double)*temp.column);
//    
//    for(y = 0;y<temp.row;y++)
//        for(x = 0;x<temp.column;x++)
//            temp.mat[y][x] =RANK(COFACTOR(ADJOINT(MatA), y, x))/RANK(MatA);
//    
    return temp;
}

Matrix COLON_1(int start,int end){
    Matrix TempVector;
    int i,x,y,k = start;
    TempVector.row = 1;
    TempVector.column = end - start+1;
    
    TempVector.mat = (double**)malloc(sizeof(double*)*TempVector.row);
    for(i = 0;i<TempVector.row;i++)
        TempVector.mat[i] = malloc(sizeof(double)*TempVector.column);
    
    for(y = 0;y<TempVector.row;y++)
       for(x = 0;x<TempVector.column;x++)
           TempVector.mat[y][x] = (double)(k++);
    return TempVector;
}
Matrix COLON_2(int start,int step,int end){
    Matrix TempVector;
    int i,x,y,k = start-step;
    TempVector.row = 1;
    TempVector.column = (int)(end - start)/step + 1;
    
    TempVector.mat = (double**)malloc(sizeof(double*)*TempVector.row);
    for(i = 0;i<TempVector.row;i++)
        TempVector.mat[i] = malloc(sizeof(double)*TempVector.column);
    
    for(y = 0;y<TempVector.row;y++)
        for(x = 0;x<TempVector.column;x++)
            TempVector.mat[y][x] = (double)(k += step);
    return TempVector;
}

Matrix POWER(Matrix MatA,int k){
    Matrix temp;
    int i;
    if(k > 0)
    {
        temp = EYE(MatA.row);
        for(i = 0;i < k;i++)
          temp = MULTIPLY(temp, MatA);
    }
    else if (k < 0) {
        temp = EYE(MatA.row);
        for(i = 0;i < (-k);i++)
            temp = MULTIPLY(temp,REVERSE(MatA));
    }
    else
        temp = EYE(MatA.row);
    return temp;
}

//double RANK(Matrix MatA){
//    RREF_Trape(<#Matrix MatA#>)
//}



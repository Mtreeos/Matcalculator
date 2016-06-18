//
//  matrix.h
//  calcu
//
//  Created by 缪晴朗 on 16/6/11.
//  Copyright © 2016年 缪晴朗. All rights reserved.


//包含了代码中使用到的各种常量赋值
//包含了矩阵类型的定义
//包含了有效存储矩阵的链式结构
//包含了处理矩阵的栈结构

#ifndef matrix_h
#define matrix_h
#define BIG 100
#include <stdio.h>


typedef struct matrix{
    
    char* variable;
    double **mat;
    int row;
    int column;
    struct matrix * next;
}Matrix,*MatPtr;

//打印出matrix
void ShowMat(Matrix M);

//获取指定位置元素
double CATCHELEMENT(Matrix M,int row , int column);

/*链表结构*/


typedef struct{
    MatPtr head;
    MatPtr tail;
    int count;
}MatList;

//搜索 返回matrix的地址 错误则返回null
MatPtr SearchMat(MatList* S,char * Ovariable);
//扩张 改变tail
void AppendMatList(MatList* S,Matrix M);
//向链表中加入1*1零矩阵 variable 为"ans"
void InitMatList(MatList* S);




/*栈结构*/

typedef struct MNode{
    Matrix data;
    struct MNode * next;
}MatStackNode, *MSNptr;//typedef struct StackNode *SNptr;

typedef struct{
    MSNptr top;
    int count;
}MatStack;

void InitMatStack(MatStack*S);
void PushMatStack (MatStack *S,Matrix e);
Matrix PoPMatStack(MatStack *S);



#endif /* matrix_h */

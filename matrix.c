//
//  matrix.c
//  calcu
//
//  Created by 缪晴朗 on 16/6/11.
//  Copyright © 2016年 缪晴朗. All rights reserved.
//

#include "matrix.h"
#include <stdlib.h>
#include <string.h>
#include "MatFunction.h"

void ShowMat(Matrix M){
    int x,y;
    for(x=0;x<M.row;x++)
    {
        for(y = 0;y<M.column;y++)
            printf(" %lf",M.mat[x][y]);
        printf("\n");
    }
    printf("\n");
}

double CATCHELEMENT(Matrix M,int row , int column){
    return M.mat[row][column];
}

/*全局链表结构*/

//1.搜索 返回matrix的地址 错误则返回null
MatPtr SearchMat(MatList *S,char* Ovariable){ //which means 'Ovariable' maight be a variable
    int i;
    
    MatPtr temp = S->head;
    for(i = 0;i<S->count;i++){
        if(!strcmp(temp->variable, Ovariable))//如果搜索到了
            return temp;
        temp = temp->next;
    }
    
    return NULL;
}

//2.扩张 改变tail
void AppendMatList(MatList *S,Matrix M){
    MatPtr new = (MatPtr)malloc(sizeof(Matrix));
    *new = M;
    
    if(S->count == 0){
        S -> head = new;
        S -> tail = new;
    }
    else{
        
        S->tail->next = new;
        S->tail = new;
    }
    
    S->count ++;
    
}

void InitMatList(MatList* S){
    Matrix temp = ZEROS(1, 1);
    AppendMatList(S, temp);
    S->head->variable = (char *)malloc(sizeof(char)*BIG);
    strcpy(S->head->variable, "ANS");
}


/*局部栈结构*/

//InitStack ( *S )：初始化操作.建立一个空栈S。
void InitMatStack (MatStack *S){
    S->top = (MSNptr)malloc(sizeof(MatStackNode));
    S->count = 0;
    S->top->data = ZEROS(0, 0);
    S->top->next = NULL;
}

//PushStack (*S,e)：若栈S存在，插入新元素e到栈S中并成为栈頂元素。
void PushMatStack (MatStack *S,Matrix e){
    MSNptr newptr= (MSNptr)malloc(sizeof(MatStackNode));
    
    newptr->data = e;
    
    newptr->next = S->top;
    
    S->top = newptr;
    S->count ++;
}


//PopStack (*S,*e)：删除栈S中栈顶元素，并用e返回其值。
Matrix PoPMatStack(MatStack *S){
    Matrix e = S->top->data;
    S->top = S->top->next;
    S->count --;
    return e;
}






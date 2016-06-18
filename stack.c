//
//  stack.c
//  calcu
//
//  Created by 缪晴朗 on 16/6/3.
//  Copyright © 2016年 缪晴朗. All rights reserved.
//

#include "stack.h"


//InitStack ( *S )：初始化操作.建立一个空栈S。
void InitStack (Stack *S){
    S->top = (SNptr)malloc(sizeof(StackNode));
    S->count = 0;
    S->top->data = 0;
    S->top->next = NULL;
}

//PushStack (*S,e)：若栈S存在，插入新元素e到栈S中并成为栈頂元素。
void PushStack (Stack *S,Elemtype e){
    SNptr newptr= (SNptr)malloc(sizeof(StackNode));
    newptr->data = e;
    newptr->next = S->top;
    S->top = newptr;
    S->count ++;
}


//PopStack (*S,*e)：删除栈S中栈顶元素，并用e返回其值。
Elemtype PopStack(Stack *S){
    Elemtype e = S->top->data;
    S->top = S->top->next;
    S->count --;
    return e;
}
//VisitElemtype 访问或操作Elemtype类型的变量

void VisitElemtype(Elemtype *e){
    printf("%lf",*e);
}


//ThroughStack 遍历栈中的元素 并对其操作 此时为输出
void ThroughStack(const Stack *S){ //为统一格式 输入统一为指向堆栈的指针
    //打印第一个 当下一个不为null 输出
    SNptr temp = S->top;
    while (temp->next != NULL) {
        VisitElemtype(&(temp->data));
        temp = temp->next;
    }
}

//StackLength (S)：返回回栈S的元素个数。
Elemtype GetStackLength(const Stack *S){
    return S->count;
}

//StackEmpty ( S ):若栈为空，返回true,否則返回 false。
bool StackIsEmpty(const Stack *S){
    if(S->count == 0) return true;
    else  return false;
}


//GetTop (S,*e)：若栈存在且非空，用e返回S的栈顶元素。
Elemtype GetStackTop(const Stack *S){
    Elemtype e;
    if(StackIsEmpty(S)) return 0;
    e = S->top->data;
    return  e;
}












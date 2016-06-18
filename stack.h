//
//  stack.h
//  calcu
//
//  Created by 缪晴朗 on 16/6/3.
//  Copyright © 2016年 缪晴朗. All rights reserved.
//

#ifndef stack_h
#define stack_h//使用链表构造栈

#include <stdio.h>
#include<stdlib.h>


#define Maxsize 100
#define true 1
#define false 0

typedef int bool;
typedef double Elemtype;

typedef struct Node{
    Elemtype data;
    struct Node * next;
}StackNode, *SNptr;//typedef struct StackNode *SNptr;

typedef struct{
    SNptr top;
    int count;
}Stack;

void InitStack (Stack *S);
void PushStack (Stack *S,Elemtype e);
Elemtype PopStack(Stack *S);
void VisitElemtype(Elemtype *e);
void ThroughStack(const Stack *S);
Elemtype GetStackLength(const Stack *S);
Elemtype GetStackTop(const Stack *S);
bool StackIsEmpty(const Stack *S);

#endif /* stack_h */

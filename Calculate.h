//
//  Calculate.h
//  calcu
//
//  Created by 缪晴朗 on 16/6/12.
//  Copyright © 2016年 缪晴朗. All rights reserved.
//

#ifndef Calculate_h
#define Calculate_h

#include <stdio.h>

char* ChangeToSTD(char expression[]);//将表达式子转化为标准型

Matrix CalculateEXP(char * expression);////计算单纯表达式

Matrix CalculatWholeEXP(char * expression);

char* VIRTUAL(char * STDexpression);

//void PEEL(char* STDexpression,char ** ODItem );

#endif /* Calculate_h */

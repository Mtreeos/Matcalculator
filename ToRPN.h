//
//  ToRPN.h
//
//
//  Created by 缪晴朗 on 16/6/4.
//  Copyright © 2016年 缪晴朗. All rights reserved.
//

#ifndef ToRPN_h
#define ToRPN_h

#include <stdio.h>
#include "matrix.h"


//实现了后缀表达式 其中数字之间以及数字与变量名之间用空格隔开

char* ChangetoRPN(char* OString);

double handleRPN(char* expression);

Matrix handleRPN_Mat(char* expression);


//double handleRPN(char* expression);


#endif /* ToRPN_h */


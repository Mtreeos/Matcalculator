//
//  ToRPN.c
//  calcu
//
//  Created by 缪晴朗 on 16/6/4.
//  Copyright © 2016年 缪晴朗. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "ToRPN.h"
#include "matrix.h"
#include "Calculate.h"
#include "MatFunction.h"

char* ChangetoRPN(char* OString){ //加入了,与;的变化 以方便整合矩阵
    char* tRPN = (char*)malloc(sizeof(OString)*2);
    Stack tempcode;
    InitStack(&tempcode);
    int i = 0;
    int k = 0;
    char top;
    char ch;
    while((ch=OString[i])!='\0')
    {
        switch (OString[i]) {
            case 'A':case 'B':case 'C':case 'D':case 'E'://变量名
            case 'F':case 'G':case 'H':case 'I':case 'J':
            case 'K':case 'L':case 'M':case 'N':case 'O':
            case 'P':case 'Q':case 'R':case 'S':case 'T':
            case 'U':case 'V':case 'W':case 'X':case 'Y':
            case 'Z':case '_':
                tRPN[k++] = ch;
                break;
            case '1':case '2':case '3':case '4':case '5':
            case '6':case '7':case '8':case '9':case '0':
            case '.':
                tRPN[k++] = ch;
                break;
            case ',':case '*': case '/':
            {
                tRPN[k++] = ' ';
                top = GetStackTop(&tempcode);
                if(top == 0) PushStack(&tempcode, ch);//meams empty
                else if(top=='*'||top =='/'||top ==','){
                    tRPN[k++] = top;
                    PopStack(&tempcode);
                    PushStack(&tempcode, ch);
                }
                else if (top=='+'||top=='-'||top==';'){
                    PushStack(&tempcode, ch);
                }
                else PushStack(&tempcode, ch);//当末尾是'(' just push
            }
                break;
                
            case '+': case '-':case ';':
            {
                tRPN[k++] = ' ';
                top = GetStackTop(&tempcode);
                if(top == 0) PushStack(&tempcode, ch);//
                else if(top=='*'||top =='/'||top==',') {
                    while (GetStackTop(&tempcode) != 0 &&
                           GetStackTop(&tempcode) != '(')
                    {
                        tRPN[k++] = GetStackTop(&tempcode);
                        PopStack(&tempcode);
                    }
                    PushStack(&tempcode, ch);
                }
                else if(GetStackTop(&tempcode) == '(') PushStack(&tempcode, ch);
                else if(top=='+'||top =='-'||top == ';') {
                    tRPN[k++] = top;
                    PopStack(&tempcode);
                    PushStack(&tempcode, ch);
                }
            }break;
                
            case '(':{
                PushStack(&tempcode, ch);
            } break;
                
            case ')':{
                while (GetStackTop(&tempcode) != '(')
                {
                    tRPN[k++] = GetStackTop(&tempcode);
                    PopStack(&tempcode);
                }
                PopStack(&tempcode);//弹出'('
            } break;
                
            case ' ':
                break;
            default:
                break;
        }
        i++;
    }
    while ((ch = GetStackTop(&tempcode))!=0) {
        tRPN[k++] = ch;
        PopStack(&tempcode);
    }
    tRPN[k] = 0;
    return tRPN;
    
}


double handleRPN(char* expression)//只有数字运算
{
    Stack Result;
    InitStack(&Result);
    double a,b;
    int max = (int)strlen(expression);
    int i = 0,k = 0;
    
    while (i<max)
    {
        if(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9')//当为数字时
        {
            char temp[20] = {0};
            temp[k++] = expression[i++];
            while(expression[i]=='.'||expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9')
                temp[k++] = expression[i++];
            PushStack(&Result, atof(temp));
            k = 0;
        }
        
        else if(expression[i] == '+'){
            a=PopStack(&Result);
            b=PopStack(&Result);
            PushStack(&Result, a+b);
            i++;
        }
        else if(expression[i] == '-'){
            a=PopStack(&Result);
            b=PopStack(&Result);
            PushStack(&Result, a-b);
            i++;
        }
        else if(expression[i] == '*'){
            a=PopStack(&Result);
            b=PopStack(&Result);
            PushStack(&Result, a*b);
            i++;
        }
        else if(expression[i] == '/'){
            a=PopStack(&Result);
            b=PopStack(&Result);
            PushStack(&Result, b/a);
            i++;
        }
        else if(expression[i] == ' '){
            i++;
        }
    }
    
    return PopStack(&Result);
}

Matrix handleRPN_Mat(char* expression){
    extern MatList list;
    int i = 0, k =0;
    Matrix A,B,SingleMat;
    Matrix C;
    MatStack TempMatStack;
    InitMatStack(&TempMatStack);
    
    while(i<strlen(expression))
    {
        SingleMat  = ZEROS(1, 1);
    
        if( expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_'||expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9')
        {
            char temp[BIG] = {0};
            temp[k++] = expression[i++];
            while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||
                  expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||
                  expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||
                  expression[i]=='9'||expression[i]=='A'||expression[i]=='B'||
                  expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||
                  expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||
                  expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||
                  expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||
                  expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||
                  expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||
                  expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||
                  expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
               temp[k++] = expression[i++];
            
            if(atof(temp)!=0 || strchr(temp, '0')) {
                SingleMat.mat[0][0] = atof(temp);
                PushMatStack(&TempMatStack, SingleMat);
            }
            else PushMatStack(&TempMatStack, *SearchMat(&list, temp));
            
            k = 0;
        }
        else if(expression[i] == '*'){
            //乘法和除法加分支
            
            A = PoPMatStack(&TempMatStack);
            B = PoPMatStack(&TempMatStack);
            
            if(B.row == 1)
                C = MULTIPLY_N(A, B.mat[0][0]);
            else if(A.row == 1)
                
                C = MULTIPLY_N(B, A.mat[0][0]);
            else
                C = MULTIPLY(A, B);
            i++;
            
            PushMatStack(&TempMatStack, C);
        }
        else if(expression[i] == '+'){
            A = PoPMatStack(&TempMatStack);
            B = PoPMatStack(&TempMatStack);
            C = PLUS(A, B);
            i++;
            PushMatStack(&TempMatStack, C);
        }
        
        else if(expression[i] == '/'){
            A = PoPMatStack(&TempMatStack);
            B = PoPMatStack(&TempMatStack);
            if(A.row == 1)
                C = DIVISION_N(B, A.mat[0][0]);
            else
                C = DIVISION(B, A);
            i++;
            PushMatStack(&TempMatStack, C);
        }
        else if(expression[i] == '-'){
            A = PoPMatStack(&TempMatStack);
            B = PoPMatStack(&TempMatStack);
            C = SUB(B, A);
            i++;
            PushMatStack(&TempMatStack, C);
        }
        
        else if(expression[i] == ' '){
            i++;
        }
    }
    
    return PoPMatStack(&TempMatStack);
}


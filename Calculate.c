//
//  Calculate.c
//  calcu
//
//  Created by 缪晴朗 on 16/6/12.
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

extern MatList list;

Matrix CalculateEXP(char * expression)//计算单纯表达式
{
    Matrix result;
    
    int i,k=0;
    
    if(!strncmp(expression, "RAND", 4)){
        int RC[2]={0};
        int t = 0;
        for(i=0;i<strlen(expression);i++)
        if(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9')
        {
            char temp[BIG] = {0};
            temp[k++] = expression[i++];
            
            while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9')
            temp[k++] = expression[i++];
            
            RC[t++]=atoi(temp);
            
            k = 0;
        }
        return RAND(RC[0], RC[1]);
    }
    
    if(!strncmp(expression, "EYE",3)){
        int RC[1]={0};
        int t = 0;
        for(i=0;i<strlen(expression);i++)
            if(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9')
            {
                char temp[BIG] = {0};
                temp[k++] = expression[i++];
                
                while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9')
                    temp[k++] = expression[i++];
                
                RC[t++]=atoi(temp);
                
                k = 0;
            }
        return EYE(RC[0]);
    }
    
    if(!strncmp(expression, "ZEROS", 5)){
        int RC[2]={0};
        int t = 0;
        for(i=0;i<strlen(expression);i++)
            if(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9')
            {
                char temp[BIG] = {0};
                temp[k++] = expression[i++];
                
                while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9')
                    temp[k++] = expression[i++];
                
                RC[t++]=atoi(temp);
                
                k = 0;
            }
        return ZEROS(RC[0], RC[1]);
    }
    
    if(!strncmp(expression, "ROUND", 5)){
        Matrix MatA;
        int i;
        for(i=5;i<strlen(expression);i++)
            if(expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
            {
                char temp[BIG] = {0};
                temp[k++] = expression[i++];
                while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9'||expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
                temp[k++] = expression[i++];
                
                if(SearchMat(&list, temp)!=NULL)
                MatA = *SearchMat(&list,temp);
            }
        return ROUND(MatA);
    }
    
    if(!strncmp(expression, "REVERSE", 6)){
        Matrix MatA;
        int i;
        for(i=6;i<strlen(expression);i++)
            if(expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
            {
                char temp[BIG] = {0};
                temp[k++] = expression[i++];
                while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9'||expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
                    temp[k++] = expression[i++];
                
                if(SearchMat(&list, temp)!=NULL)
                    MatA = *SearchMat(&list,temp);
            }
        return REVERSE(MatA);
    }

    
    if(!strncmp(expression, "LOWER", 5)){
        Matrix MatA;
        int i;
        for(i=5;i<strlen(expression);i++)
            if(expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
            {
                char temp[BIG] = {0};
                temp[k++] = expression[i++];
                while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9'||expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
                    temp[k++] = expression[i++];
                
                if(SearchMat(&list, temp)!=NULL)
                    MatA = *SearchMat(&list,temp);
            }
        return LOWER(MatA);
    }
    
    if(!strncmp(expression, "UPPER", 5)){
        Matrix MatA;
        int i;
        for(i=5;i<strlen(expression);i++)
            if(expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
            {
                char temp[BIG] = {0};
                temp[k++] = expression[i++];
                while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9'||expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
                    temp[k++] = expression[i++];
                
                  if(SearchMat(&list, temp)!=NULL)
                    MatA = *SearchMat(&list,temp);
            }
        
        return UPPER(MatA);
    }
    
    
    
    if(!strncmp(expression, "RREF", 4)){
        Matrix MatA;
        int i;
        for(i=4;i<strlen(expression);i++)
            if(expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
            {
                char temp[BIG] = {0};
                temp[k++] = expression[i++];
                while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9'||expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
                    temp[k++] = expression[i++];
                
                if(SearchMat(&list, temp)!=NULL)
                    MatA = *SearchMat(&list,temp);
            }
        
        return RREF(MatA);
    }
    
    if(!strncmp(expression, "REVERSE", 6)){
        Matrix MatA;
        int i;
        for(i=6;i<strlen(expression);i++)
            if(expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
            {
                char temp[BIG] = {0};
                temp[k++] = expression[i++];
                while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9'||expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
                    temp[k++] = expression[i++];
                
                if(SearchMat(&list, temp)!=NULL)
                    MatA = *SearchMat(&list,temp);
            }
        
        return REVERSE(MatA);
    }
    
    if(!strncmp(expression, "SUM", 3)){
        Matrix MatA,MatB;
        MatB = EYE(1);
        int i;
        for(i=3;i<strlen(expression);i++)
            if(expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
            {
                char temp[BIG] = {0};
                temp[k++] = expression[i++];
                while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9'||expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
                    temp[k++] = expression[i++];
                
                if(SearchMat(&list, temp)!=NULL)
                    MatA = *SearchMat(&list,temp);
            }
        MatB.mat[0][0] = SUM(MatA);
        return MatB;
    }
    
    if(!strncmp(expression, "MAX", 3)){
        Matrix MatA,MatB;
        MatB = EYE(1);
        int i;
        for(i=3;i<strlen(expression);i++)
            if(expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
            {
                char temp[BIG] = {0};
                temp[k++] = expression[i++];
                while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9'||expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
                    temp[k++] = expression[i++];
                
                if(SearchMat(&list, temp)!=NULL)
                    MatA = *SearchMat(&list,temp);
            }
        MatB.mat[0][0] = MAX(MatA);
        return MatB;
    }
    
    
    
    if(!strncmp(expression, "REVERSE", 6)){
        Matrix MatA,MatB;
        int i;
        for(i=7;i<strlen(expression);i++)
            if(expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
            {
                char temp[BIG] = {0};
                temp[k++] = expression[i++];
                while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9'||expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
                    temp[k++] = expression[i++];
                
                if(SearchMat(&list, temp)!=NULL)
                    MatA = *SearchMat(&list,temp);
            }
        MatB = REVERSE(MatA);
        return MatB;
    }
    if(!strncmp(expression, "ADJOINT", 6)){
        Matrix MatA,MatB;
        int i;
        for(i=6;i<strlen(expression);i++)
            if(expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
            {
                char temp[BIG] = {0};
                temp[k++] = expression[i++];
                while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9'||expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
                    temp[k++] = expression[i++];
                
                if(SearchMat(&list, temp)!=NULL)
                    MatA = *SearchMat(&list,temp);
            }
        MatB = ADJOINT(MatA);
        return MatB;
    }



    
    if(!strncmp(expression, "MIN", 3)){
        Matrix MatA,MatB;
        MatB = EYE(1);
        int i;
        for(i=3;i<strlen(expression);i++)
            if(expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
            {
                char temp[BIG] = {0};
                temp[k++] = expression[i++];
                while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9'||expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
                    temp[k++] = expression[i++];
                
                if(SearchMat(&list, temp)!=NULL)
                    MatA = *SearchMat(&list,temp);
            }
        MatB.mat[0][0] = MIN(MatA);
        return MatB;
    }
    
    if(!strncmp(expression, "DET", 3)){
        Matrix MatA,MatB;
        MatB = EYE(1);
        int i;
        for(i=3;i<strlen(expression);i++)
            if(expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
            {
                char temp[BIG] = {0};
                temp[k++] = expression[i++];
                while(expression[i]=='0'||expression[i]=='1'||expression[i]=='2'||expression[i]=='3'||expression[i]=='4'||expression[i]=='5'||expression[i]=='6'||expression[i]=='7'||expression[i]=='8'||expression[i]=='9'||expression[i]=='A'||expression[i]=='B'||expression[i]=='C'||expression[i]=='E'||expression[i]=='F'||expression[i]=='G'||expression[i]=='H'||expression[i]=='I'||expression[i]=='J'||expression[i]=='K'||expression[i]=='L'||expression[i]=='M'||expression[i]=='N'||expression[i]=='O'||expression[i]=='P'||expression[i]=='Q'||expression[i]=='R'||expression[i]=='S'||expression[i]=='T'||expression[i]=='U'||expression[i]=='V'||expression[i]=='W'||expression[i]=='X'||expression[i]=='Y'||expression[i]=='Z'||expression[i]=='_')
                    temp[k++] = expression[i++];
                
                if(SearchMat(&list, temp)==NULL)
                    MatA = *SearchMat(&list,temp);
            }
        MatB.mat[0][0] = DET(MatA);
        return MatB;
    }
    
    if(strchr(expression, '\''))//power
    {
        char *PeelEXP;
        Matrix TempMat;
        
        char m[]="\'";
    
        PeelEXP=strtok(expression, m);
        
        TempMat = CalculateEXP(PeelEXP);
        
        return REVERSE(TempMat);
        
    }
    
    
    
    if(strchr(expression, '^'))//power
    {
        char *PeelEXP[2];
        Matrix TempMat[2];
        int item = 0;
        
        char m[]="^";
        
        PeelEXP[item]=strtok(expression, m);
        
        while (PeelEXP[item]) {
            PeelEXP[++item] = strtok(NULL,m);
        }
        
        for(i = 0;i<item;i++)
            TempMat[i] = CalculateEXP(PeelEXP[i]);
        
        return POWER(TempMat[0], TempMat[1].mat[0][0]);
        
    }
    
    
    if(strchr(expression, ':'))//取出其中变量个数 若为3 则调用colon_2 若为1 调用_1
    {
        char *PeelEXP[3];
        Matrix TempMat[3];
        int item = 0;
        
        char m[]=":";
        
        PeelEXP[item]=strtok(expression, m);
        
        while (PeelEXP[item]) {
            PeelEXP[++item] = strtok(NULL,m);
        }
        for(i = 0;i<item;i++)
            TempMat[i] = CalculateEXP(PeelEXP[i]);
        
        if(item == 2){
            return COLON_1(TempMat[0].mat[0][0], TempMat[1].mat[0][0]);
        }
        else
            return COLON_2(TempMat[0].mat[0][0], TempMat[1].mat[0][0],TempMat[2].mat[0][0]);
    }
    
    if(1){ //含变量名的中缀表达式 数字也可放在其中
        
        MatStack TempMatStack;
        InitMatStack(&TempMatStack);
        char * RPN = (char*)malloc(sizeof(expression));
        RPN =ChangetoRPN(expression);
        return handleRPN_Mat(RPN);
    }

    return result;
}

Matrix POWER(Matrix MatA,int k);//计算n次幂
Matrix TURN(Matrix MatA);//转置矩阵
Matrix RREF_Trape(Matrix MatA);//通过列主元消去法 化为阶梯性矩阵
Matrix RREF(Matrix MatA);//化为行最简型

Matrix COLON_1(int start,int end); //冒号
Matrix COLON_2(int start,int step,int end);

Matrix COFACTOR(Matrix MatA,int x,int y);//求出矩阵余子式
Matrix ADJOINT(Matrix MatA);//求出矩阵的伴随矩阵


char* VIRTUAL(char * STDexpression)//一个虚拟的中缀字符串 用来模拟,;的作用
{
    char * destination = malloc(sizeof(STDexpression));
    char * result = malloc(sizeof(STDexpression));
    int i;
    int k =0;
    for(i = 0;i<strlen(STDexpression);i++)
        if(STDexpression[i]==','||STDexpression[i]==';')
            destination[k++] = STDexpression[i];
    for (i=0; i<strlen(destination); i++) {
        char* temp = malloc(sizeof(char)*BIG);
        sprintf(temp,"%d",i);
        strcat(result,temp);
        strncat(result, destination+i, 1);
    }
    char* temp = malloc(sizeof(char)*BIG);
    sprintf(temp,"%d",i);
    strcat(result,temp);
//    for(i = 0;i<strlen(result);i++)
//    {
//        if(result[i] == ',') result[i] = '*';
//        if(result[i] == ';') result[i] = '+';
//    }
    return result;
}


Matrix CalculatWholeEXP(char expression[])
{
    if(strchr(expression, '[')||strchr(expression, ']')){
        MatStack TempMatStack;
        InitMatStack(&TempMatStack);
        char * VirtualRPN;
        int i,k= 0;
        int item = 0;
        char *PeelEXP[BIG];
        Matrix TempMat[BIG];
        Matrix A,B;
        
        VirtualRPN = VIRTUAL(expression);
        VirtualRPN = ChangetoRPN(VirtualRPN);
        
        char m[]="[],;";
        
        PeelEXP[item]=strtok(expression, m);
        
        while (PeelEXP[item]) {
            PeelEXP[++item] = strtok(NULL,m);
        }
        //先假设k为 式子个数
        for(i = 0;i<item;i++)
            TempMat[i] = CalculateEXP(PeelEXP[i]);
        //此时
        i = 0;
        while (i < strlen(VirtualRPN))
        {
            if(VirtualRPN[i]=='0'||VirtualRPN[i]=='1'||VirtualRPN[i]=='2'||
               VirtualRPN[i]=='3'||VirtualRPN[i]=='4'||VirtualRPN[i]=='5'||
               VirtualRPN[i]=='6'||VirtualRPN[i]=='7'||VirtualRPN[i]=='8'||
               VirtualRPN[i]=='9')//当为数字时
            {
                char temp[20] = {0};
                temp[k++] = VirtualRPN[i++];
                while(VirtualRPN[i]=='0'||VirtualRPN[i]=='1'||VirtualRPN[i]=='2'||
                      VirtualRPN[i]=='3'||VirtualRPN[i]=='4'||VirtualRPN[i]=='5'||
                      VirtualRPN[i]=='6'||VirtualRPN[i]=='7'||VirtualRPN[i]=='8'||
                      VirtualRPN[i]=='9')
                    temp[k++] = VirtualRPN[i++];
                PushMatStack(&TempMatStack, TempMat[atoi(temp)]);
                k = 0;
            }
            
            else if(VirtualRPN[i] == ';'){
                A=PoPMatStack(&TempMatStack);
                B=PoPMatStack(&TempMatStack);
                PushMatStack(&TempMatStack,MIXDOWN(B, A));
                i++;
            }
            else if(VirtualRPN[i] == ','){
                A=PoPMatStack(&TempMatStack);
                B=PoPMatStack(&TempMatStack);
                PushMatStack(&TempMatStack,MIXRIGHT(B, A));
                i++;
            }
            else if(VirtualRPN[i] == ' '){
                i++;
            }
        }
        
        return PoPMatStack(&TempMatStack);
    }
    else return CalculateEXP(expression);
}

char* ChangeToSTD(char expression[]){
    //很多空格变成一个 字母变为大写
    //去掉=[,;后面的空格 =前面的空格
    int i=0,k=0;
    char *STD_1 = (char*)malloc(sizeof(char)*strlen(expression));
    char *STD_2 = (char*)malloc(sizeof(char)*strlen(expression));
    char *STD_3 = (char*)malloc(sizeof(char)*strlen(expression));
    while(i<(int)strlen(expression)){
        if(expression[i] == ' ')
            while (expression[i+1]==' ') {
                ++i;
            }
        STD_1[k++] = expression[i++];
    }
    i = 0; k =0;
    while (i<(int)strlen(expression)) {
        if((STD_1[i]=='='||STD_1[i]=='['||STD_1[i]==','||STD_1[i]==';')&&STD_1[i+1]==' ')
        {
            STD_2[k++] = STD_1[i++];
            i++;
        }
        else if(STD_1[i]==' '&&STD_1[i+1]=='='){
            i++;
        }
        else STD_2[k++] = STD_1[i++];
    }
    i = 0; k =0;
    while (i<(int)strlen(expression)){
        if(STD_2[i]>='a'&&STD_2[i]<='z')
            STD_3[k++]=STD_2[i++]-32;
        else STD_3[k++] = STD_2[i++];
    }
    
    
    return STD_3;
}








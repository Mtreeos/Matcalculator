//
//  main.c
//  calcu
//
//  Created by 缪晴朗 on 16/6/3.
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

MatList list;//所有有效值被存储在其中


void StartWords(){
    printf("    Welcome using MatCalc by Tree     \n");
    printf("**************************************\n");
}

void help(){
    printf("When you enter like'A = [1,2; 3 4]'\n");
    printf("Congratulations! U creat a matrix!'\n");
    printf("**********************************'\n");
    printf("In order to calculate the Matrix A'\n");
    printf("  You might need to enter demands   '\n");
    printf("         such as 'SUM' 'MAX'          \n");
    printf("           or 'ROUND''DET'          \n");
    printf("          or 'stat:step:end'      \n");
    printf("           or 'RAND' 'EYE'      \n");
    printf("More Information in InstructionFILE'\n");
    printf("              have fun!           \n");
}


int main()
{
    
    extern MatList list;
    
    InitMatList(&list);
    
    StartWords();
    char* ODexpression = (char*)malloc(BIG);
    
    
    while (fgets(ODexpression,BIG,stdin))
    {
        char* TempExp;
        int i ,y,x;
        Matrix MatA;
        MatPtr Matptr;
        TempExp = ChangeToSTD(ODexpression);
        
//        if(!strncmp(TempExp, "READFILE", 8)){
//            FILE *finput,*foutput;
//            
//            finput = fopen("example.txt", "r+");
//            foutput = fopen("output.txt", "w+");
//            
//            fgets(ODexpression, 2, finput);
//            TempExp = ChangeToSTD(ODexpression);
//            
//            
//            fputs("nihao", foutput);
//        }
//        TempExp = ChangeToSTD(ODexpression);

        if(!strncmp(TempExp, "QUIT", 4)) break;
        
        
        if(!strncmp(TempExp, "HELP", 4)){ help(); continue;}
        
        
        
        if(!strchr(TempExp, '=')){
            printf("ans =\n");
            MatA = CalculatWholeEXP(TempExp);
            list.head->column = MatA.column;
            list.head->row = MatA.row;
            list.head->mat = (double**)malloc(sizeof(double*)*MatA.row);
            for(i = 0;i<MatA.row;i++) list.head->mat[i] = malloc(sizeof(double)*MatA.column);
            
            for(y = 0;y<MatA.row;y++)
                for(x = 0;x<MatA.column;x++)
                    list.head->mat[y][x] = MatA.mat[y][x];
            ShowMat(MatA);
        }
        
        else{
            printf("ans =\n");
            char *PeelEXP[2];
            int item = 0;
            
            char m[]="=";
            PeelEXP[item]=strtok(TempExp, m);
            
            while (PeelEXP[item])
            {
                PeelEXP[++item] = strtok(NULL,m);}
                
            MatA = CalculatWholeEXP(PeelEXP[1]);
            list.head->column = MatA.column;
            list.head->row = MatA.row;
            list.head->mat = (double**)malloc(sizeof(double*)*MatA.row);
            for(i = 0;i<MatA.row;i++)
                list.head->mat[i] = malloc(sizeof(double)*MatA.column);

            for(y = 0;y<MatA.row;y++)
                for(x = 0;x<MatA.column;x++)
                    list.head->mat[y][x] = MatA.mat[y][x];
            
            if((Matptr = SearchMat(&list, PeelEXP[0]))!=NULL){
                Matptr->column = MatA.column;
                Matptr->row = MatA.row;
                Matptr->mat = (double**)malloc(sizeof(double*)*MatA.row);
                for(i = 0;i<MatA.row;i++)
                    Matptr->mat[i] = malloc(sizeof(double)*MatA.column);
                
                for(y = 0;y<MatA.row;y++)
                    for(x = 0;x<MatA.column;x++)
                        Matptr->mat[y][x] = MatA.mat[y][x];
            }//加一个判断 如果PeelEXP[0]可以找到 改变其值
            else
            {
                AppendMatList(&list, MatA);
            list.tail->variable = (char*)malloc(sizeof(char)*BIG);
            list.tail->variable = PeelEXP[0];
            }
            ShowMat(MatA);

        }
    }
}





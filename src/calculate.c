#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disassembler.h"
#include "calculate.h"

//convert input to binary : [31]~~~[0]
void fillBinaryArr(unsigned int value, int binaryArr[32])
{
    for(int i=31; i>=0; i--)
    {
        binaryArr[i]=(value>>i)&1;
    }
}

//address calculate
char* convert_binary_to_decimal(char* binaryString)
{
    int decimal=0;
    int length=strlen(binaryString);
    char* stringNum=(char*)malloc(length+1);

    for(int i=0;i<length;i++)
    {
        if(binaryString[i]=='1')
            decimal+=1<<(length-1-i);
    }
    sprintf(stringNum, "%d",decimal);
    return stringNum;
}

//immediate calculate
char* convert_binary_to_decimal_imm(char* binaryString)
{
    int decimal=0;
    int length=strlen(binaryString);
    char* stringNum=(char*)malloc(length+1);

    int complementCount=0;


   if(binaryString[0]=='1')
   {
        complementCount=1;
        for(int i=0; i<length; i++)
        {
            if(binaryString[i]=='0')
                binaryString[i]='1';
            else
                binaryString[i]='0';
        }
        int carry=1;
        for(int i= length-1; i>=0;i--)
        {
            if(binaryString[i]=='0'&&carry==1)
            {
                binaryString[i]='1';
                carry=0;
            }
            else if(binaryString[i]=='1'&&carry==1)
            {
                binaryString[i]='0';
            }
        }
   }
    for(int i=0;i<length;i++)
    {
        if(binaryString[i]=='1')
            decimal+=1<<(length-1-i);
    }

    if(complementCount)
        decimal=-decimal;
    sprintf(stringNum, "%d",decimal);
    return stringNum;
}

char* slice_array(int* arr, int start, int end)
{
    int arrSize = end-start;
    char* combinedNum =(char *)malloc(sizeof(char)*(arrSize+1));
    int* slicedArray=(int *)malloc(sizeof(int)*arrSize);
    int num=0;
    

    for (int i = 0; i < arrSize; i++) {
        slicedArray[i] = arr[end - 1 - i];
    }

    for (int i=0; i<arrSize;i++)
    {
        char digit=slicedArray[i]+'0';
        combinedNum[num++]=digit;
    }
    combinedNum[num]='\0';

    return combinedNum;
}


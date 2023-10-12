#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disassembler.h"
#include "calculate.h"


int main(int argc, char* argv[])
{

    
    if(argc!=2)
    {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    FILE *fp;
    unsigned char buffer[4];
    int count=0;
    int binaryArr[32];

    //read file

    if ((fp = fopen(argv[1],"rb")) == NULL)
    {
        perror("fopen");
        exit(1);
    }

    //disassemble
    while (fread(buffer, sizeof(buffer),1, fp)==1)
    {
        unsigned int value = buffer[3]<<24 | buffer[2]<<16 | buffer[1]<<8|buffer[0];
        fillBinaryArr(value, binaryArr);
        char* result=disassemble(binaryArr);  
        printf("inst %d: %08x %s\n",count++, value,result);      
    }

    fclose(fp);
    
    return 0;
}
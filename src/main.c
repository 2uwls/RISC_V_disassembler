#include <stdio.h>
#include "disassembler.h"

int main(int argc, char* argv[])
{
    // 1. file path 입력 받기

    // 2. file 명령어 마다 읽어들이기

    // 3. 각 끊은 거를 disassemble
    char s[] = "00208033";
    char src[] = "0000000000101000000000110011";
    printf("%s\n", disassemble(src));

    // 4. 출력

    return 0;
}
//disassemble
char* disassemble(int*arr);


//type
char* disassemble_with_rType(int* arr, char* instruction, char* result);
char* disassemble_with_iType(int* arr, char* instruction, char* result);
char* disassemble_with_iTypeLoad(int* arr, char* instruction, char* result);
char* disassemble_with_sType(int* arr, char* instruction, char* result, char* imm);
char* disassemble_with_sbType(int* arr, char* instruction, char* result, char* imm);

//else
char* disassemble_with_luiInst(int *arr, char* instruction, char* result,char* imm);
char* disassemble_with_auipcInst(int* arr, char* instruction, char* result,char* imm);
char* disassemble_with_jalInst(int* arr, char* instruction, char* result, char* imm);
char* disassemble_with_jalrInst(int *arr, char* instruction, char* result);

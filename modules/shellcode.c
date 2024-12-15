#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shellcode.h"

// Display the help menu for the XOR module
void shellcode_help() {
    printf("Binary To Shellcode Module\n\n");
    printf("Usage:\n");
    printf("  shellcode --help              Display this help message.\n");
    printf("  shellcode payload.bin shellcode.txt\n");
    printf("                          Convert MSFvenom .bin to shellcode.\n\n");
    printf("Example:\n");
    printf("  chameleon shellcode payload.bin shellcode.txt \n");
}
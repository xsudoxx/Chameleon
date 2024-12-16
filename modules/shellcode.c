#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shellcode.h"

// Display the help menu for the XOR module
void shellcode_help() {
    printf("Binary To Shellcode Module\n\n");
    printf("Usage:\n");
    printf("  shellcode --help                              Display this help message.\n");
    printf("  shellcode payload.bin shellcode.txt           Convert MSFvenom .bin to shellcode\n");
    printf("Example:\n");
    printf("  chameleon shellcode payload.bin shellcode.txt \n");
}//shellcode_help

void print_shellcode_to_file(const char* input_file, const char* output_file) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "w");

    if (!input || !output) {
        printf("Error: Unable to open file.\n");
        return;
    }

    fprintf(output, "unsigned char shellcode[] = {\n");

    int byte;
    int count = 0;
    while ((byte = fgetc(input)) != EOF) {
        if (count > 0) {
            fprintf(output, ", ");
        }
        if (count % 10 == 0 && count != 0) { // Wrap lines every 10 bytes
            fprintf(output, "\n    ");
        }
        fprintf(output, "0x%02x", byte);
        count++;
    }

    fprintf(output, "\n};\n");

    fclose(input);
    fclose(output);
}


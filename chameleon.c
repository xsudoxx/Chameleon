#include <stdio.h>
#include <string.h>
#include "modules/xor.h"
#include "modules/shellcode.h"

// Display the main help menu
void display_help() {
    printf("Chameleon - Obfuscation and Payload Manipulation Tool\n\n");
    printf("Usage: chameleon [option] [arguments]\n\n");
    printf("Options:\n");
    printf("  --help                  Display this help message.\n");
    printf("  xor --help              Display usage for XOR obfuscation.\n");
    printf("  xor <input> <output> <key>\n");
    printf("                          Encrypt a shellcode file using XOR encryption.\n");
    printf("  shellcode --help        Display usage for shellcode manipulation.\n");
    printf("  shellcode <input> <output>\n");
    printf("                          Convert a shellcode file to C-style array format.\n\n");

    printf("Example: XOR Obfuscation\n");
    printf("  chameleon xor raw_shellcode.txt encrypted_shellcode.txt key123\n");
    printf("\n");
    printf("Example: Convert Shellcode to C array format\n");
    printf("  chameleon shellcode payload.bin shellcode.txt\n");
    printf("  This will convert the 'payload.bin' file into C-style shellcode array and save it in 'shellcode.txt'.\n");

    printf("\nUsage for Shellcode File Conversion:\n");
    printf("  chameleon shellcode <input_file> <output_file>\n");
    printf("  - This option will take the input file (e.g., a binary payload) and convert it to a C-style array format\n");
    printf("    suitable for use in C programs.\n");
    printf("  - The output will be a C file containing an array like:\n");
    printf("    unsigned char shellcode[] = {\n");
    printf("        \\x90, \\x90, \\x90, // Add your shellcode bytes here\n");
    printf("    };\n");
    printf("\n");
    printf("Note: For XOR encryption, the input file should be a binary shellcode file (e.g., from msfvenom).\n");
    printf("      You can then use the output encrypted file in your program for further obfuscation.\n");
}


int main(int argc, char* argv[]) {
    // Display help if no arguments are passed
    if (argc < 2) {
        printf("Error: No option provided.\n");
        display_help();
        return 1;
    }

    // Handle --help option
    if (strcmp(argv[1], "--help") == 0) {
        display_help();
        return 0;
    }

    // Handle XOR module
    if (strcmp(argv[1], "xor") == 0) {
        if (argc == 3 && strcmp(argv[2], "--help") == 0) {
            xor_help();
            return 0;
        }

        if (argc == 5) {
            const char* input_file = argv[2];
            const char* output_file = argv[3];
            const char* key = argv[4];
            xor_enc_dec(input_file, output_file, key);
            return 0;
        }

        printf("Error: Invalid arguments for 'xor'.\n");
        xor_help();
        return 1;
    }

    // Handle Shellcode module
    if (strcmp(argv[1], "shellcode") == 0) {
        if (argc == 3 && strcmp(argv[2], "--help") == 0) {
            shellcode_help();
            return 0;
        }

        // if (argc == 5) {
        //     const char* input_file = argv[2];
        //     const char* output_file = argv[3];
        //     const char* key = argv[4];
        //     xor_enc_dec(input_file, output_file, key);
        //     return 0;
        // }

        printf("Error: Invalid arguments for 'shellcode'.\n");
        shellcode_help();
        return 1;
    }

    // Unknown option
    printf("Error: Unknown option '%s'.\n", argv[1]);
    display_help();
    return 1;
}
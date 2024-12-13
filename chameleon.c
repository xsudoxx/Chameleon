#include <stdio.h>
#include <string.h>
#include "modules/xor.h"

// Display the main help menu
void display_help() {
    printf("Chameleon - Obfuscation and Payload Manipulation Tool\n\n");
    printf("Usage: chameleon [option] [arguments]\n\n");
    printf("Options:\n");
    printf("  --help                  Display this help message.\n");
    printf("  xor --help              Display usage for XOR obfuscation.\n");
    printf("  xor <input> <output> <key>\n");
    printf("                          Encrypt a shellcode file using XOR encryption.\n\n");
    printf("Example:\n");
    printf("  chameleon xor raw_shellcode.txt encrypted_shellcode.txt key123\n");
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

        // if (argc == 5) {
        //     const char* input_file = argv[2];
        //     const char* output_file = argv[3];
        //     const char* key = argv[4];
        //     xor_encrypt(input_file, output_file, key);
        //     return 0;
        // }

        printf("Error: Invalid arguments for 'xor'.\n");
        xor_help();
        return 1;
    }

    // Unknown option
    printf("Error: Unknown option '%s'.\n", argv[1]);
    display_help();
    return 1;
}

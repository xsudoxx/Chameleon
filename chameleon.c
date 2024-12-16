#include <stdio.h>
#include <string.h>
#include "modules/xor.h"
#include "modules/shellcode.h"
#include "modules/uuid.h"

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
        if (argc == 2) { // User entered "chameleon.exe shellcode"
            shellcode_help(); // Show help by default
            return 0;
        }

        if (argc == 3 && strcmp(argv[2], "--help") == 0) { // User entered "chameleon.exe shellcode --help"
            shellcode_help();
            return 0;
        }

        if (argc == 4) { // User entered "chameleon.exe shellcode input_file output_file"
            const char* input_file = argv[2]; // argv[2] should be the input file
            const char* output_file = argv[3]; // argv[3] should be the output file

            // Call the function to print the shellcode to a file
            print_shellcode_to_file(input_file, output_file);

            printf("Shellcode has been written to %s\n", argv[3]);
            return 0;
        }

        // If none of the above conditions match, display an error and the help message
        printf("Error: Invalid arguments for 'shellcode'.\n");
        shellcode_help();
        return 1;
    }
    if (strcmp(argv[1], "uuid") == 0) {
        if (argc == 2) { // User entered "chameleon.exe uuid"
            uuid_help(); // Show help by default
            return 0;
        }

        if (argc == 3 && strcmp(argv[2], "--help") == 0) { // User entered "chameleon.exe uuid --help"
            uuid_help();
            return 0;
        }

        if (argc == 4) { // User entered "chameleon.exe uuid input_file output_file"
            handle_uuid_conversion(argv[2], argv[3]);
            return 0;
        }

        printf("Error: Invalid arguments for 'uuid'.\n");
        uuid_help();
        return 1;
    }


    // Unknown option
    printf("Error: Unknown option '%s'.\n", argv[1]);
    display_help();
    return 1;
}
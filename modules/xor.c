#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "xor.h"

// Display the help menu for the XOR module
void xor_help() {
    printf("XOR Obfuscation Module\n\n");
    printf("Usage:\n");
    printf("  xor --help                       Display this help message.\n");
    printf("  xor <input> <output> <key>       Encrypt a shellcode file using XOR encryption.\n");
    printf("Example:\n");
    printf("  chameleon xor raw_shellcode.txt encrypted_shellcode.txt key123\n");
}

void xor_enc_dec(const char* input_file, const char* output_file, const char* key) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    if (!input || !output) {
        printf("Error: Unable to open file(s).\n");
        if (input) fclose(input);
        if (output) fclose(output);
        return;
    }

    size_t key_len = strlen(key);
    int c;
    size_t i = 0;

    // Read each byte, XOR it with the key, and write to the output file
    while ((c = fgetc(input)) != EOF) {
        fputc(c ^ key[i % key_len], output);
        i++;
    }

    fclose(input);
    fclose(output);

    printf("File '%s' successfully encrypted/decrypted to '%s'.\n", input_file, output_file);
}

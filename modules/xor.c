#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "xor.h"

// Display the help menu for the XOR module
void xor_help() {
    printf("XOR Obfuscation Module\n\n");
    printf("Usage:\n");
    printf("  xor --help              Display this help message.\n");
    printf("  xor <input> <output> <key>\n");
    printf("                          Encrypt a shellcode file using XOR encryption.\n\n");
    printf("Example:\n");
    printf("  chameleon xor raw_shellcode.txt encrypted_shellcode.txt key123\n");
}
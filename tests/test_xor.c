#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "xor.h"

// Function to compare two strings
int compare_strings(const char *str1, const char *str2) {
    return strcmp(str1, str2) == 0;
}

void test_xor_encryption() {
    const char *input = "Hello, World!";
    const char *key = "key123";
    
    char encrypted[256] = {0};
    char decrypted[256] = {0};
    
    // Encrypt the message
    xor_enc_dec(input, encrypted, key);
    
    // Decrypt the message (should match the original)
    xor_enc_dec(encrypted, decrypted, key);
    
    // Check if decrypted message matches the original
    if (compare_strings(input, decrypted)) {
        printf("Test passed: XOR encryption/decryption works.\n");
    } else {
        printf("Test failed: Decrypted message does not match original.\n");
    }
}

int main() {
    test_xor_encryption();
    return 0;
}

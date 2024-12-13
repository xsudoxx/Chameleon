#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xor.h"

void test_xor_encryption() {
    const char *input = "Hello, World!";
    const char *key = "key123";
    
    char encrypted[256] = {0};
    char decrypted[256] = {0};
    
    // Encrypt the message
    xor_enc_dec(input, encrypted, key);
    
    // Decrypt the message (should match the original)
    xor_enc_dec(encrypted, decrypted, key);
    
    if (strcmp(input, decrypted) == 0) {
        printf("Test passed: XOR encryption/decryption works.\n");
    } else {
        printf("Test failed: Decrypted message does not match original.\n");
    }
}

int main() {
    test_xor_encryption();
    return 0;
}

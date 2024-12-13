#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xor.h"

// Function to print test result
void test_xor_encryption() {
    const char *input = "Hello, World!";  // Example input string
    const char *key = "key123";           // Example XOR key
    
    char encrypted[256] = {0};           // Buffer for encrypted output
    char decrypted[256] = {0};           // Buffer for decrypted output
    
    // Encrypt the message
    xor_enc_dec(input, encrypted, key);
    
    // Decrypt the message (should match the original)
    xor_enc_dec(encrypted, decrypted, key);
    
    // Check if the decrypted message matches the original input
    if (strcmp(input, decrypted) == 0) {
        printf("Test passed: XOR encryption/decryption works.\n");
    } else {
        printf("Test failed: Decrypted message does not match original.\n");
    }
}

int main() {
    test_xor_encryption();  // Run the unit test
    return 0;
}

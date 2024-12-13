#include <assert.h>
#include <stdio.h>
#include "modules/xor.h"

void test_xor_encryption() {
    const char* input = "Hello, World!";
    const char* key = "key123";
    char encrypted_output[256];
    char decrypted_output[256];
    
    // Encrypt the input
    xor_enc_dec(input, encrypted_output, key);
    
    // Decrypt it back
    xor_enc_dec(encrypted_output, decrypted_output, key);
    
    // Assert that the decrypted output matches the original input
    assert(strcmp(input, decrypted_output) == 0);
    
    printf("XOR Encryption and Decryption Test Passed!\n");
}

int main() {
    test_xor_encryption();
    return 0;
}

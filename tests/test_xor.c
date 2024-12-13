#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xor.h"

// Function to read the file into a buffer
size_t read_file(const char *filename, char **buffer) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return 0;
    }
    
    // Get file size
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // Allocate buffer to hold file contents
    *buffer = (char *)malloc(file_size);
    if (*buffer == NULL) {
        perror("Memory allocation error");
        fclose(file);
        return 0;
    }
    
    // Read the file content into the buffer
    size_t bytes_read = fread(*buffer, 1, file_size, file);
    fclose(file);
    return bytes_read;
}

// Function to write a buffer to a file
void write_file(const char *filename, const char *buffer, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }
    
    fwrite(buffer, 1, size, file);
    fclose(file);
}

void test_xor_encryption() {
    const char *input_file = "modules/raw_shellcode.bin";
    const char *encrypted_file = "modules/encrypted_shellcode.bin";
    const char *decrypted_file = "modules/decrypted_shellcode.bin";
    const char *key = "key123";
    
    // Read the input file into a buffer
    char *input_buffer = NULL;
    size_t input_size = read_file(input_file, &input_buffer);
    if (input_size == 0) {
        printf("Error: Failed to read input file.\n");
        return;
    }

    // Encrypt the file contents
    char *encrypted_buffer = (char *)malloc(input_size);
    if (encrypted_buffer == NULL) {
        perror("Memory allocation error for encrypted buffer");
        free(input_buffer);
        return;
    }
    xor_enc_dec(input_buffer, encrypted_buffer, key);

    // Write encrypted data to file
    write_file(encrypted_file, encrypted_buffer, input_size);

    // Decrypt the file contents
    char *decrypted_buffer = (char *)malloc(input_size);
    if (decrypted_buffer == NULL) {
        perror("Memory allocation error for decrypted buffer");
        free(input_buffer);
        free(encrypted_buffer);
        return;
    }
    xor_enc_dec(encrypted_buffer, decrypted_buffer, key);

    // Write decrypted data to file
    write_file(decrypted_file, decrypted_buffer, input_size);

    // Compare original and decrypted files
    if (memcmp(input_buffer, decrypted_buffer, input_size) == 0) {
        printf("Test passed: XOR encryption/decryption works.\n");
    } else {
        printf("Test failed: Decrypted message does not match original.\n");
    }

    // Clean up
    free(input_buffer);
    free(encrypted_buffer);
    free(decrypted_buffer);
}

int main() {
    test_xor_encryption();
    return 0;
}

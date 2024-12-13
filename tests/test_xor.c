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

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    *buffer = (char *)malloc(file_size);
    if (*buffer == NULL) {
        perror("Memory allocation error");
        fclose(file);
        return 0;
    }

    size_t bytes_read = fread(*buffer, 1, file_size, file);
    fclose(file);
    return bytes_read;
}

// Function to write the buffer to a file
void write_file(const char *filename, const char *buffer, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }
    fwrite(buffer, 1, size, file);
    fclose(file);
}

int main() {
    const char *input_file = "modules/raw_shellcode.bin";  // The raw shellcode file
    const char *encrypted_file = "modules/encrypted_shellcode.bin"; // Encrypted output file
    const char *key = "key123"; // XOR encryption key

    // Read the input file into a buffer
    char *input_buffer = NULL;
    size_t input_size = read_file(input_file, &input_buffer);
    if (input_size == 0) {
        printf("Error: Failed to read input file.\n");
        return 1;
    }

    // Encrypt the file contents
    char *encrypted_buffer = (char *)malloc(input_size);
    if (encrypted_buffer == NULL) {
        perror("Memory allocation error for encrypted buffer");
        free(input_buffer);
        return 1;
    }
    xor_enc_dec(input_buffer, encrypted_buffer, key);

    // Write encrypted data to the file
    write_file(encrypted_file, encrypted_buffer, input_size);

    // Print the encrypted file contents to stdout (as hex for visibility)
    printf("Encrypted contents of %s:\n", encrypted_file);
    for (size_t i = 0; i < input_size; ++i) {
        printf("%02x ", (unsigned char)encrypted_buffer[i]);
    }
    printf("\n");

    // Clean up
    free(input_buffer);
    free(encrypted_buffer);

    return 0;
}

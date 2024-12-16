#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uuid.h"

#define MAX_UUIDS 1024  // Set a maximum limit for UUIDs (or dynamically adjust if needed)

// Global array to store UUIDs
char UuidArray[MAX_UUIDS][37];  // 36 characters + null terminator for each UUID

// Display the help menu for the UUID module
void uuid_help() {
    printf("UUID Obfuscation Module\n\n");
    printf("Usage:\n");
    printf("  uuid --help                                   Display this help message.\n");
    printf("  uuid payload.bin uuid_array.txt               Convert shellcode .bin to UUID array.\n");
    printf("Example:\n");
    printf("  chameleon uuid payload.bin uuid_array.txt\n");
    printf("Description:\n");
    printf("  This module converts raw shellcode into UUID strings.\n");
    printf("  The output is saved as a C-style array in the specified file.\n");
    printf("  UUIDs help obfuscate the shellcode, making it harder to detect.\n");
}

// This function handles UUID conversion
void handle_uuid_conversion(const char* input_file, const char* output_file) {
    // Open the input file in binary mode
    FILE* file = fopen(input_file, "rb");
    if (!file) {
        printf("Error: Could not open input file %s\n", input_file);
        return;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);

    // Allocate memory to hold the shellcode
    unsigned char* shellcode = (unsigned char*)malloc(file_size);
    if (!shellcode) {
        printf("Error: Could not allocate memory for shellcode.\n");
        fclose(file);
        return;
    }

    // Read the shellcode into memory
    fread(shellcode, 1, file_size, file);
    fclose(file);

    // Call the function to convert shellcode to UUID
    convert_shellcode_to_uuid(shellcode, file_size);

    // Open the output file for writing
    FILE* output = fopen(output_file, "w");
    if (!output) {
        printf("Error: Could not open output file %s\n", output_file);
        free(shellcode);
        return;
    }

    // Write the UUIDs to the output file
    fprintf(output, "char* UuidArray[] = {\n");
    for (int i = 0; i < MAX_UUIDS && UuidArray[i][0] != '\0'; i++) {
        fprintf(output, "    \"%s\",\n", UuidArray[i]);
    }
    fprintf(output, "};\n");

    fclose(output);
    free(shellcode);

    printf("UUID array has been written to %s\n", output_file);
}

// Function to convert shellcode to UUID
void convert_shellcode_to_uuid(const unsigned char* shellcode, size_t size) {
    size_t uuid_index = 0;
    char uuid[37];  // UUID string format (36 characters + null terminator)

    // Process the shellcode in 16-byte chunks
    for (size_t i = 0; i < size; i += 16) {
        // Zero-initialize UUID buffer
        memset(uuid, 0, sizeof(uuid));

        // Format the 16-byte chunk into UUID format
        snprintf(uuid, sizeof(uuid),
            "%02X%02X%02X%02X-%02X%02X-%02X%02X-%02X%02X-%02X%02X%02X%02X%02X%02X",
            shellcode[i + 0], shellcode[i + 1], shellcode[i + 2], shellcode[i + 3],
            shellcode[i + 4], shellcode[i + 5], shellcode[i + 6], shellcode[i + 7],
            shellcode[i + 8], shellcode[i + 9], shellcode[i + 10], shellcode[i + 11],
            shellcode[i + 12], shellcode[i + 13], shellcode[i + 14], shellcode[i + 15]);

        // Store the UUID in the global UuidArray
        strncpy(UuidArray[uuid_index], uuid, sizeof(UuidArray[uuid_index]));
        uuid_index++;

        // Check if we exceed the maximum number of UUIDs allowed
        if (uuid_index >= MAX_UUIDS) {
            break;
        }
    }
}

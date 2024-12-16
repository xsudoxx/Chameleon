#ifndef UUID_H
#define UUID_H

// Function to display help information for XOR obfuscation
void uuid_help();
void convert_shellcode_to_uuid(const unsigned char* shellcode, size_t size);
void handle_uuid_conversion(const char* input_file, const char* output_file);
#endif // UUID_H
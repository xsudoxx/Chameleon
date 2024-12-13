CC = gcc
CFLAGS = -Wall -I./modules

# Target to compile the test program
test_xor: tests/test_xor.c modules/xor.o
	$(CC) $(CFLAGS) tests/test_xor.c -o test_xor modules/xor.o

# Target to compile the XOR module
modules/xor.o: modules/xor.c modules/xor.h
	$(CC) $(CFLAGS) -c modules/xor.c -o modules/xor.o

# Phony targets
.PHONY: clean

# Clean up object files and executables
clean:
	rm -f test_xor modules/xor.o modules/encrypted_shellcode.bin

CC = gcc
CFLAGS = -Wall -I./modules

# Target to compile the test
test_xor: test_xor.c modules/xor.o
	$(CC) $(CFLAGS) test_xor.c -o test_xor modules/xor.o

# Target to compile the XOR module
modules/xor.o: modules/xor.c modules/xor.h
	$(CC) $(CFLAGS) -c modules/xor.c -o modules/xor.o

# Target to run the tests
run_tests: test_xor
	./test_xor

# Clean up object files and executables
clean:
	rm -f test_xor modules/xor.o modules/encrypted_shellcode.bin modules/decrypted_shellcode.bin

# Phony targets
.PHONY: clean run_tests

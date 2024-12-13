CC = gcc
CFLAGS = -Wall

# Default target to compile the program
all: test_xor

# Compile test_xor.c and xor.c
test_xor: test_xor.c xor.c
	$(CC) $(CFLAGS) -o test_xor test_xor.c xor.c

# Clean up generated files
clean:
	rm -f test_xor

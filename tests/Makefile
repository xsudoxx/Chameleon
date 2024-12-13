# Compiler and flags
CC = gcc
CFLAGS = -Wall -I../modules  # Assuming your modules are in the parent directory

# File paths
SRC = test_xor.c ../modules/xor.c
OBJ = test_xor.o ../modules/xor.o
EXEC = test_xor

# Default target (compile everything)
all: $(EXEC)

# How to build the test_xor executable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Compile source files into object files
test_xor.o: test_xor.c
	$(CC) $(CFLAGS) -c test_xor.c

../modules/xor.o: ../modules/xor.c
	$(CC) $(CFLAGS) -c ../modules/xor.c

# Run tests (you can call the test directly here)
run_tests: $(EXEC)
	./$(EXEC)

# Clean up generated files
clean:
	rm -f $(OBJ) $(EXEC)

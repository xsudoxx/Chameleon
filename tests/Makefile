CC=gcc
CFLAGS=-Wall -I../modules  # Include the modules folder for the headers
SOURCES=test_xor.c
OBJECTS=$(SOURCES:.c=.o)
EXEC=test_runner  # Renaming to avoid conflict with run_tests

# Default target to build the tests
all: $(EXEC)

# Rule to build the final executable (test_runner)
$(EXEC): $(OBJECTS) ../modules/xor.o
	$(CC) $(OBJECTS) -o $(EXEC) ../modules/xor.o

# Rule to compile the test source file
test_xor.o: test_xor.c
	$(CC) $(CFLAGS) -c test_xor.c -o test_xor.o

# Rule to compile the xor module
../modules/xor.o: ../modules/xor.c
	$(CC) $(CFLAGS) -c ../modules/xor.c -o ../modules/xor.o

# Clean up object files and executable
clean:
	rm -f $(OBJECTS) $(EXEC)

# Run the compiled tests
run_tests: $(EXEC)
	./$(EXEC)

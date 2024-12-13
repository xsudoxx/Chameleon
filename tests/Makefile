CC=gcc
CFLAGS=-Wall -I../modules  # Include the modules folder for the headers
SOURCES=test_xor.c
OBJECTS=$(SOURCES:.c=.o)
EXEC=run_tests

# Define the default target, which will build the tests
all: $(EXEC)

# Rule to build the final executable (run_tests)
$(EXEC): $(OBJECTS) ../modules/xor.o
	$(CC) $(OBJECTS) -o $(EXEC) ../modules/xor.o

# Rule to compile the test source file
../modules/xor.o: ../modules/xor.c
	$(CC) $(CFLAGS) -c ../modules/xor.c -o ../modules/xor.o

# Clean up object files and executable
clean:
	rm -f $(OBJECTS) $(EXEC)

# Run the compiled tests
run_tests: $(EXEC)
	./$(EXEC)

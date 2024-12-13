CC=gcc
CFLAGS=-Wall -I../modules  # Ensure correct path to modules folder
SOURCES=test_xor.c
OBJECTS=$(SOURCES:.c=.o)
EXEC=run_tests

all: $(EXEC)

$(EXEC): $(OBJECTS) ../modules/xor.o  # Link xor.o object file from modules
	$(CC) $(OBJECTS) -o $(EXEC) ../modules/xor.o

../modules/xor.o: ../modules/xor.c  # Compile xor.c to xor.o
	$(CC) $(CFLAGS) -c ../modules/xor.c -o ../modules/xor.o

clean:
	rm -f $(OBJECTS) $(EXEC)

run_tests: $(EXEC)
	./$(EXEC)

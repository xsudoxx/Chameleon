CC=gcc
CFLAGS=-Wall -I../modules
SOURCES=test_xor.c
OBJECTS=$(SOURCES:.c=.o)
EXEC=run_tests

all: $(EXEC)

$(EXEC): $(OBJECTS) ../modules/xor.o
	$(CC) $(OBJECTS) -o $(EXEC) ../modules/xor.o

clean:
	rm -f $(OBJECTS) $(EXEC)

run_tests: $(EXEC)
	./$(EXEC)
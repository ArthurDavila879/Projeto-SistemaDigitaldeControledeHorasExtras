CC = gcc
CFLAGS = -Wall
TARGET = programa
SOURCES = main.c funcoes.c
HEADERS = funcoes.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET) *.o

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

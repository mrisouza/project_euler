.PHONY: clean

CC := g++
CXXFLAGS := -O0 -g -std=c++11 -Wall -Wextra -Wshadow -pedantic -Weffc++
CFLAGS := 
LDFLAGS :=
OBJFILES := main.o
TARGET := main

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -rf $(OBJFILES) $(TARGET) *~
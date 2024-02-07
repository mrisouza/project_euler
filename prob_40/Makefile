.PHONY: clean, all

CC := g++
CXXFLAGS := -O0 -g -std=c++11 -Wall -Wextra -Wshadow -pedantic -Weffc++
SOURCES := main.cpp
OBJFILES := $(SOURCES:.cpp=.o)
LDFLAGS := 
TARGET := main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -rf $(TARGET) $(OBJFILES) ~*
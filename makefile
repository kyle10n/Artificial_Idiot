# Makefile for lab5 project

CXX = g++
TARGET = slm
SRC = $(wildcard src/*.cpp)

$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
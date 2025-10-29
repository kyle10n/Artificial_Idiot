# Makefile for lab5 project

CXX = g++
TARGET = slm
SRC = ./src/*.cpp

# Compile program
$(TARGET): $(SRC)
	$(CXX) -o $(TARGET) $(SRC)

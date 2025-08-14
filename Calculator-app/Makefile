# Makefile for Basic Calculator

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = calculator
SOURCE = calculator.cpp

# Default target
all: $(TARGET)

# Build the calculator
$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

# Run the calculator
run: $(TARGET)
	./$(TARGET)

# Clean up compiled files
clean:
	rm -f $(TARGET)

# Install dependencies (if needed)
install:
	@echo "No additional dependencies required for this C++ calculator"

.PHONY: all run clean install

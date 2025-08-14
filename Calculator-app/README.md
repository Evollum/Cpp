# Basic C++ Calculator

A simple command-line calculator written in C++ that performs basic arithmetic operations.

## Features

- **Addition** (+): Add two numbers
- **Subtraction** (-): Subtract two numbers
- **Multiplication** (\*): Multiply two numbers
- **Division** (/): Divide two numbers (with zero-division protection)
- **Input validation**: Handles invalid inputs gracefully
- **User-friendly interface**: Clear prompts and error messages

## How to Build and Run

### Using Make (Recommended)

```bash
# Compile the calculator
make

# Run the calculator
make run

# Clean up compiled files
make clean
```

### Manual Compilation

```bash
# Compile manually
g++ -std=c++11 -Wall -Wextra -O2 -o calculator calculator.cpp

# Run the calculator
./calculator
```

## How to Use

1. Run the calculator
2. Enter the first number when prompted
3. Choose an operation (+, -, \*, /)
4. Enter the second number when prompted
5. View the result
6. Repeat or type 'q' to quit

## Example Usage

```
=== Basic Calculator ===
Operations: +, -, *, /
Type 'q' to quit
========================

Enter first number: 15
Enter operation (+, -, *, /): +
Enter second number: 25
Result: 15.00 + 25.00 = 40.00

Enter first number: 100
Enter operation (+, -, *, /): /
Enter second number: 4
Result: 100.00 / 4.00 = 25.00

Enter first number: q
Thank you for using the calculator!
```

## Error Handling

- **Division by zero**: Displays error message and continues
- **Invalid numbers**: Prompts user to re-enter valid numbers
- **Invalid operations**: Prompts user to enter valid operation (+, -, \*, /)

## Requirements

- C++11 compatible compiler (g++, clang++, etc.)
- Make (optional, for using Makefile)

## File Structure

```
Calculator-app/
├── calculator.cpp    # Main calculator source code
├── Makefile         # Build configuration
└── README.md        # This file
```

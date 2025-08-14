#include <iostream>
#include <iomanip>
#include <limits>

class Calculator {
public:
    void run() {
        std::cout << "=== Basic Calculator ===" << std::endl;
        std::cout << "Operations: +, -, *, /" << std::endl;
        std::cout << "Type 'q' to quit" << std::endl;
        std::cout << "========================" << std::endl;
        
        while (true) {
            double num1, num2;
            char operation;
            
            // Get first number
            std::cout << "\nEnter first number: ";
            if (!getNumber(num1)) {
                break; // User wants to quit
            }
            
            // Get operation
            std::cout << "Enter operation (+, -, *, /): ";
            std::cin >> operation;
            
            if (operation == 'q' || operation == 'Q') {
                break;
            }
            
            if (!isValidOperation(operation)) {
                std::cout << "Invalid operation! Please use +, -, *, or /" << std::endl;
                clearInput();
                continue;
            }
            
            // Get second number
            std::cout << "Enter second number: ";
            if (!getNumber(num2)) {
                break; // User wants to quit
            }
            
            // Perform calculation
            double result = calculate(num1, num2, operation);
            
            // Display result
            if (result != std::numeric_limits<double>::quiet_NaN()) {
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << std::endl;
            }
        }
        
        std::cout << "Thank you for using the calculator!" << std::endl;
    }

private:
    bool getNumber(double &num) {
        std::string input;
        std::cin >> input;
        
        if (input == "q" || input == "Q") {
            return false;
        }
        
        try {
            num = std::stod(input);
            return true;
        } catch (const std::exception&) {
            std::cout << "Invalid number! Please enter a valid number." << std::endl;
            clearInput();
            return getNumber(num); // Recursively ask for valid input
        }
    }
    
    bool isValidOperation(char op) {
        return (op == '+' || op == '-' || op == '*' || op == '/');
    }
    
    double calculate(double num1, double num2, char operation) {
        switch (operation) {
            case '+':
                return add(num1, num2);
            case '-':
                return subtract(num1, num2);
            case '*':
                return multiply(num1, num2);
            case '/':
                return divide(num1, num2);
            default:
                std::cout << "Error: Invalid operation" << std::endl;
                return std::numeric_limits<double>::quiet_NaN();
        }
    }
    
    double add(double a, double b) {
        return a + b;
    }
    
    double subtract(double a, double b) {
        return a - b;
    }
    
    double multiply(double a, double b) {
        return a * b;
    }
    
    double divide(double a, double b) {
        if (b == 0) {
            std::cout << "Error: Division by zero is not allowed!" << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
        }
        return a / b;
    }
    
    void clearInput() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
};

int main() {
    Calculator calc;
    calc.run();
    return 0;
}

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

bool isOperatorGreaterOrEqual(char op1, char op2) {
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) {
        return true;
    }
    return false;
}

void applyOperation(std::stack<int>& numbers, std::stack<char>& operations) {
    int operand2 = numbers.top();
    numbers.pop();

    int operand1 = numbers.top();
    numbers.pop();

    char operation = operations.top();
    operations.pop();

    int result;
    switch (operation) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            // Handle division (you can add more checks if needed)
            if (operand2 != 0) {
                result = operand1 / operand2;
            } else {
                // std::cerr << "Error: Division by zero." << std::endl;
                break; // Error, division by zero
            }
            break;
        default:
            std::cerr << "Error: Invalid operation." << std::endl;
            break; // Error, invalid operation
    }

    numbers.push(result);
}


int calculateExpression(const std::string& expression) {
    std::istringstream iss(expression);
    std::stack<int> numbers;
    std::stack<char> operations;

    char token;
    while (iss >> token) {
        if (isdigit(token)) {
            iss.putback(token);
            int number;
            iss >> number;
            numbers.push(number);
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            while (!operations.empty() && isOperatorGreaterOrEqual(operations.top(), token)) {
                applyOperation(numbers, operations);
            }
            operations.push(token);
        }
    }

    while (!operations.empty()) {
        applyOperation(numbers, operations);
    }

    return numbers.top();
}


int main() {
    // Get input symbols from the user
    while (true) {
        std::string symbols;
        std::cout << "Enter the symbols (e.g., '+-*/'): ";
        std::cin >> symbols;

        // Initialize the expression with the first natural number
        std::string expression;
        expression += "1";

        // Insert natural numbers between symbols
        for (size_t i = 0; i < symbols.size(); ++i) {
            expression += symbols[i];
            expression += std::to_string(i + 2);
        }

        // Perform calculation
        int result = calculateExpression(expression);

        // Print the expression and result
        std::cout << "Output: " << result << std::endl;
    }

    return 0;
}

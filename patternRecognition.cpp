#include <iostream>

int patternRecognition(int x) {
    // Extract the last digit
    int lastDigit = x % 10;

    // Subtract the square of the last digit from the input
    return x - (lastDigit * lastDigit);
}

int main() {
    // Get input from the user
    while(true){
    int input;
    std::cout << "Input: ";
    std::cin >> input;

    // Perform pattern recognition
    int result = patternRecognition(input);

    // Print the result
    std::cout << "Output: " << result << std::endl;
    }
    
    return 0;
}

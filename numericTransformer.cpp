#include <iostream>

int numericTransformation(int x) {
    return (x * x) - 15;
}

int main() {
    // Get input from the user
    while(true){
        int input;
        std::cout << "Input: ";
        std::cin >> input;

        // Perform numeric transformation
        int result = numericTransformation(input);

        // Print the result
        std::cout << "Output: "<<result << std::endl;
    }
    std::cin.get();
    return 0;
}

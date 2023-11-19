#include <iostream>
#include <string>

std::string wordFormation(const std::string& word1, const std::string& word2) {
    std::string result;

    // Assuming both words have the same length
    for (size_t i = 0; i < word1.length(); ++i) {
        result += word1[i];
        result += word2[i];
    }

    return result;
}

int main() {
    // Get input words from the user
    while(true){
    std::string word1, word2;
    std::cout << "Input1: ";
    std::cin >> word1;
    std::cout << "Input2: ";
    std::cin >> word2;

    // Perform word formation
    std::string result = wordFormation(word1, word2);

    // Print the result
    std::cout << "Output: " << result << std::endl;
    }

    return 0;
}

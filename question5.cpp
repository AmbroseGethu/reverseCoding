#include <iostream>
#include <cmath>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= std::sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to find the nth prime number
int nthPrime(int n) {
    int count = 0;
    int num = 2;
    while (true) {
        if (isPrime(num)) {
            ++count;
        }
        if (count == n) {
            return num;
        }
        ++num;
    }
}

// Function to calculate the output based on the pattern
int calculateOutput(int position) {
    return position * position + nthPrime(position);
}

int main() {
    // Calculate and display the output for n = 5
    while(true){
    int i;
    std::cout<<"INPUT: ";
    std::cin>>i;
    int result = calculateOutput(i);
    
    // Print the result
    std::cout << "Output for n = 5: " << result << std::endl;
    }
    return 0;
}

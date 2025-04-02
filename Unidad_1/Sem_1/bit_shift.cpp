#include <iostream>
#include <bitset>

//2 understand negative shifting https://chatgpt.com/share/67edbe52-f094-800c-838d-552d05f01625

void displayShift(const std::string& description, int number, int shift, bool leftShift) {
    std::cout << description << "\n";
    std::cout << "Original number (decimal): " << number << "\n";
    std::cout << "Original number (binary): " << std::bitset<8>(number) << "\n";

    int shifted = leftShift ? (number << shift) : (number >> shift);

    std::cout << (leftShift ? "Left" : "Right") << " shifted by " << shift << ":\n";
    std::cout << "Shifted number (decimal): " << shifted << "\n";
    std::cout << "Shifted number (binary): " << std::bitset<8>(shifted) << "\n\n";
}

int main() {
    // Example 1: Left shift with sign bit 0
    int num1 = 10; // Binary: 00001010
    displayShift("Example 1: Left shift with sign bit 0", num1, 2, true);

    // Example 2: Left shift with sign bit 1
    int num2 = -10; // Binary: 11110110 (two's complement representation)
    displayShift("Example 2: Left shift with sign bit 1", num2, 2, true);

    // Example 3: Right shift with sign bit 0
    int num3 = 10; // Binary: 00001010
    displayShift("Example 3: Right shift with sign bit 0", num3, 2, false);

    // Example 4: Right shift with sign bit 1
    int num4 = -10; // Binary: 11110110 (two's complement representation)
    displayShift("Example 4: Right shift with sign bit 1", num4, 2, false);

    return 0;
}
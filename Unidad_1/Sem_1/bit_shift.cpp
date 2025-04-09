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
    int num4 = -5; // Binary: 11110110 (two's complement representation)
    displayShift("Example 4: Right shift with sign bit 1", num4, 2, false);

    // Example 5: Left shift with INT_MAX
    int num5 = INT_MAX; // Binary: 01111111... (platform-dependent size) (undefined behaviour)
    displayShift("Example 5: Left shift with INT_MAX", num5, 2, true);

    // Example 6: Right shift with a large shift value
    int num6 = 15; // Binary: 00001111
    displayShift("Example 6: Right shift with a large shift value", num6, 10, false);

    // Example 7: Left shift with zero
    int num7 = 0; // Binary: 00000000
    displayShift("Example 7: Left shift with zero", num7, 3, true);

    // Example 8: Right shift with zero
    int num8 = 0; // Binary: 00000000
    displayShift("Example 8: Right shift with zero", num8, 3, false);

    // Example 9: Shift with negative shift value (undefined behavior)
    // Uncommenting the following line may cause undefined behavior
    // displayShift("Example 9: Shift with negative shift value", num1, -2, true);

    // Example 10: Shift with negative number to a positive number 
    int num9 = -2; // Binary: 11111110 (two's complement representation)
    displayShift("Example 10: Shift with negative number to a positive number", num9, 5, false); //-1
    

    std::cout<<"-2 in 3 bits: "<<std::bitset<3>(-2)<< "\n";

    return 0;
}
#include <iostream>
using namespace std;

void decimalToBinary(int n) {
    if (n > 1) {
        decimalToBinary(n / 2);
    }
    cout << (n % 2);
}

int main() {
    int num;
    cout << "Introduce un numero decimal: ";
    cin >> num;

    cout << "El número en binario es: ";
    decimalToBinary(num);
    cout << endl;

    return 0;
}

/*
10

f(10) -> f(5) -> f(2) -> f(1) 
f(1): 1
f(2): 0
f(5): 1
f(10): 0
"1010"
*/
#include <iostream>
using namespace std;

void foo2(int b){
    if(b > 1){
        foo2(b-1);
    }
    cout<<"*";
}

void foo(int a, int b) {
    if (a > 0) {
        foo(a - 1, b);
        foo2(b);
        cout<<endl;
    }
}

int main() {
    int altura;
    cout << "Introduce la altura: ";
    cin >> altura;

    int base;
    cout << "Introduce la base: ";
    cin >> base;

    foo(altura, base);

    return 0;
}


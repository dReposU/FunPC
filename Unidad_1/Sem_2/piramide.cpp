#include <iostream>
using namespace std;

void sumR(int n){
    if (n > 1){
        sumR(n-1);
    }
    cout<<n;
}

void foo(int n) {
    if (n > 1){
        foo(n - 1);
    }
    sumR(n);
    cout<<endl;
}

int main() {
    int num;
    cout << "Introduce un numero: ";
    cin >> num;

    foo(num);
    return 0;
}


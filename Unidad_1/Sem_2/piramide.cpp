#include <iostream>
using namespace std;

void foo(int n) {
    if (n > 1){
        foo(n - 1);
    }
    for (int i = 1; i <= n; i++){
        cout << i;
    }
    cout<<endl;
}

int main() {
    int num;
    cout << "Introduce un numero: ";
    cin >> num;

    foo(num);
    return 0;
}


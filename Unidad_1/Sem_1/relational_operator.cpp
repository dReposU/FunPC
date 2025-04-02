//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2113
#include <iostream>

int main (){
    int t;
    std::cin >> t;

    while (t--) {
        long long a, b;
        std::cin >> a >> b;
        std::cout << (a > b ? ">" : (a < b ? "<" : "=")) << std::endl;
    }
    return 0;
}
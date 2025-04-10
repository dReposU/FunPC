#include <iostream>
#include <vector>

void cribaDeEratostenes(int n) {
    std::vector<bool> esPrimo(n + 1, true);
    esPrimo[0] = esPrimo[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (esPrimo[i]) {
            for (int j = i * i; j <= n; j += i) {
                esPrimo[j] = false;
            }
        }
    }

    std::cout << "Números primos hasta " << n << ": ";
    for (int i = 2; i <= n; ++i) {
        if (esPrimo[i]) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
}

int main() {
    int limite;
    std::cout << "Introduce el límite superior: ";
    std::cin >> limite;

    cribaDeEratostenes(limite);

    return 0;
}

/*
Optimización del for anidado j = i * i
Básicamente porque no es necesario volver a marcar los múltiplos de i que ya han sido marcados por números menores a i.
Por ejemplo, si i = 5, los múltiplos de 5 (10, 15, 20, ...) ya han sido marcados por el 2 y el 3. Por lo tanto, comenzamos a marcar desde i * i.
Esto reduce el número de iteraciones y mejora la eficiencia del algoritmo.
https://chatgpt.com/share/67f704d8-0114-800c-9204-eb0c66477630
*/
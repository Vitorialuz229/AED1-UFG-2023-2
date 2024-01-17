#include <stdio.h>

// Função para calcular o fatorial duplo de n
int fatorialDuplo(int n) {
    // Caso base: ¨f(1) = 1 e ¨f(2) = 1
    if (n == 1 || n == 2) {
        return 1;
    }

    // Caso ¨f(n) seja ímpar
    if (n % 2 != 0) {
        return n * fatorialDuplo(n - 2);
    }

    // Caso ¨f(n) seja par
    return fatorialDuplo(n - 1);
}

int main() {
    int n;

    // Leitura do valor de n
    scanf("%d", &n);

    // Cálculo e impressão do fatorial duplo de n
    printf("%d\n", fatorialDuplo(n));

    return 0;
}

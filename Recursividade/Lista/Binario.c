/*Escreva um programa, em C, que receba um número natural n ∈ N, 
representado utilizando a notação decimal, e o converta para sua 
notação binária. O programa deve utilizar uma “função recursiva” para
realizar a conversão.*/
#include <stdio.h>

// Função recursiva para converter decimal para binário
void decimalParaBinario(int n) {
    if (n > 0) {
        decimalParaBinario(n / 2);
        printf("%d", n % 2);
    }
}

int main() {
    int k, i, numero;

    // Leitura do número de casos de teste
    scanf("%d", &k);

    // Processamento de cada caso de teste
    for (i = 0; i < k; i++) {
        // Leitura do número a ser convertido
        scanf("%d", &numero);

        // Impressão do resultado
        decimalParaBinario(numero);
        printf("\n");
    }

    return 0;
}

/*Escreva um programa, em C, que receba um número natural n ∈ N, 
representado utilizando a notação decimal, e o converta para sua 
notação binária. O programa deve utilizar uma “função recursiva” para
realizar a conversão.*/
#include <stdio.h>

// Função recursiva para converter um número decimal para binário
void decimalParaBinario(int n) {
    if (n > 0) {
        decimalParaBinario(n / 2);
        printf("%d", n % 2);
    }
}

int main() {
    int k;

    // Leitura do número de casos de teste
    scanf("%d", &k);

    // Processamento de cada caso de teste
    for (int i = 0; i < k; i++) {
        int ni;

        // Leitura do número decimal a ser convertido
        scanf("%d", &ni);

        // Impressão da representação binária
        decimalParaBinario(ni);
        printf("\n");
    }

    return 0;
}
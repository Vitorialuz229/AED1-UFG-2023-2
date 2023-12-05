#include <stdio.h>

// Função para contar o número de pares (i, j) com i < j, cuja soma é máxima
int contarParesMaximos(int A[], int n, int i, int j, int maxSum) {
    // Caso base: se i ou j ultrapassarem os limites do vetor
    if (i >= n || j >= n) {
        return 0;
    }

    // Verificar se a soma dos elementos nos índices i e j é máxima
    if (A[i] + A[j] == maxSum) {
        // Se sim, incrementar o contador e chamar recursivamente para o próximo j
        return 1 + contarParesMaximos(A, n, i, j + 1, maxSum);
    } else if (A[i] + A[j] < maxSum) {
        // Se a soma for menor, chamar recursivamente para o próximo i
        return contarParesMaximos(A, n, i + 1, j, maxSum);
    } else {
        // Se a soma for maior, chamar recursivamente para o próximo j
        return contarParesMaximos(A, n, i, j + 1, maxSum);
    }
}

int main() {
    int t; // Número de casos de teste
    scanf("%d", &t);

    while (t--) {
        int n; // Número de elementos no vetor A
        scanf("%d", &n);

        int A[n]; // Vetor A
        int i =0;
        for (i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }

        int maxSum = 0; // Inicializar a soma máxima como 0

        // Calcular a soma máxima
        int j;
        for (i = 0; i < n - 1; i++) {
            for ( j = i + 1; j < n; j++) {
                if (A[i] + A[j] > maxSum) {
                    maxSum = A[i] + A[j];
                }
            }
        }

        // Contar o número de pares com a soma máxima usando a função recursiva
        int result = contarParesMaximos(A, n, 0, 1, maxSum);

        // Imprimir o resultado para o caso atual
        printf("%d\n", result);
    }

    return 0;
}

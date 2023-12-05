#include <stdio.h>

// Função para verificar se um número é primo
int isPrime(int num, int divisor) {
    if (divisor <= 1) {
        return 1; // Se o divisor chegou a 1, o número é primo
    } else {
        if (num % divisor == 0) {
            return 0; // Se o número é divisível pelo divisor, não é primo
        } else {
            // Chamar recursivamente com um divisor menor
            return isPrime(num, divisor - 1);
        }
    }
}

// Função para imprimir os números primos e calcular a soma
void printPrimes(int A[], int n, int i, int primes[], int sum) {
    int j;
    if (i < n) {
        int num = 1; // Iniciar com o primeiro número primo (2)
        for (j = 0; j < A[i]; j++) {
            do {
                num++; // Procurar o próximo número primo
            } while (!isPrime(num, num - 1));
        }
        
        primes[i] = num;
        sum += num;
        
        printPrimes(A, n, i + 1, primes, sum);
    } else {
        // Ordenar os números primos antes de imprimir
        int k, l;
        for (k = 0; k < n - 1; k++) {
            for (l = k + 1; l < n; l++) {
                if (primes[k] > primes[l]) {
                    // Trocar os elementos se estiverem fora de ordem
                    int temp = primes[k];
                    primes[k] = primes[l];
                    primes[l] = temp;
                }
            }
        }

        // Imprimir os números primos ordenados
        for (k = 0; k < n; k++) {
            printf("%d ", primes[k]);
        }

        printf("\n%d\n", sum);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int A[n];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int primes[n];
    printPrimes(A, n, 0, primes, 0);

    return 0;
}

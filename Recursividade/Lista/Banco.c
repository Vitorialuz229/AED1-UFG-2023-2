#include <stdio.h>

// Define os valores das notas
#define N2 2
#define N5 5
#define N10 10
#define N20 20
#define N50 50
#define N100 100

// Define o número de tipos de notas
#define N 6

// Define os valores das notas em um vetor global
int V[N] = {N2, N5, N10, N20, N50, N100};

// Função auxiliar recursiva que recebe o valor do saque, as quantidades de notas de cada tipo, o vetor de valores das notas e o índice do tipo de nota atual
int aux(int S, int Q[], int V[], int i) {
  // Se o valor do saque é zero, há uma única maneira de obter o valor
  if (S == 0) {
    return 1;
  }
  // Se o valor do saque é negativo ou não há mais tipos de notas, não há nenhuma maneira de obter o valor
  if (S < 0 || i == N) {
    return 0;
  }

  int num_ways = 0;
  int k;
  // Tenta usar uma quantidade k de notas do tipo atual, onde k varia de 0 até a quantidade disponível
  for (k = 0; k <= Q[i]; k++) {
    if (S - k * V[i] >= 0) {
      num_ways += aux(S - k * V[i], Q, V, i + 1);
    }
  }

  return num_ways;
}

// Função principal que recebe o valor do saque e as quantidades de notas de cada tipo
int saque(int S, int Q[]) {
  // Chama a função auxiliar com o índice inicial zero e o vetor global de valores das notas
  return aux(S, Q, V, 0);
}

int main() {
  // Declara as variáveis
  int S; // Valor do saque
  int Q[N]; // Quantidade de notas de cada tipo
  int i; // Índice para percorrer o vetor Q

  // Lê o valor do saque
  printf("Digite o valor do saque: ");
  scanf("%d", &S);

  // Lê as quantidades de notas de cada tipo
  printf("Digite as quantidades de notas de 2, 5, 10, 20, 50 e 100 reais: ");
  for (i = 0; i < N; i++) {
    scanf("%d", &Q[i]);
  }

  // Imprime o resultado da função saque
  printf("O número de maneiras distintas de entregar o valor %d ao cliente é: %d\n", S, saque(S, Q));

  return 0;
}
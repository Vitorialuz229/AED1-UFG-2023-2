#include <stdio.h>

// Função recursiva que encontra o representante de um elemento x, usando o vetor P
int busca(int x, int P[], int n) {
  // Se o pai de x é o próprio x, então x é o representante do seu subconjunto
  if (P[x] == x) {
    return x;
  }
  // Senão, procura o representante do pai de x de forma recursiva, e atualiza o pai de x para esse representante, otimizando as buscas futuras
  else {
    P[x] = busca(P[x], P, n);
    return P[x];
  }
}

// Função que une os subconjuntos que contêm os elementos x e y, usando o vetor P
void uniao(int x, int y, int P[], int n) {
  // Encontra os representantes de x e y
  int rep_x = busca(x, P, n);
  int rep_y = busca(y, P, n);
  // Se os representantes são diferentes, significa que x e y estão em famílias distintas
  if (rep_x != rep_y) {
    // Faz com que o representante de x seja o pai do representante de y, unindo as famílias
    P[rep_x] = rep_y;
  }
}

int main() {
  // Declara as variáveis
  int n, m; // Número de pessoas e número de linhas do arquivo de entrada
  int x, y; // Números que identificam um par de pessoas da mesma família
  int num_fam; // Número de famílias distintas
  int i; // Índice para percorrer o vetor P

  // Lê o número de pessoas e o número de linhas do arquivo de entrada
  scanf("%d %d", &n, &m);

  // Vetor que armazena o pai de cada elemento
  int P[n];
  
  // Inicializa o vetor P, fazendo com que cada elemento seja o seu próprio pai
  for (i = 0; i < n; i++) {
    P[i] = i;
  }

  // Lê as m linhas do arquivo de entrada, que contêm os pares de pessoas da mesma família
  for (i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    // Faz a união dos subconjuntos que contêm x e y
    uniao(x, y, P, n);
  }

  // Inicializa o número de famílias distintas como zero
  num_fam = 0;

  // Percorre o vetor P, contando quantos elementos são os seus próprios pais, ou seja, quantos elementos são representantes de subconjuntos
  for (i = 0; i < n; i++) {
    if (busca(i, P, n) == i) {
      num_fam++;
    }
  }

  // Imprime o número de famílias distintas
  printf("%d\n", num_fam);

  return 0;
}

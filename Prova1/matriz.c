/*Escrever, utilizando a linguagem de programação C, um programa que seja capaz de
receber como entrada três números naturais (n, x e y), necessariamente nesta ordem e
numa única linha, e imprimir uma matriz moldura de ordem n × n, sendo x o valor da
moldura externa e y o valor da moldura interna [veja a explicação do conceito adiante
neste texto].
Sabe-se que os valores obedecem às seguintes regras:
• 1 ≤ n ≤ 100;
• 1 ≤ x, y < 10 e x̸ = y;
• n é sempre um número ímpar*/
 
    #include <stdio.h>
     
    void preencher(int matriz[][100], int n, int x, int y, int linha, int coluna) {
        if (linha < n && coluna < n) {
            if (linha == 0 || linha == n - 1 || coluna == 0 || coluna == n - 1) {
                matriz[linha][coluna] = x; // Preenche valores na moldura externa
            } else {
                if (linha <= coluna && linha <= n - 1 - coluna && linha >= n / 2) {
                    matriz[linha][coluna] = x; // Preenche valores na moldura externa
                } else {
                    matriz[linha][coluna] = y; // Preenche valores na moldura interna
                }
            }
     
        // Move para a próxima coluna ou próxima linha quando a coluna estiver completa
            if (coluna == n -1 ) {
                preencher(matriz, n, x, y, linha + 1, 0);
            } else {
                preencher(matriz, n, x, y, linha, coluna + 1);
            }
        }
    }
     
    void imprimirMatriz(int matriz[][100], int n) {
        int i =0, j=0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
    }
     
    int main() {
        int n, x, y;
     
        // Recebe os valores de entrada
        scanf("%d %d %d", &n, &x, &y);
     
        // Verifica se os valores de entrada obedecem às regras
        if (n % 2 == 0 || n < 1 || n > 100 || x < 1 || x >= 10 || y < 0 || y >= 10 || x == y) {
            printf("Entrada inválida.\n");
            return 1;
        }
     
        int matriz[100][100] = {0}; // Inicializa a matriz com zeros
     
        // Preenche a matriz
        preencher(matriz, n, x, y, 0, 0);
     
        // Imprime a matriz preenchida
        imprimirMatriz(matriz, n);
     
        return 0;
    }
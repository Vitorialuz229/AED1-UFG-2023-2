/*Ada, uma programadora de jogos digitais educacionais, deseja
criar um novo jogo que envolva palavras de diferentes idiomas, como 
Português e Inglês, por exemplo.
Para isto uma de suas necessidades é ter uma rotina que seja capaz 
de, dada uma cadeia de caracteres S a ela, gerar “todos os possíveis
anagramas distintos daquela cadeia”*/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
// Função para trocar os caracteres de duas posições em uma string
void trocar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
 
// Função recursiva para gerar anagramas
void gerarAnagramas(char *str, int inicio, int fim) {
    if (inicio == fim) {
        printf("%s\n", str);
        return;
    }
    int i; 
    for (i = inicio; i <= fim; i++) {
        // Evita repetições trocando apenas caracteres distintos
        if (i != inicio && str[i] == str[inicio])
            continue;
 
        // Troca os caracteres
        trocar(&str[inicio], &str[i]);
 
        // Chama recursivamente para a parte restante
        gerarAnagramas(str, inicio + 1, fim);
 
        // Desfaz a troca para explorar outras possibilidades
        trocar(&str[inicio], &str[i]);
    }
}
 
// Função principal
int main() {
    // Recebe a cadeia de caracteres
    char str[257];
    scanf("%s", str);
 
    // Ordena a string para garantir a ordem alfabética crescente
    int len = strlen(str);
    qsort(str, len, sizeof(char), (int (*)(const void *, const void *))strcmp);
 
    // Chama a função para gerar anagramas
    gerarAnagramas(str, 0, len - 1);
 
    return 0;
}
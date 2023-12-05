//Exercício 17 boca
//Exercício 3 - Recursividade

/*Uma das versões mais comuns, a Função de Ackermann-Péter, que possui apenas dois argumentos,
é definida a seguir para números naturais m e n:
fack(m,n) =
    (n+1), se m = 0
    fack(m−1,1), se n = 0,m > 0
    fack(m−1, fack(m,n−1)), se n > 0,m > 0

Entrada
A única linha da entrada contém dois números naturais m e n separados por um único espaço em branco,
nesta ordem, representando os parâmetros para a Função de Ackermann.
*/
#include <stdio.h>
#include <stdlib.h>
//
// Funcao de Ackermann - Programa Principal
//
unsigned long int ackermann(unsigned long int m, unsigned long int n) {
        
    if (m == 0) {
       return(n + 1);
    }
    if (n == 0) { 
       return (ackermann(m - 1, 1));
    }  
    return (ackermann(m - 1, ackermann(m, n - 1)));
}
int main() {
    unsigned long int m, n;
    
    scanf("%lu %lu", &m, &n);
    printf("%lu", ackermann(m, n));
    return 0;
}



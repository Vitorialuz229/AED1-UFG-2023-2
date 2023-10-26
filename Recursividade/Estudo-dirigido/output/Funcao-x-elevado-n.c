#include <stdio.h> 
#include <stdlib.h>

/*Explicando: 
4 = 2 * 2
5 = 3 * 3 
*/

int potencia(int x, int n){ 
    if(n == 0)
        return 1; 
    else 
        return x * potencia(x, n - 1);
}

int main() { 
    int x, n; 

    printf("Digite o valor para 'x' e para 'n': ");
    scanf("%d%d", &x, &n);

    printf("Resultado de %d elevado a %d: %d\n", x, n, potencia(x, n));
}
#include <stdio.h>
#include <stdlib.h>

int eh_primo(long numero)
{
    long divisor = 3;
    long metade_numero = numero / 2;
    
    if (numero != 2 && numero % 2 == 0) return 0; // Composto
    
    while (divisor < metade_numero){
        if (numero % divisor != 0){
            divisor += 2;
        }
        else{
            return 0;
        }
    }
    
    return 1; // Primo
}

int main (void)
{
    int entradas, temp, i;
    long* numeros = NULL;
    char* textos[] = {"composto", "primo"};
    
    scanf(" %d", &entradas);
    numeros = malloc(sizeof (long*) * entradas);
    
    for (i = 0; i < entradas; i++){
        scanf(" %ld", &numeros[i]);
    }
    
    for (i = 0; i < entradas; i++){
        temp = eh_primo(numeros[i]);
        printf("%s\n", textos[temp]);
    }
    
    return 0;
}
//Conversão de decimal para binário (++)
//Exercicio 19 boca
//Exercicio 5 lista de recursão

/*Escreva um programa, em C, que receba um número natural n ∈ N, representado utilizando a notação
decimal, e o converta para sua notação binária. O programa deve utilizar uma “função recursiva” para
realizar a conversão*/

#include <stdlib.h>
#define K_MIN 1
#define K_MAX 1000
#define N_MIN 1
#define N_MAX 1000000

void decimalParaBinario(unsigned int n);

int main(){
    unsigned int *vetor;
    unsigned int k, i;

    do{
        scanf("%u", &k);
    } while(k < K_MIN || k > K_MAX);

    vetor = (unsigned int*) malloc(sizeof(unsigned int)*k);

    for(i=0; i<k; i++){
        do{
            scanf("%u", &vetor[i]);
        } while(vetor[i] < N_MIN || vetor[i] > N_MAX);
    }

    for(i=0; i<k; i++){
        decimalParaBinario(vetor[i]);
        printf("\n");
    }

    return 0;
}

void decimalParaBinario(unsigned int n){
    if(n/2 > 0)//Se n / 2 for maior que 0
    //a função chama a si mesma recursivamente, dividindo n por 2.
        decimalParaBinario(n/2);
    
    printf("%u", (n%2));
}
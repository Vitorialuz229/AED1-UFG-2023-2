//Exercicio 18 no boca 
//Exercicio 5 - Conversão de decimal para binário

/*Escreva um programa, em C, que receba um número natural n ∈ N, representado utilizando a notação
decimal, e o converta para sua notação binária. O programa deve utilizar uma “função recursiva” para
realizar a conversão.*/

#include <stdio.h> 
#include <stdlib.h> 
#define MIN 1
#define MAX 1000000

void inverterecursivo(unsigned int n) { 

	if(n < 10) {
	printf("%d", n); 
	}
	else { 
		printf("%d", n%10); 
		inverterecursivo (n/10); 
		 } 
}	 
	int main (){ 
	unsigned int n; 
		
	do { 
		scanf("%d", &n); 
    }while ((n < MIN) || (n > MAX));
			
	inverterecursivo(n);
			
return 0;
} 
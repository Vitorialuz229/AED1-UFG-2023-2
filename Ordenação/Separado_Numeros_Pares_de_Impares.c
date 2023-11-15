//Exercicío 2 - Separando Números Pares de Ímpares 
//Ex: 54

/*Sabe-se que na caixa havia n ∈ N∗ números, com (1 < n ≤ 100), mas seus valores são desconhecidos.
Sua tarefa é conceber um programa C que seja capaz de ordenar esta fila, segundo as seguintes regras:
• primeiro devem vir todos os números pares, em ordem crescente;
• depois devem vir os números ímpares, em ordem decrescente*/

#include <stdio.h>
#define TAM 100

void troca (int *x, int *y){
	int aux;
	aux=*x;
	*x=*y;
	*y=aux;
}
void bubble(int v[], int n){
	int  i,j;
	for (i=1; i<n; i++) {
		for (j=0; j<n-i; j++) {
			if (v[j]>v[j+1]) {
				troca(&v[j], &v[j+1]);
			}
		}
	}
}


int main(){
	int vet[TAM],i, n;
	scanf("%d", &n);
	//Ler o vetor
	for (i=0; i<n; i++) {
       scanf("%d", &vet[i]);
	}
	//imprime o vetor lido
	
	bubble(vet,n);
	//imprime o vetor ordenado para pares
	for(i=0; i<n; i++){
	  if(vet[i]%2==0)
	    printf("%d ", vet[i]);
	  }
	 printf("\n");
	 //imprime o vetor em ordem decrescente para impares
	for(i=n-1; i>=0; i--){
	  if(vet[i]%2!=0)
	    printf("%d ", vet[i]);
	  }
	 printf("\n");
	return(0);
}
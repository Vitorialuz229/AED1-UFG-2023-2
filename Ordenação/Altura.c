//Exercicio 3 - Altura 
//Ex: 55 

/*Na equipe, você foi designado para realizar a tarefa no conjunto de cidades com 10.000 ou menos habitantes.
Nestas cidades terá que ser coletada a altura de todos os habitantes. Segundo o IBGE não há, atualmente
no Brasil, nenhuma pessoa com mais que 230cm de altura.
Entrada
A primeira linha de entrada contém um número natural ηC, ηC < 100, que indica a quantidade de casos
de teste, ou seja, o número de cidades que será a seguir informado.
Cada caso de teste é formado por duas linhas:
A primeira linha contém um número natural n, 1 ≤ n ≤ 104, que indica a quantidade de pessoas daquela
cidade.
A segunda linha apresenta a altura de cada uma destas pessoas, em centímetros, representado pela letra h,
20 ≤ h ≤ 230, e separados por um espaço em branco entre si*/

#include <stdio.h>
#define TAM 10000

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
	int vet[TAM],i, n, ct;
	scanf("%d", &ct);
	while(ct--) {
	  scanf("%d", &n);
	  for(i=0; i<n; i++) {
	    scanf("%d", &vet[i]);
	  }
	 bubble(vet, n);
	 for(i=0; i<n-1;i++){
	   printf("%d ", vet[i]);
	 }
	 printf("%d\n", vet[i]); 
	}
	return 0;
}
	
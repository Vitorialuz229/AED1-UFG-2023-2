//Números Primos e Vetores (++)
//Exercicio 59 
//Exercicio 7 da Lista de Ordenação

#include <stdio.h>
#define N 100


// metodo bubble sort

void troca (int *x, int* y){
	int aux;
	aux=*x;
	*x=*y;
	*y=aux;
}
void bubble(int v[], int n){
	int  i,j;
	for (i=n-1; i>0; i--) {
		for (j=0; j<i; j++) {
			if (v[j]>v[j+1]) {
				troca(&v[j], &v[j+1]);
			}
		}
	}
}

void imprimeVet(int* v, int n){
	int i;
	for (i=0; i<n; i++) {
    printf("%d ", v[i]);
	}
	printf("\n");
}

int main() {
  int n, vetor[N], par, imp, i, vp[N], vi[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&vetor[i]);
   }
    par=0;imp=0;
    for(i=0;i<n;i++){
      if((vetor[i]%2)==0){
        vp[par] = vetor[i];
        par++;
      }else{ vi[imp]=vetor[i];
             imp++;
           }
      }
     if(par!=0){
       bubble(vp,par);
       imprimeVet(vp,par);
       }
      if(imp!=0){
        bubble(vi,imp);
         for(i=(imp-1);i>0; i--){
			 printf("%d ",vi[i]);
		 }
		 printf("%d\n",vi[i]);
       }

  return 0;
  }
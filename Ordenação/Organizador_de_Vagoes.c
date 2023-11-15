//Exercicíos 1 - Organizador de Vagões 
//Ex: 53

/*Para um dado trem com determinado número de vagões, qual é o 
número de trocas entre trens adjacentes que são necessárias para que 
o trem fique ordenado (em ordem crescente).*/

#include <stdio.h>
#define MAX 1000

int cont_troca(int v[], int n) {
  int cont=0, i, j;
  for(i=0; i<n-1; i++) {
    for(j=i; j<n; j++) {
       if(v[i]>v[j]){
         cont++;
       }
    }
 }
  return cont;
}

int main(){
  int trem[MAX], n, ct, i, cont=0;
  scanf("%d", &ct);
  while(ct--){
	scanf("%d", &n);
    for(i=0; i<n; i++) {
       scanf("%d", &trem[i]);
    }
   cont = cont_troca(trem, n);
   printf("%d\n", cont);
  }
return 0;
}
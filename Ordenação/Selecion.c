//Insertion - Selection(+)
//Exercicio 57 
//Exercicio 5 da lista de ordenação 

#include <stdio.h>
#define TAM 1000

int insertion_Sort(int* v, int n) {
  int count=0,i= 0;
  int j = 1;
  int aux = 0;
  while (j < n) {
    aux = v[j];
    i = j - 1;
    while ((i >= 0) && (v[i] > aux)) {
    //  printf("(%d <-> %d)\n", v[(i+1)], v[i]); 
      v[i + 1] = v[i];
      count++;
      i--; 
    }
   // printf("(%d <-> %d)\n", v[(i+1)], v[j]); 
    v[i + 1] = aux;
    count++;
    j++;
  }
  return (count);
}


// v : vetor; n : tamanho do vetor
int selectionSort(int* v, int n) {  
  int count=0, i, j, min, aux;
  for (i = 0; i < (n-1); i++) {
      min = i;
      for (j = (i+1); j < n; j++) {
          if (v[j] < v[min]) 
             min = j;
      }
      if (v[i] != v[min]) {
        // printf("(%d | %d)\n", v[i], v[min]); 
         aux = v[i];
         v[i] = v[min];
         v[min] = aux;
         count++;
      }
  }
  return (count);
}

int main() {
  int vet1[TAM],vet2[TAM], n, i, dif=0;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &vet1[i]);
    vet2[i] = vet1[i];  // vet1 e vet2 para enviar cada um em um proc. de ordenacao
  }
  dif = insertion_Sort(vet1, n) - selectionSort(vet2, n);
  
  printf("%d\n", dif);
  return 0;
  }
  
/*Considere que seja dado um número n, n ∈ N∗. Usando o conceito de 
recursividade, elabore um programa em C para  imprimir até o n-ésimo 
termo da “Série de Fibonacci”.
Observação: Note que a contagem dos termos foi iniciada com o termo 0 (zero): f0 = 0.
*/

#include <stdio.h>

long fib(long n) {

  if(n==0)
    return(0);
   else if(n==1)
          return(1);
         else if(n>=2)
                return(fib(n-1)+fib(n-2));
  
  }
         
  int main() {
    long n, i, j;
    scanf("%ld", &n);
  
    for(i=0; i<n+1;i++){
    j = fib(i);
    printf("%ld ", j);
   }
   printf("\n"); 
  return 0;

  }

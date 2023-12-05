//Exercicío 8 - Famílias de Tróia 
//Ex: 22
/*O arquivo de entrada consiste de (m+1) linhas.
A primeira linha do arquivo de entrada contém dois números naturais n e m. Onde n, n ∈ N, indica o
número de pessoas na população que, por simplicidade, são sempre numeradas de 1 a n e sabe-se que
1 ≤ n ≤ 5 × 104. O valor m indica a quantidade de linhas após a primeira linha, sendo que m ∈ N e
1 ≤ m ≤ 105.
As demais m linhas do arquivo de entrada contêm, cada uma, dois números naturais identificando um par de
pessoas daquela população por meio de seus números, sempre separados por um único espaço em branco.
Cada linha indica que as duas pessoas pertenciam a uma mesma família.*/
#include <stdio.h>
 
  long int fib(long int n){
   if(n==0)
     return(0);
    else if(n==1)
           return(1);
          else return(fib(n-1)+fib(n-2));
  }
  
  int main() {
    long int n, i;
    scanf("%ld", &n);
    for(i=0; i<n;i++)
       printf("%ld ",fib(i));
     printf("%ld\n",fib(i)); 
  return 0;
  }
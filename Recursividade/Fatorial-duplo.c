//Exercicio 20 
//Exercicio 6 lista de recursividade 

/*Você deve escrever uma função recursiva, em C, que seja 
capaz de, recebendo n, imprimir o valor de ¨f (n)*/

#include <stdio.h>

double fatorialDuplo(int n);

int main(){
    int n;
   
    scanf("%d", &n);
    if(n%2==0)
        printf("%.0lf", fatorialDuplo(n-1));
    else
        printf("%.0lf", fatorialDuplo(n));
    
    return 0;
}

double fatorialDuplo(int n){
    if(n == 1 || n == 2)
        return 1;
   
    else
        return n * fatorialDuplo(n - 2);
}
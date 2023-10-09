//Ex15 
//Exercício 1 de Recursividade 

/*
A partir deste conceito inicial a respeito dos números naturais, deseja-se que você escreva um programa,
em C, para imprimir os n primeiros números naturais usando o conceito de recursividade, que os define da
seguinte maneira:
n0 = 0
ni+1 = ni +1,i ∈ {0,1,2,...}
*/ 

#include <stdio.h>

int escrever(int num, int n) { 
    printf("%d ",num); 
    if(num == n-1) 
    return(0); 
    else return(escrever(num + 1, n));
}

int main() { 
    int n, i = 0; 
    scanf("%d", &n); 
    i++;
    i = escrever(1, n);
    printf("%d", n);

return 0; 
}

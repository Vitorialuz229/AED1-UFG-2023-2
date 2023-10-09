//Exercício 2 de recursividade - Sequência de Fibonacci recursiva (+) 
//Exercício 16

/*
Sem dúvida a chamada “Sequência de Fibonacci” (ou “Sucessão de Fibonacci”) é uma das mais famosas
sequências numéricas da Matemática. Os dois primeiros termos desta sequência são:
f0 = 0 f1 = 1.
A partir do terceiro termo, cada termo é obtido somando-se os dois termos imediatamente anteriores a ele,
ou seja:
fn = fn−1 + fn−2, com n ∈ N e n ≥ 2
Portanto,os seus dez primeiros termos são 0,1,1,2,3,5,8,13,21,34.
*/

#include <stdio.h> 

long fib(long n) { 
    if(n == 0) {
     return(0); 
    } else if (n <=2){ 
        return (fib(n-1) + fibo(n-2));
    }
}

void main () { 
    int n, i; 
    scanf("%d", &n);
    i++; 
    
    printf("%d", n);

return 0; 
}
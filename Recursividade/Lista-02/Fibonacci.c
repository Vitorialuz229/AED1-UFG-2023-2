/*Considere que seja dado um número n, n ∈ N∗. Usando o conceito de 
recursividade, elabore um programa em C para  imprimir até o n-ésimo 
termo da “Série de Fibonacci”.
Observação: Note que a contagem dos termos foi iniciada com o termo 0 (zero): f0 = 0.
*/

#include <stdio.h> 

long fibonacci(long n) { 
    if(n == 0){ 
        return 0;
    } else if(n == 1){ 
        return 1;
    } else{ 
        return fibonacci(n - 1) + fibonacci (n - 2);
    }
}
int main () { 
int n, i; 
scanf("%d", &n); 

for (int i = 0; i < n; i++) { 
    printf("%d ", fibonacci(i));
}
return 0; 
}

//Exemplo: Calcula o enésimo termo da sequência de fibonacci
// 1 2 3 4 5
// 0 1 1 2 3 

#include <stdio.h> 
/* 
Ex: n = 6 
Verfica se o numero é 1 ou 2, se for falso 
(6 - 1) + (6+2)
fib5 + fib4
Empilha as duas e proccura na arvóre de recursão 
até chegar em todos os pontos de parada  */
int fibonacci(int n){ 
    if(n == 1)
        return 0; 
    else{ 
        if(n == 2) 
            return 1; 
        else //definição de enésimo n = (n-1) + (n+2)
            return fibonacci(n - 1) + fibonacci(n + 2); 
    }
}

int main(){ 
int n; 

printf("Digite o valor");
scanf("%d", &n); 

printf("O termo %d: %d\n", n, fibonacci);

return 0; 
}
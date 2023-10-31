//Faça uma função recursiva que calcule a soma dos números 
// inteiros de 1 a N. 

#include <stdio.h> 
/*Explicando: 
n = 4 
Ve se o n é igual a zero, caso falso 
4 + (4-1)
4 + 3 
chama a função agora com o valor 3 
Isso deve proceguir até o caso base*/
int soma(int n) { 
    if(n == 0) 
        return 0; 
    else
        return n + soma(n-1); 
}

int main(){ 

    int n; 

    printf("Digite N: "); 
    scanf("%d", &n); 

    printf("Soma de 1 ate %d: %d\n", n, soma(n));

return 0; 
}


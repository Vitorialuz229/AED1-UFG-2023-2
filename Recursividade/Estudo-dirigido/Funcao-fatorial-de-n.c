//Exemplo: Fazer uma função que calcula e retorna o fatorial de n
//4! = 4 * 3 * 2 * 1 = 24
//1! ou 0! = 1 

#include <stdio.h>
/* 
Explicando: 
2! = 2 * 1 
Entra na comparação, se falso 
Retorna n que é o número inserido multiplicado pelo fatorial anterior '5 * 4!'  */
int fatorial (int n){ 
    if(n == 1 || n == 0)
        return 1; 
    else {
      return n * fatorial(n-1); //Fatorial * o fatorial anterior 
    }
}

int main(){ 
    int n; 

    printf("Digite um valor maior que zero: "); 
    scanf("%d", &n);

    printf("Fatorial de  %d: %d\n", n, fatorial(n));
return 0; 
}
 
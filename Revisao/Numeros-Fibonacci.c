//Exercicio 13 
//Números de Fibonacci (++)

/*Escreva, em C, um programa que receba o valor de n conforme anteriormente definido, 3 ≤ n ≤ 100, e
escreva na saída o valor de fn correspondente.*/

#include <stdio.h>

unsigned long int fibonacci(int);

int main(){
    int testes, n;
    
    scanf("%d", &testes);
    
    while(testes--){
        scanf("%d", &n);
    
        printf("%lu\n", fibonacci(n));
    }
    
    return 0;
}

unsigned long int fibonacci(int n){                                          
    unsigned long int f1=1, f2=1, soma=0;         
    int i;
    
    if(n == 0) //Se n for 0, retorna 0.
        return 0;
    
    else if(n == 1 || n == 2)//Se n for 1 ou 2, retorna 1.
        return 1;
    
    else{//O loop começa de i = 3 (pois os casos iniciais já foram tratados) 
    //e vai até i <= n.
        for(i=3; i<=n; i++){                                        
            soma = f1 + f2;                    
            f1 = f2;                           
            f2 = soma;                           
        }
    }
    
    return f2;                             
}  
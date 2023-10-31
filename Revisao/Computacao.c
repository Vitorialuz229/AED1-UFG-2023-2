//Exercicio 5 - Computação (++)

/*A SBC contratou você para fazer um programa C que receba um número inteiro positivo, na base decimal,
e converta-o para a base 4 utilizando divisões sucessivas. Você deve escrever um programa que, a partir de
uma lista de números, calcule o valor correspondente de cada desses números na base 4.*/

#include <stdio.h>
#define N 10

int main(){
    int testes, num, i;
    
    scanf("%d", &testes);
    
    while(testes--){
        scanf("%d", &num);
        
        int restosNum[testes];
    
        i=0;
        
        while(num > 0 || i <= num){
            restosNum[i] = num%4;
            
            i++; num = num/4;
        }
        
        while(i--){
            switch(restosNum[i]){
                case 0: 
                    printf("A");
                    break;
                
                case 1:
                    printf("C");
                    break;
                
                case 2:
                    printf("G");
                    break;
                
                case 3:
                    printf("T");
                    break;
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
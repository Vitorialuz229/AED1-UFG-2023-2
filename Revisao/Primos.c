//Exercicio 8 (++)
/*que, desde Euclides, se envolveram nesse estranho mistério.
Você deverá, assim, pequisar e implementar, em C, um algoritmo que seja capaz de identificar se um dado
número inteiro positivo é, ou não, um número primo. Número que não é primo é denominado de composto.
*/
#include <stdio.h>

int primo(int);

int main(){
    int qtd, n;
    
    scanf("%d", &qtd);
    
    while(qtd--){
        scanf("%d", &n);
        
        if(primo(n) == 0){
            printf("primo");
        } else{
            printf("composto");
        }
        
        printf("\n");
    }
    
    return 0;
}

int primo(int n){
    int i, flag=0;
    
    for(i=2; i<n; i++){
        if(n%i == 0){
            flag++;
        } 
    }
    
    if(flag != 0){
        return -1;
    }
    
    return 0;
}
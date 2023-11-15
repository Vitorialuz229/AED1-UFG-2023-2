//Exercicio 6 - Envelope 
/*Você deve escrever um programa C que, a partir da lista de rótulos de Kurt, calcule o número máximo de
envelopes válidos que ele pode enviar para a promoção da SBC.*/

#include <stdio.h>

int main(){
    int qtdBalas, tiposProduzidos, tiposDeRotulos;
    int i=0, j=0, nMax=1001, count=0;
    
    scanf("%d %d", &qtdBalas, &tiposProduzidos);
    
    int rotulos[qtdBalas];
    
    while(i < qtdBalas){
        scanf("%d", &tiposDeRotulos);
        
        rotulos[j] = tiposDeRotulos;
        
        j++; i++;
    }
    
    j=0;
    
    for(i = 1; i <= tiposProduzidos; i++){
        
        while(j < qtdBalas){
            if(rotulos[j] == i)
                count++;
            
            j++;
        }
        
        if(count < nMax)
            nMax = count;
            
        count = 0; j=0;
    }
    
    printf("%d\n", nMax);
    
    return 0;
}
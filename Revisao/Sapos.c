//Exercicío 7 - Sapos (+++)
/*“Dado o número de pedras no rio – P –, o número de sapos – S, a pedra inicial sobre a qual cada sapo
está, sabendo-se que cada pedra é identificada por sua posição na sequência de pedras a partir da margem
do rio que está no “fundo” da casa dos avós de SBC – 1,2,3,... – e, por fim, a distância que cada sapo pula
– d1,d2,d3,...,dp –, determinar as posições onde pode existir pelo menos um sapo depois que SBC chega
no rio após assistir ao balé dos pulos dos sapos.”.
*/
#include <stdio.h>

int main(){
    int nPedras, nSapos, pInicial, dPulo;
    int i, j, posicao; 
    
    scanf("%d %d", &nPedras, &nSapos);
    
    int pedras[nPedras];
    
    for(i=0; i<nPedras; i++)
        pedras[i] = 0;
    
    for(i=0; i<nSapos; i++){
        scanf("%d %d", &pInicial, &dPulo);
        
        posicao = pInicial;
        
        for(j=0; j<nPedras; j++){
            for(posicao = pInicial; posicao <= nPedras; posicao += dPulo)
                if(pedras[j] == 0 && posicao-1 == j)
                    pedras[j] = 1;
        }
    }
    
    for(i=0; i<nPedras; i++)
        printf("%d\n", pedras[i]);
    
    return 0;
}

/* Exercicio  - Capicua (++)
Alan deve pegar um número com quatro algarismos e verificar se o reverso deste número é ele próprio. Se
for, Alan deve responder yes, do contrário deve responder no – Alan é britânico e, por isso, responde em
inglês.
Verifica se o numero e palíndromo*/

#include <stdio.h>

int palindromo(int num);

int main(){
    int testes, num;
    
    scanf("%d", &testes); //Determina a quantidade de números a serem fornecidos como entrada
    
    int numeros[testes], i=0;//'numeros' armazena os números testados 
    
    while(i < testes){ //i menor que a 'testes'
        scanf("%d", &num); 
        numeros[i] = num;//Cada 'num' lido é armazenado no array 'numero'
        i++; //O valor de 'i' é incrementado em cada iteração para rastrear a posição no array 'numero'
    }
    
    for(i = 0; i < testes-1; i++){
        
        if(palindromo(numeros[i]) == 0){//Verifica se o número no array numero[i] 
            printf("yes ");//É Palíndrono 
        } else{
            printf("no ");//Não é Palíndrono
        }
    }
    
    if(i == testes-1){
        if(palindromo(numeros[i]) == 0){
            printf("yes");
        } else{
            printf("no");
        }
    }

    return 0;
}

int palindromo(int num){
    int m, c, d, u;
    //Recebe um número de quatro dígito
    m = num/1000;//Divide em Unidade de milhar
    c = num/100%10;//Divide em Centenas
    d = num/10%10;//Dividde dezena
    u = num%10;//Divide em unidade
    
    if(m == u && c == d)//Verifica se unidade de milhar e unidade são iguais 
        return 0;      // E se as centenas e dezenas são iguais
        //Retorna 0 se for um palíndromo
    return -1;//Retorna -1 se não for
}
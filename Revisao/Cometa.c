//Exercício 1 - Cometa (+)

/*O cometa Halley é um dos cometas de menor período do Sistema Solar, completando uma volta em
torno do Sol a cada 76 anos. Na última ocasião em que ele se tornou visível do planeta Terra, em 1986,
várias agências espaciais enviaram sondas para coletar amostras de sua cauda e assim confirmar teorias
sobre sua composição química. Saiba mais sobre ele em http://astro.if.ufrgs.br/solar/
halley.htm.
Escreva um programa C que, dado o ano atual, determina qual o próximo ano em que o cometa Halley
será visível novamente no planeta Terra. Se o ano atual é um ano de passagem do cometa, considere que o
cometa já passou nesse ano, ou seja, considere sempre o próximo ano de passagem após o atual.
Observação: Não se esqueça de considerar os anos bissextos, ou seja, que a cada quatro anos (em direção ao futuro 
ou ao passado) há um erro de um dia em relação ao ano solar que, neste caso, é considerado
como tendo exatamente 365 dias terrestres. O ano de 1986, quando o cometa de Halley se tornou visível na
Terra pela última vez, é considerado o “marco de sincronismo” para os cálculos do programa a ser elaborado.
*/

#include <stdio.h>

//Fórmula para determinar o próximo ano que o cometa Halley será visível novamente
//n = (ano - 1986)/76
//prox_ano = 1986 + (n + 1)*76
void main(int argc, char *argv[]) { 
    int ano, prox_ano; 
    scanf("%d", &ano);

    prox_ano = (ano - 1986)/76; 
    prox_ano++; 
    
    printf("%d", prox_ano * 76 + 1986);
    
return 0;     
}
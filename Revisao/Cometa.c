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
#include <stdio.h>
#define ULTIMA_VEZ 1986

int main(){
    int ano, proximo;
    
    scanf("%d", &ano);
    
    if(ano >= ULTIMA_VEZ){//verifica se o 'ano' é maior ou igual ao 'ultimo_vez'(1986)
        proximo = ULTIMA_VEZ + 76;//proximo 'ano' será 'Ultima_vez' (1986) + 76 
                                 //a cada quanto tempo o cometa aparece 
        
        //Iniciaza a variável 'proximo' com o valor 1986(o último ano bissexto conhecido)
        //Entra no loop que continua até que 'proximo' seja maior ou igual ao ano fornecido
        while(proximo < ano){
            proximo += 76; //Cada interação, adiciona 76 anos a 'proximo'
        }
    } else{
        proximo = ULTIMA_VEZ;

        //Se o ano fornecido for menor que 1986, ele calcula o próximo ano bissexto antes de 1986       
        //Inicia a variavel 'proximo' com o valor 1986
        //Entra em um loop que continua até que 'proximo' seja menor ou igual 
        //ao ano fornecido mais 76
        while(proximo > ano + 76){
            proximo -= 76;
        }                
    }
    
    printf("%d\n", proximo);

    return 0;
}
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
#include <math.h>

#define MARCO 1986
#define INTERVALO 76
#define ANOS_ERRO 365

// Verifica se o número passado corresponde a um ano bissexto.
int bissexto(int ano)
{
    if(ano % 4 == 0 && ano % 100 != 0) return 1;
    if(ano % 400 == 0 && ano % 100 == 0) return 1;
    
    return 0;
}

// A cada 365 anos bissextos, adiciona ou subtrai 1 ano de proxPassagem.
void corrigeErro(int *proxPassagem)
{
    int distancia = (int) fabs(*proxPassagem - MARCO);
    int anosBissextos = 0;

    if(*proxPassagem > MARCO){
        for(distancia; distancia != 0; distancia--){
            anosBissextos += bissexto(MARCO + distancia);
        }

        anosBissextos = (int) (anosBissextos / ANOS_ERRO);
        *proxPassagem += anosBissextos;
    }
    else{
        for(distancia; distancia != 0; distancia--){
            anosBissextos += bissexto(MARCO - distancia);
        }

        anosBissextos = (int) (anosBissextos / ANOS_ERRO);
        *proxPassagem -= anosBissextos;
    }
}

// Descobre a próxima passagem do cometa Haley a partir do ano fornecido.
int calculoProxPassagem(int anoAtual)
{
    int proxPassagem = MARCO;
    int diferenca = anoAtual - MARCO;

    if(diferenca > 0){
        for(proxPassagem;
            proxPassagem < anoAtual;
            proxPassagem += 76);

        corrigeErro(&proxPassagem);

        if(proxPassagem == anoAtual){
            proxPassagem += 76;
            corrigeErro(&proxPassagem);
            return proxPassagem;
        }

        return proxPassagem;
    }
    else if(diferenca < 0){
        for(proxPassagem;
            proxPassagem > anoAtual && proxPassagem -76 > anoAtual;
            proxPassagem -= 76);

        corrigeErro(&proxPassagem);

        if(proxPassagem == anoAtual){
            proxPassagem += 76;
            corrigeErro(&proxPassagem);
            return proxPassagem;
        }

        return proxPassagem;
    }
    else{
        return (anoAtual + 76);
    }
}

int main(void)
{
    int anoAtual;
    int proxPassagem;

    scanf("%d", &anoAtual);
    proxPassagem = calculoProxPassagem(anoAtual);
    printf("%d\n", proxPassagem);

    return 0;
}
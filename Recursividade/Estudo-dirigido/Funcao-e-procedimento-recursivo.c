//Exemplo: Imprimir todos os números de n até 0

#include <stdio.h> 
/*
--Decrescente 
Explicando: 
Supondo que X = 5
'if' vai comparar vê que não é igual a 0 
Imprime o 5 
Chamada recursiva 'chama o mesmo procedimento' 
Salva na pilha 
5 - 1 = 4 
Repete o processo até chegar no 0
Imprime o zero

--Crescente 
Explicando: 
Supondo que 'x' = 5 
'if' vai comparar e observa se é igual, vê que é negativo 
Chamada recursiva
Salva na pilha
5 - 1 = 4 
Volta para a chamada 
Repete o processo até chegar no 0 
Começa a imprimir pelo 0 
Vai voltando as chamadas recursivas e imprimindo 
*/

//Decrescente
/*void imprimir(int x) { 
    if(x = 0)
        printf("%d", x);
    else{ 
        printf("%d ", x);
        imprimir(x - 1);//Chama a função e subtrai o número de 'x' por menos 1 
    }//Retorna pro inicial da função que compara a igualdade
} */  
//Crescente
void imprimir(int y) {
    if(y == 0)
        printf("%d ", y); 
    else{
        imprimir(y - 1);//Guarda na pilha e volta pra função 
        printf("%d ", y); //Desempilha os números guardados 
    }
}

int main() { 
    int n;

    printf("Digite um valor maior que zero: "); 
    scanf("%d", &n);

    imprimir(n);

return 0; 
}
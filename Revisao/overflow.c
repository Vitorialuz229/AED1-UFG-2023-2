//Exercicio 3 - Overflow (++)

/*Se um computador fictício somente pode representar números menores ou iguais a 1023
(2^10 − 1) e mandarmos ele executar a conta 1022 + 5, vai ocorrer um overflow, já que 
o resultado deste cálculo é maior que 1023.
Elabore um programa C que seja capaz de receber o maior número que um computador consegue 
representar em sua memória e uma expressão de soma ou de multiplicação entre dois inteiros 
positivos, determine se ocorrerá, ou não, overflow naquele computador.
*/
#include <stdio.h>
#include <stdint.h>

int main() {
    int64_t maxNumber;
    scanf("%lld", &maxNumber); //Leia o maior número que o computador consegue representar

    int64_t operand1, operand2; 
    char operation;

    //Represente a expressão N1 + N2 ou N1 x N2
    scanf("%lld %c %lld", &operand1, &operation, &operand2);

    int64_t result;

    if (operation == '+') {
        result = operand1 + operand2;
    } else if (operation == 'x') {
        result = operand1 * operand2;
    }

    if (result >= maxNumber) { //Se o resultado for maior ou igual que numero máximo
        printf("overflow\n");
    } else {
        printf("no overflow\n");
    }

    return 0;
}

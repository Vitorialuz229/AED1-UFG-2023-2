//Exercício 2 - José (+)

/*João tem um irmão mais novo, José, que começou a ir à escola e já está tendo problemas com números.
Para ajudá-lo a “pegar o jeito” com a escala numérica, a professora de José escreve dois números de três
dígitos e pede ele para comparar esses números.
Entretanto, ao invés de interpretá-los com o dígito mais significativo à esquerda, ele deve interpretá-los com
o dígito mais significativo à direita. Ele tem que dizer à professora qual o maior dos dois números.
Escreva um programa em C que seja capaz de verificar as respostas de José.
*/

#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    // Inverte os dígitos de A e B para que José possa interpretá-los corretamente
    int reversed_A = 0, reversed_B = 0;

    while (A > 0) {
        reversed_A = reversed_A * 10 + A % 10;
        A /= 10;
    }

    while (B > 0) {
        reversed_B = reversed_B * 10 + B % 10;
        B /= 10;
    }

    // Determina o maior número invertido
    int maior;
    if (reversed_A > reversed_B) {
        maior = reversed_A;
    } else {
        maior = reversed_B;
    }

    printf("%d\n", maior);

    return 0;
}

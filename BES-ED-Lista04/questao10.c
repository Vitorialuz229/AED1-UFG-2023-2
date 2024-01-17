#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um dígito na lista encadeada
typedef struct Digit {
    int value;
    struct Digit* next;
} Digit;

// Estrutura para representar um número inteiro na lista encadeada
typedef struct {
    Digit* firstDigit;
    int sign; // +1 para positivo, -1 para negativo
} BigInteger;

// Função para criar um número inteiro vazio
void createEmptyNumber(BigInteger* num) {
    num->firstDigit = NULL;
    num->sign = 1;
}

// Função para inserir um dígito no final do número
void insertDigit(BigInteger* num, int digit) {
    Digit* newDigit = (Digit*)malloc(sizeof(Digit));
    if (!newDigit) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    newDigit->value = digit;
    newDigit->next = NULL;

    if (num->firstDigit == NULL) {
        num->firstDigit = newDigit;
    } else {
        Digit* current = num->firstDigit;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newDigit;
    }
}

// Função para imprimir um número inteiro
void printBigInteger(BigInteger* num) {
    if (num->sign == -1) {
        printf("-");
    }

    Digit* current = num->firstDigit;
    while (current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
    printf("\n");
}

// Função para liberar a memória alocada por um número inteiro
void freeBigInteger(BigInteger* num) {
    Digit* current = num->firstDigit;
    while (current != NULL) {
        Digit* temp = current;
        current = current->next;
        free(temp);
    }
    num->firstDigit = NULL;
    num->sign = 1;
}

// Função para somar dois números inteiros
BigInteger add(BigInteger* num1, BigInteger* num2) {
    BigInteger result;
    createEmptyNumber(&result);

    // Implementação da soma aqui...

    return result;
}

// Função para subtrair dois números inteiros
BigInteger subtract(BigInteger* num1, BigInteger* num2) {
    BigInteger result;
    createEmptyNumber(&result);

    // Implementação da subtração aqui...

    return result;
}

// Função para multiplicar dois números inteiros
BigInteger multiply(BigInteger* num1, BigInteger* num2) {
    BigInteger result;
    createEmptyNumber(&result);

    // Implementação da multiplicação aqui...

    return result;
}

// Função para dividir dois números inteiros (divisão inteira)
BigInteger divide(BigInteger* num1, BigInteger* num2) {
    BigInteger result;
    createEmptyNumber(&result);

    // Implementação da divisão aqui...

    return result;
}

// Função para verificar se um número é primo
int isPrime(BigInteger* num) {
    // Implementação da verificação de primalidade aqui...
    return 0;
}

int main() {
    BigInteger num1, num2;
    createEmptyNumber(&num1);
    createEmptyNumber(&num2);

    // Inserir dígitos nos números conforme necessário...

    printf("Número 1: ");
    printBigInteger(&num1);

    printf("Número 2: ");
    printBigInteger(&num2);

    // Exemplo de operações
    BigInteger sum = add(&num1, &num2);
    printf("Soma: ");
    printBigInteger(&sum);

    BigInteger difference = subtract(&num1, &num2);
    printf("Subtração: ");
    printBigInteger(&difference);

    BigInteger product = multiply(&num1, &num2);
    printf("Multiplicação: ");
    printBigInteger(&product);

    BigInteger quotient = divide(&num1, &num2);
    printf("Divisão: ");
    printBigInteger(&quotient);

    // Exemplo de verificação de primalidade
    if (isPrime(&num1)) {
        printf("Número 1 é primo.\n");
    } else {
        printf("Número 1 não é primo.\n");
    }

    // Liberar memória
    freeBigInteger(&num1);
    freeBigInteger(&num2);
    freeBigInteger(&sum);
    freeBigInteger(&difference);
    freeBigInteger(&product);
    freeBigInteger(&quotient);

    return 0;
}

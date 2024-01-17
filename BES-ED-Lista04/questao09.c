#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da fila
typedef struct Node {
    int valor;
    int prioridade;
    struct Node* proximo;
} Node;

// Definição da estrutura da fila
typedef struct {
    Node* inicio;
    Node* fim;
} FilaPrioridade;

// Função para criar a fila
void criarFila(FilaPrioridade* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Função para verificar se a fila está vazia
int estaVazia(FilaPrioridade* fila) {
    return (fila->inicio == NULL);
}

// Função para enfileirar um elemento com prioridade
void enfileirar(FilaPrioridade* fila, int valor, int prioridade) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if (!novoNo) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    novoNo->valor = valor;
    novoNo->prioridade = prioridade;
    novoNo->proximo = NULL;

    if (estaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        Node* atual = fila->inicio;
        Node* anterior = NULL;

        // Encontrar a posição correta para inserir com base na prioridade
        while (atual != NULL && atual->prioridade <= prioridade) {
            anterior = atual;
            atual = atual->proximo;
        }

        // Inserir no início
        if (anterior == NULL) {
            novoNo->proximo = fila->inicio;
            fila->inicio = novoNo;
        }
        // Inserir no meio ou no fim
        else {
            anterior->proximo = novoNo;
            novoNo->proximo = atual;

            // Se inseriu no final, atualizar o ponteiro fim
            if (atual == NULL) {
                fila->fim = novoNo;
            }
        }
    }
}

// Função para desenfileirar um elemento
int desenfileirar(FilaPrioridade* fila) {
    if (estaVazia(fila)) {
        fprintf(stderr, "Erro: Fila vazia.\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = fila->inicio;
    int valor = temp->valor;
    fila->inicio = temp->proximo;
    free(temp);

    // Se a fila ficou vazia, também atualizar o ponteiro fim
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    return valor;
}

// Função para imprimir a fila
void imprimirFila(FilaPrioridade* fila) {
    Node* atual = fila->inicio;
    printf("Fila por Prioridade: ");
    while (atual != NULL) {
        printf("(%d, %d) ", atual->valor, atual->prioridade);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    FilaPrioridade fila;
    criarFila(&fila);

    int n;
    printf("Digite o número de elementos (1 <= n <= 100): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int valor, prioridade;
        printf("Digite o valor e a prioridade do elemento %d: ", i + 1);
        scanf("%d %d", &valor, &prioridade);
        enfileirar(&fila, valor, prioridade);
    }

    printf("\nFila por Prioridade:\n");
    imprimirFila(&fila);

    return 0;
}

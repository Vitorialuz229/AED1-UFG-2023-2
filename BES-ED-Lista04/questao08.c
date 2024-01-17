#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da pilha
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definição da estrutura da pilha
typedef struct {
    Node* top;
} Pilha;

// Função para criar a pilha
void criarPilha(Pilha* p) {
    p->top = NULL;
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha* p) {
    return (p->top == NULL);
}

// Função para empilhar um elemento
void empilhar(Pilha* p, int x) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if (!novoNo) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    novoNo->data = x;
    novoNo->next = p->top;
    p->top = novoNo;
}

// Função para desempilhar um elemento
int desempilhar(Pilha* p) {
    if (estaVazia(p)) {
        fprintf(stderr, "Erro: Pilha vazia.\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = p->top;
    int valor = temp->data;
    p->top = temp->next;
    free(temp);
    return valor;
}

// Função para remover um elemento específico da pilha
void removeChave(Pilha* p, int x) {
    Pilha auxiliar;
    criarPilha(&auxiliar);

    // Transferir elementos da pilha original para a pilha auxiliar
    while (!estaVazia(p)) {
        int elemento = desempilhar(p);
        if (elemento != x) {
            empilhar(&auxiliar, elemento);
        }
    }

    // Transferir elementos de volta para a pilha original
    while (!estaVazia(&auxiliar)) {
        int elemento = desempilhar(&auxiliar);
        empilhar(p, elemento);
    }
}

// Função para imprimir a pilha
void imprimirPilha(Pilha* p) {
    Node* current = p->top;
    printf("Pilha: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Pilha minhaPilha;
    criarPilha(&minhaPilha);

    empilhar(&minhaPilha, 10);
    empilhar(&minhaPilha, 20);
    empilhar(&minhaPilha, 30);
    empilhar(&minhaPilha, 40);

    printf("Pilha original:\n");
    imprimirPilha(&minhaPilha);

    int chaveRemover = 20;
    removeChave(&minhaPilha, chaveRemover);

    printf("\nPilha após remover %d:\n", chaveRemover);
    imprimirPilha(&minhaPilha);

    return 0;
}

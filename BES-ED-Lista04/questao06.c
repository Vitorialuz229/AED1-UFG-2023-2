#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definição da estrutura da lista
typedef struct {
    Node* head;
    Node* tail;
    int size;
} List;

// Função para criar uma lista inicialmente vazia
int criarLista(List* lista) {
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    return 0;
}

// Função para inserir um número inteiro no final da lista
int inserirFinal(List* lista, int x) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if (!novoNo) {
        return -1; // Erro de alocação de memória
    }

    novoNo->data = x;
    novoNo->next = NULL;

    if (lista->size == 0) {
        lista->head = novoNo;
        lista->tail = novoNo;
    } else {
        lista->tail->next = novoNo;
        lista->tail = novoNo;
    }

    lista->size++;
    return 0;
}

// Função para inserir um número inteiro no início da lista
int inserirInicio(List* lista, int x) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if (!novoNo) {
        return -1; // Erro de alocação de memória
    }

    novoNo->data = x;
    novoNo->next = lista->head;

    if (lista->size == 0) {
        lista->tail = novoNo;
    }

    lista->head = novoNo;
    lista->size++;
    return 0;
}

// Função para remover o número inteiro que está na última posição da lista
int removerFinal(List* lista) {
    if (lista->size == 0) {
        return -1; // Lista vazia, não é possível remover
    }

    Node* atual = lista->head;
    Node* anterior = NULL;

    while (atual->next != NULL) {
        anterior = atual;
        atual = atual->next;
    }

    if (anterior == NULL) {
        lista->head = NULL;
        lista->tail = NULL;
    } else {
        anterior->next = NULL;
        lista->tail = anterior;
    }

    free(atual);
    lista->size--;
    return 0;
}

// Função para remover o número inteiro que está na primeira posição da lista
int removerInicio(List* lista) {
    if (lista->size == 0) {
        return -1; // Lista vazia, não é possível remover
    }

    Node* temp = lista->head;
    lista->head = lista->head->next;

    if (lista->head == NULL) {
        lista->tail = NULL;
    }

    free(temp);
    lista->size--;
    return 0;
}

// Função para apresentar os números presentes na lista, do primeiro ao último
void mostrarLista(List* lista) {
    Node* atual = lista->head;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

// Função para apresentar a quantidade de números inteiros existentes na lista
int quantidadeElementos(List* lista) {
    return lista->size;
}

// Função para apresentar o número inteiro que está no início da lista
int elementoInicio(List* lista) {
    if (lista->size == 0) {
        return -1; // Lista vazia
    }
    return lista->head->data;
}

// Função para apresentar o número inteiro que está na última posição da lista
int elementoFinal(List* lista) {
    if (lista->size == 0) {
        return -1; // Lista vazia
    }
    return lista->tail->data;
}

int main() {
    List lista;
    criarLista(&lista);

    inserirFinal(&lista, 10);
    inserirInicio(&lista, 5);
    inserirFinal(&lista, 20);

    mostrarLista(&lista);

    printf("Quantidade de elementos: %d\n", quantidadeElementos(&lista));
    printf("Elemento no início: %d\n", elementoInicio(&lista));
    printf("Elemento no final: %d\n", elementoFinal(&lista));

    removerFinal(&lista);
    removerInicio(&lista);

    mostrarLista(&lista);

    return 0;
}

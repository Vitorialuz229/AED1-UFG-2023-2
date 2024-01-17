#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um elemento não nulo na matriz esparsa
typedef struct Node {
    int row;
    int col;
    int value;
    struct Node* nextRow;
    struct Node* nextCol;
} Node;

// Estrutura para representar a matriz esparsa
typedef struct {
    Node* rowList;
    Node* colList;
} SparseMatrix;

// Função para criar uma matriz esparsa vazia
void criarMatrizEsparsa(SparseMatrix* matrix) {
    matrix->rowList = NULL;
    matrix->colList = NULL;
}

// Função para inserir um elemento não nulo na matriz esparsa
void inserirElemento(SparseMatrix* matrix, int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->nextRow = NULL;
    newNode->nextCol = NULL;

    // Inserir na lista de linhas
    if (matrix->rowList == NULL) {
        matrix->rowList = newNode;
    } else {
        Node* current = matrix->rowList;
        while (current->nextRow != NULL) {
            current = current->nextRow;
        }
        current->nextRow = newNode;
    }

    // Inserir na lista de colunas
    if (matrix->colList == NULL) {
        matrix->colList = newNode;
    } else {
        Node* current = matrix->colList;
        while (current->nextCol != NULL) {
            current = current->nextCol;
        }
        current->nextCol = newNode;
    }
}

// Função para imprimir a matriz esparsa de maneira tabular
void imprimirMatriz(SparseMatrix* matrix, int numRows, int numCols) {
    for (int i = 1; i <= numRows; i++) {
        for (int j = 1; j <= numCols; j++) {
            Node* current = matrix->rowList;
            while (current != NULL) {
                if (current->row == i && current->col == j) {
                    printf("%d\t", current->value);
                    break;
                }
                current = current->nextRow;
            }
            if (current == NULL) {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

// Função para realizar a atribuição de um valor a uma posição específica
void atribuirValor(SparseMatrix* matrix, int row, int col, int value) {
    Node* current = matrix->rowList;
    while (current != NULL) {
        if (current->row == row && current->col == col) {
            current->value = value;
            return;
        }
        current = current->nextRow;
    }

    // Se não encontrar, inserir um novo elemento
    inserirElemento(matrix, row, col, value);
}

// Função para consultar o valor em uma posição específica
int consultarValor(SparseMatrix* matrix, int row, int col) {
    Node* current = matrix->rowList;
    while (current != NULL) {
        if (current->row == row && current->col == col) {
            return current->value;
        }
        current = current->nextRow;
    }
    return 0;  // Valor padrão para elementos nulos
}

int main() {
    SparseMatrix matrix;
    criarMatrizEsparsa(&matrix);

    int numRows, numCols;
    printf("Digite o número de linhas e colunas da matriz: ");
    scanf("%d %d", &numRows, &numCols);

    printf("Digite os elementos não nulos da matriz (linha coluna valor):\n");
    int row, col, value;
    while (scanf("%d %d %d", &row, &col, &value) == 3) {
        inserirElemento(&matrix, row, col, value);
    }

    printf("\nMatriz Esparsa:\n");
    imprimirMatriz(&matrix, numRows, numCols);

    // Exemplo de atribuição de valor
    atribuirValor(&matrix, 2, 3, 10);
    printf("\nMatriz após atribuição:\n");
    imprimirMatriz(&matrix, numRows, numCols);

    // Exemplo de consulta de valor
    int consulta = consultarValor(&matrix, 2, 3);
    printf("\nValor na posição (2, 3): %d\n", consulta);

    return 0;
}
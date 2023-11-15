//Exercicio 11 
//Manipulação de matrizes 

/*Considerando apenas as matrizes bidimensionais A, de ordem m por n, que armazenam em cada uma de suas
posições um número inteiro ai, j
, onde o índice i indica a linha e o índice j indica a coluna, com 1 ≤ i ≤ m
e 1 ≤ j ≤ n e m,n ∈ N*/

#include <stdio.h>

int main(){
    int m, n, i, j, lin, col, soma;
    char op;
    
    scanf("%d %d", &m, &n);
    
    int A[m][n], B[m][n], multiplicacao[m][n];
    
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &A[i][j]);
        }
    }
    
    scanf(" %c", &op);
    
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &B[i][j]);
        }
    }
    
    switch(op){
        case '+':
            for(i=0; i<m; i++){
                for(j=0; j<n; j++){
                    printf("%d ", A[i][j] + B[i][j]);
                }
                printf("\n");
            }
            
            break;
        
        case 'x':
            if(m != n) 
                printf("ERROR\n");
                
            else{
                for(lin=0; lin<m; lin++){
                    for(col=0; col<n; col++){
                        soma=0;
                        
                        for(i=0; i<n; i++)
                            soma += A[lin][i]*B[i][col];
                            
                        multiplicacao[lin][col] = soma;
                    }
                }
                
                for(i=0; i<m; i++){
                    for(j=0; j<n; j++){
                        printf("%d ", multiplicacao[i][j]);
                    }       
                    printf("\n");
                }
            }
            
            break;
    }

    return 0;
}
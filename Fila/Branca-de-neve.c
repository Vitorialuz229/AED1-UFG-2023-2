//Branca de neve e os n anões(++)
//Exercicico 33 
//Exercicio 4 da lista de Filhas e Pilhas

#include <stdio.h>
#include <stdlib.h>

//A estrutura de dados será lista encadeada (dinamica), ela vai guardar as cores dos anões na lista.

typedef struct lista {
    int dado;
    struct lista * prox;
} Lista;

// Função auxiliar que retorna o máximo entre dois números.

int max (int a, int b){
    if (a < b) {
       return b; 
    }
    return a;
}

// Aloca um nó novo, com o dado passado por argumento.

Lista *cria_no(int x){
    Lista *tmp = NULL;
    tmp = (Lista *) malloc(sizeof(Lista));
    tmp->dado = x;
    tmp->prox = NULL;
    return tmp;
}


// Função recursiva que insere um dado na lista, chama a função auxiliar cria_nó
// para completar a inserção.

Lista *insere(Lista *L, int x){
	if (L == NULL){
	   return cria_no(x);
	}
	L->prox = insere(L->prox, x);
	return L;
}

void imprime(Lista *L){
	if(L == NULL){
		printf("\n");
		return;
	}
	printf("%d ", L->dado);
	imprime(L->prox);
}

int procura(Lista *L, int i){
	int k = 1;
	while(k < i){
		L = L->prox;
		k++;
	}
	return L->dado;
}

void gosta(Lista *L, int a, int b, int c){
	int k, maximo;
        int v[10010] = {0};
        
        k      = 1;
        maximo = 0;
	while(k < a){
            L = L->prox;
            k++;
	}
	while(k <= b){
		v[L->dado]++;
		maximo = max(v[L->dado],maximo);
		L = L->prox;
		k++;
	}
	if ((((b-a)/2.0) + 0.5) < maximo){
            printf("bonita ");
            for(k = 1; (k <= c); k++){
                    if (v[k] == maximo){
                       printf("%d\n", k);
                       break;
                    }
            }
	}
	else { 
           printf("feia\n");
        }
}

// Função que desaloca a lista.

void limpa (Lista * L){
	Lista  *s;
	
	if (L == NULL) { 
	   return;
        }   
        while (L != NULL) { 
	    s = L;
	    L = L->prox; 
            free(s);
	}   
        L = NULL;
}

void mostra(Lista * L){
	Lista * r;
	
	if (L == NULL) {
            printf("Fila vazia\n.");
	   return;
        }   
	r = L;
	while (r != NULL) { 
	    printf("%d ", r->dado);
	    r = r->prox;
	}   
       printf("\n"); 
        
}

int main(){
	int n, x, t, c, m, i, a, b;
	
	scanf("%d", &t);
	while(t--) {
            Lista * fila = NULL;
            
            scanf("%d %d", &n, &c);
            for(i = 0;i < n;i++){
                    scanf("%d", &x);
                    fila = insere(fila, x);
            }
            scanf("%d", &m);
            for(i = 0;i < m;i++){
                    scanf("%d %d", &a, &b);
                    if (a == b){
                       printf("bonita %d\n", procura(fila, a));
                    }
                    else {  
                       gosta(fila, a, b, c);
                    }
            }
            limpa(fila);
    }
}

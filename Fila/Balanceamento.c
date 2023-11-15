//Balanceamento de parênteses
//Exercicio 35
//Exercicio 6 da lista de Filha e Pilha

#include <stdio.h>
#include <stdlib.h>

typedef char Char;

typedef struct Elem{
	Char chave;
	struct Elem *prox;
  }Caixa;
                 
typedef Caixa *Ponteiro;

typedef struct {
	Ponteiro prim, ult;
	int tam;
    }Lista; 
    
void inicializa_lista(Lista *l){
    l->prim = (Ponteiro) malloc (sizeof(Caixa));
    l->ult = l->prim;
    l->prim->prox = NULL;
    l->tam=0;
}

void inserir_elemento_lista(Lista *l, Char x){
    Ponteiro  q;
    q = (Ponteiro) malloc(sizeof(Caixa));
    q->chave = x;
    q->prox = l->ult->prox;
    l->ult->prox = q;
    l->tam++;
    l->ult = q;
    
}
//int verificaListaVazia(Lista l){
//    return(l.ult == NULL);
//}
/*

Char remover_da_lista(Lista *l, Char *x){
    Ponteiro p, q;
    p = l->prim;
    while((p!=l->ult)&&(*x!=p->chave))
	      p=p->prox;
    if(l->prim==l->ult){
        printf("A lista esta vazia - Remover\n");
        return ' ';
       }
    else{
        q=p->prox;
		*x = q->chave;
		p->prox=q->prox;
	    if(q==l->ult)
			 l->ult=p;
	    l->tam--;
		free(q);
       }
       return *x;
  }
*/

 
int calcula(Lista *l, int *abri){
    Char x;
    Ponteiro p;
    p=l->prim->prox;
    if(p==NULL)
      return -1;
     else{ while(p!=NULL){
		   x = p->chave;
           if(x == '('){
               *abri=*abri+1;
            }else if(x == ')'){
                      *abri=*abri-1;
                    }
           if(*abri<0)
             return (*abri);
           p= p->prox;
         //  printf("%c",x);
           
           }
          return (*abri);
         }
}

int main(){
    Lista l;
    Lista l2;
    int abri=0, flag;
    Char  x;
    inicializa_lista(&l);
    inicializa_lista(&l2);
    int i;
    char string[100];
    scanf("%s", string);
    for(i=0;string[i] != '\0'; i++){
		x = string[i];
        inserir_elemento_lista(&l, x);
       // printf("%c", x);
    }
    flag=0;
    flag = calcula(&l,&abri);
    if(flag<0){
        printf("incorreta");
    }else{
        printf("correta");
    }
    printf("\n");
    
    return 0;
}
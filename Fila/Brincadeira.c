//Brincadeira (+)
//Exercicio 42
//Exercicio 13 da lista de Pilha e Filh

#include <stdio.h>
#include <stdlib.h>


typedef struct { char nome[30];
                 int valor;
                }Pessoa;
typedef struct cx { Pessoa item;
                    struct cx  *prox, *ant;
                  }Caixa;
typedef Caixa *ponteiro;
typedef struct {ponteiro prim, ult;
                int qtde;
                }Listac;
                
void inicia_listac(Listac *l){
   l->prim = NULL;
   l->ult = NULL;
   l->qtde = 0;
}

void ler_pessoa(Pessoa *x){
   scanf("%s",x->nome);
   scanf("%d",&x->valor);
}

void insere_pessoa_listac(Listac *l, Pessoa x){  //insere anti-horário
   ponteiro p;
   p = (ponteiro) malloc(sizeof(Caixa));
    p->item = x;
    l->qtde++;
   if(l->prim==NULL) {
     l->prim = p;
     l->ult=p;
     p->ant=l->ult;
     p->prox = l->prim;
     }else { 
             p->prox = l->prim->prox;
             p->ant = l->ult->ant;
             l->ult->ant=p;
             l->prim->prox = p;
             l->ult = p;
             }
}
/*
void sequenciaah(Listac l){    //função só para olhar a sequencia horária e anti-horária cadastrado
  ponteiro p;
  int i=5;
  p = l.prim;
  
  while(i--){
    printf("%d - ",p->item.valor);
    p = p->ant;
 }
  printf("%d\n",p->item.valor);
}


void sequenciah(Listac l){
  ponteiro p;
  int i=5;
  p = l.ult;
  while(i--){
    printf("%d - ",p->item.valor);
    p = p->prox;
 }
  printf("%d\n",p->item.valor);
}

*/
void conta_ahorario(Listac *l, int *v){
	ponteiro p;
	int val;
	 p = l->prim->ant;
	 val = *v;
	 val--;
	while(val--)
		 p = p->ant;
	 *v = p->item.valor;
//	 printf("Apagou %s\n",p->item.nome);
	p->prox->ant=p->ant;
	p->ant->prox = p->prox;
	if(p==l->prim)
	  l->prim = p->ant;
	if(p==l->ult)
	  l->ult = p->prox;
    l->qtde--;
    free(p);
}

void conta_horario(Listac *l,int *v){
	ponteiro p;
	int val;
	p = l->prim->prox;
	val = *v;
	val--;
	while(val--){
		 p = p->prox;
	 }
	 *v = p->item.valor;
//	  printf("Apagou %s\n",p->item.nome);
	p->prox->ant=p->ant;
	p->ant->prox = p->prox;
	if(p==l->prim)
	  l->prim = p->ant;
	if(p==l->ult)
	  l->ult = p->prox;
    l->qtde--;
    free(p);
}


int main() {
  int  n, v;
  Listac l;
  Pessoa x;
  inicia_listac(&l);
  scanf("%d", &n);
  while(n--){
      ler_pessoa(&x);
      insere_pessoa_listac(&l,x);
   }
  v = l.prim->item.valor;
  while(l.qtde!=1){
	  if((v%2)==0)
	    conta_horario(&l,&v);
	  else conta_ahorario(&l,&v);
  }
 printf("%s\n",l.prim->item.nome);
// sequenciaah(l);
// sequenciah(l);
 return 0;

}
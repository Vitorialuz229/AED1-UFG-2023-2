// 44 - Ciranda, cirandinha, vamos todos cirandar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct crianca {
	char nome[30];
	int numero;
};

struct lista {
	int dim;
	struct crianca dados[MAX];
};
typedef struct lista Lista;

Lista *cria_lista()
{
	Lista *li;
	li = (Lista *) malloc(sizeof(struct lista));
	if(li != NULL)
		li->dim = 0;

	return li;
}

void libera_lista(Lista *li)
{
	free(li);
}

int tamanho_lista(Lista *li)
{
	if(li == NULL)
		return -1;
	else
		return li->dim;
}

int lista_vazia(Lista *li)
{
	if(li == NULL)
		return -1;
	return(li->dim == 0);
}

int lista_cheia(Lista *li)
{
	if(li == NULL)
		return -1;
	return(li->dim == MAX);
}

int insere_lista_final(Lista *li, char *nome, int numero)
{
	if(li == NULL)
		return 0;
	if(lista_cheia(li))
		return 0;
	li->dados[li->dim].numero = numero;
	strcpy(li->dados[li->dim].nome, nome);
	li->dim++;
	return 1;
}

int remove_lista(Lista *li, int posicao)
{
	if (li == NULL)return 0;
	if(li->dim == 0) return 0;

	int i;
	for(i = posicao - 1; i < li->dim - 1; i++) {
		li->dados[i].numero = li->dados[i + 1].numero;
		strcpy(li->dados[i].nome, li->dados[i + 1].nome);
	}
	li->dim--;
	return 1;
}

void imprime_lista(Lista *li)
{
	int i;

	for(i = 0; i < li->dim; i++) {
		printf("%s %d \n", li->dados[i].nome, li->dados[i].numero);
	}

}

void imprime_ganhador(Lista *li)
{
	int cont;
	int x = tamanho_lista(li), aux = li->dados[0].numero;;
	do {
		// Caso anti-horário
		if(aux % 2 != 0) {
			cont = 1;
			
			do {
				cont++;
				if(cont >= x + 1) cont = 1;
				aux--;
			} while(aux != 0);

			aux = li->dados[cont - 1].numero;
			remove_lista(li, cont);
			x = tamanho_lista(li);
		}
		// Caso horário
		else {
			cont = 1;
			
			do {
				cont--;
				if(cont <= 0) cont = x;
				aux--;
			} while(aux != 0);

			aux = li->dados[cont - 1].numero;
			remove_lista(li, cont);
			x = tamanho_lista(li);
		}
	} while(li->dim != 1);

	printf("%s\n", li->dados[0].nome);

}

int main(void)
{
	int n, i;
	Lista *li;
	li = cria_lista();

	do {
		scanf("%d", &n);
	} while(n < 1 || n > 100);

	struct crianca cr[n];

	for(i = 0; i < n; i++) {
		do {
			scanf("%s", cr[i].nome);
			scanf("%d", &cr[i].numero);
		} while(cr[i].numero < 1 || cr[i].numero > 500);

		insere_lista_final(li, cr[i].nome, cr[i].numero);
	}

	imprime_ganhador(li);
	libera_lista(li);

	return 0;
}
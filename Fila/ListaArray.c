// A lista de Arya (GoT)

#include <stdio.h>
#include <stdlib.h>

struct node {
	int inimigo;
	struct node *prox;
};

struct lista {
	struct node *no;
	struct node *primeiro_no;
	struct node *ultimo_no;
};

struct lista *lst_inicializa (void)
{
	struct lista *lst = malloc(sizeof (struct lista));
	lst->no = NULL;
	lst->primeiro_no = NULL;
	lst->ultimo_no = NULL;
	return lst;
}

void lst_adiciona_elemento (struct lista *lst, int elem, int antesDeX)
{
	if (antesDeX <= 0) {
		if (lst->ultimo_no == NULL) {
			lst->ultimo_no = malloc(sizeof (struct node));
			lst->primeiro_no = lst->ultimo_no;
		}
		else {
			lst->ultimo_no->prox = malloc(sizeof (struct node));
			lst->ultimo_no = lst->ultimo_no->prox;
		}
		lst->ultimo_no->inimigo = elem;
		lst->ultimo_no->prox = NULL;
		return;
	}

	lst->no = lst->primeiro_no;
	while (lst->no != NULL) {
		if (lst->no->inimigo == antesDeX) {
			struct node *temp;
			temp = lst->no->prox;
			lst->no->prox = malloc(sizeof (struct node));
			lst->no = lst->no->prox;
			lst->no->inimigo = elem;
			lst->no->prox = temp;
			if (temp == NULL) {
				lst->ultimo_no = lst->no;
			}
			return;
		}
		lst->no = lst->no->prox;
	}
	fprintf(stderr, "o elemento nao foi encontrado\n");
	return;
}

void lst_remove (struct lista *lst, int elem)
{
	if (lst->primeiro_no->inimigo == elem) {
		lst->no = lst->primeiro_no->prox;
		free(lst->primeiro_no);
		lst->primeiro_no = lst->no;
		return;
	}

	lst->no = lst->primeiro_no;
	while (lst->no->prox != NULL) {
		if (lst->no->prox->inimigo == elem) {
			struct node *temp = lst->no->prox;
			lst->no->prox = lst->no->prox->prox;
			free(temp);
			if (lst->no->prox == NULL) {
				lst->ultimo_no = lst->no;
			}
			return;
		}
		lst->no = lst->no->prox;
	}
}

int lst_entre_a_b (struct lista *lst, int a, int b)
{
	int i = 0;
	struct node *temp1 = NULL;

	lst->no = lst->primeiro_no;
	while (lst->no != NULL) {
		if (lst->no->inimigo == a || lst->no->inimigo == b) {
			if (temp1 == NULL) {
				temp1 = lst->no;
			}
			else {
				break;
			}
		}
		lst->no = lst->no->prox;
	}

	while(1) {
		temp1 = temp1->prox;
		if (temp1->inimigo == a || temp1->inimigo == b) {
			break;
		}
		i++;
	}
	return i;
}

void lst_imprime (struct lista *lst)
{
	lst->no = lst->primeiro_no;
	if (lst->no == NULL) {
		printf("lista vazia\n");
		return;
	}
	printf("lista ");
	while (lst->no != NULL) {
		printf("%d", lst->no->inimigo);
		if (lst->no->prox != NULL) {
			printf(" ");
		}
		else {
			printf("\n");
			return;
		}
		lst->no = lst->no->prox;
	}
}

int main (void)
{
	char opcao;
	int i, inimigo, iniAnterior;
	int a, b;
	struct lista *lista;

	lista = lst_inicializa();

	scanf(" %d", &i);
	for (; i > 0; i--) {
		scanf(" %d", &inimigo);
		lst_adiciona_elemento(lista, inimigo, 0);
	}

	//lst_imprime(lista);

	while (1) {
		scanf(" %c", &opcao);
		switch (opcao) {
		case 'I':
			scanf(" %d", &inimigo);
			scanf(" %d", &iniAnterior);
			lst_adiciona_elemento(lista, inimigo, iniAnterior);
			printf("inserido %d\n", inimigo);
		break;
		
		case 'R':
			scanf(" %d", &inimigo);
			lst_remove(lista, inimigo);
			printf("removido %d\n", inimigo);
		break;
		
		case 'C':
			scanf(" %d%d", &a, &b);
			printf("quantidade %d\n", lst_entre_a_b(lista, a, b));
		break;
		
		case 'M':
			lst_imprime(lista);
		break;
		
		default:
			printf("fim\n");
			exit(0);
		}

		//lst_imprime(lista);
	}

	exit(0);
}
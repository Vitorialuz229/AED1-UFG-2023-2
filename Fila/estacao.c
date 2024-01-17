#include <stdio.h>
#include <stdlib.h>

#define FATOR_AUMENTO 2

struct pilha {
	int *v;
	size_t tamanho;
	size_t usado;
};

struct pilha *nova_pilha(size_t tamanho)
{
	struct pilha *p = malloc(sizeof (struct pilha));
	p->tamanho = tamanho;
	p->v = malloc(sizeof (int) * tamanho);
	p->usado = 0;
	return p;
}

void pilha_push(struct pilha *p, int elemento)
{
	if (p->v == NULL) {
		p->v = malloc(sizeof (int) * 2);
		p->tamanho = 2;
	}

	if (p->tamanho / 2 > p->usado + 1) {
		p->tamanho *= FATOR_AUMENTO;
		p->v = realloc(p->v, sizeof (int) * p->tamanho);
	}

	p->usado++;
	p->v[p->usado] = elemento;
}

int pilha_pop(struct pilha *p)
{
	if (p->usado - 1 == -2)
		return 0;

	p->usado--;
	return p->v[p->usado + 1];
}

size_t pilha_usado(struct pilha *p)
{
	return p->usado;
}

void free_pilha(struct pilha *p)
{
	free(p->v);
	free(p);
}

char *checa_ordem(struct pilha *p)
{
	int i = 0;
	char *sim = "sim";
	char *nao = "nao";

	while (pilha_usado(p)) {
		int temp = pilha_pop(p);
		//printf("temp %d\n", temp);
		if (i == 0) {
			i = temp;
			continue;
		}
		if (i + 1 == temp || i - 1 == temp) {
			i = temp;
		}
		else {
			return nao;
		}
	}
	return sim;
}

int main(void)
{
	int i, temp;
	int vagoes;
	struct pilha *pilha;

	scanf(" %d", &vagoes);
	pilha = nova_pilha(vagoes);

	for (i = 0; i < vagoes; i++) {
		scanf(" %d", &temp);
		pilha_push(pilha, temp);
	}

	printf("%s\n", checa_ordem(pilha));
	free_pilha(pilha);

	return 0;
}
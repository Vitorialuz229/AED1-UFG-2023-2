//Exercicício 4 - Placar: Quem vai ser reprovado?
//Ex: 56

/*Você é o(a) “monitor(a)” do Professor X e sua tarefa,é escrever um programa C que leia os resultados
dos(as) alunos(as) e imprima a classificação final, marcando com a hashtag #reprovado(a) aquele(a)
estudante que deverá ser reprovado(a).
A primeira linha de cada contém um número natural n, 1 ≤ n ≤ 100, que indica a quantidade estudantes
na competiação.
Cada uma das n linhas seguintes contém o nome do(a) aluno(a) – sem espaço entre as suas palavras formadoras de seu nome – e o número de problemas resolvidos por ele(a). O número de problemas resolvidos
está, obviamente, entre 0 e 10, inclusive extremos*/

#include <stdio.h>
#include <string.h>
#define TAM 100

typedef struct{ char nome[20];
                int nota;
              }ALUNO;
         
void troca (ALUNO *x, ALUNO *y){
	ALUNO aux;
	aux=*x;
	*x=*y;
	*y=aux;
}

void bubblenota(ALUNO v[], int n){
	int  i,j;
	for (i=1; i<n; i++) {
		for (j=0; j<n-i; j++) {
			if (v[j].nota<v[j+1].nota) {
				troca(&v[j], &v[j+1]);
			}
		}
	}
}

void bubblenome(ALUNO v[], int n){
	int  i,j;
	for (i=1; i<n; i++) {
		for (j=0; j<n-i; j++) {
			if (strcmp(v[j].nome,v[j+1].nome)>0) {
				troca(&v[j], &v[j+1]);
			}
		}
	}
}

int main(){
  ALUNO vet[TAM], x;
  int n, i;
  scanf("%d", &n);
  for(i=0; i<n;i++){
    scanf("%s %d", x.nome, &x.nota);
    getchar();
    vet[i] = x;
   }
   bubblenome(vet, n);
   bubblenota(vet, n);
   for(i=0; i<n-1;i++){
     printf("%s %d\n", vet[i].nome, vet[i].nota);
   }
   printf("%s %d #reprovado(a)\n", vet[i].nome, vet[i].nota);
   
return 0;
}
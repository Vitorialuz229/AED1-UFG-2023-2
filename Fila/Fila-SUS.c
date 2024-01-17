//Enumerando os números racionais
//Exercicio 30 
//Exercico 1 da lista de Filhas e Pilhas

/*Você deverá construir um programa C para realizar 
a enumeração de números racionais segundo o método 
anteriormente apresentado.*/
#include <stdio.h>
#include <stdlib.h>

#define TEMPO_CONSULTA 30

// Tudo em minutos
struct paciente {
	int chegada;
	int tempoCritico;
	int saida;
};

struct vetor {
	int tam;
	struct paciente *ptr;
};

void aloca_vetor(struct vetor *vet)
{
	vet->ptr = calloc(vet->tam, sizeof(struct paciente));
}

void registra_pacientes(struct vetor *vet)
{
	int i;
	for (i = 0; i < vet->tam; i++) {
		int hora;
		int minuto;

		scanf(" %d", &hora);
		scanf(" %d", &minuto);
		scanf(" %d", &(vet->ptr[i].tempoCritico));
		vet->ptr[i].chegada = hora * 60;
		vet->ptr[i].chegada += minuto;
		vet->ptr[i].saida = 0;
	}
}

//1 determinar quando cada paciente terá saído da consulta;
//2 verificar quantos entraram em estado crítico.
//PRECISA SER REESCRITO, TÁ MUITO FEIO
int pacientes_criticos(struct vetor *vet)
{
	int i;
	int pacientesCriticos = 0;
	struct paciente *p;

	p = vet->ptr;

	for (i = 0; i < vet->tam; i++) {
		int horaRedonda; // hora cheia ou meia hora
		int difTempo;
		int espera = 0;

		horaRedonda = p[i].chegada;

		if (horaRedonda % TEMPO_CONSULTA != 0) {
			horaRedonda += 30 - (p[i].chegada % TEMPO_CONSULTA);
			espera += 30 - (p[i].chegada % TEMPO_CONSULTA);
		}

		if (i == 0) {
			p[i].saida = horaRedonda + TEMPO_CONSULTA;
			p[i].tempoCritico -= espera;
			
			if (p[i].tempoCritico < 0) {
				pacientesCriticos++;
			}
			//printf("\n(%d)\nC: %d\ntC: %d\nS: %d\n", i, p[i].chegada, p[i].tempoCritico, p[i].saida);
			continue;
		}
		else {
			p[i].saida = p[i].chegada;
		}

		difTempo = horaRedonda - p[i - 1].saida;

		if (difTempo < 0) {
			espera += -difTempo;
		}

		p[i].saida += espera;
		p[i].tempoCritico -= espera;
		
		if (p[i].tempoCritico < 0) {
			pacientesCriticos++;
		}

		p[i].saida += TEMPO_CONSULTA;

		//printf("\n(%d)\nC:%d\nCr: %d\ntC: %d\nS: %d\n", i, p[i].chegada, horaRedonda, p[i].tempoCritico, p[i].saida);
	}

	return pacientesCriticos;
}

void free_vetor(struct vetor *vet)
{
	free(vet->ptr);
	vet->ptr = NULL;
	vet->tam = 0;
}

int main (void)
{
	struct vetor vetor;

	scanf(" %d", &vetor.tam);
	aloca_vetor(&vetor);
	registra_pacientes(&vetor);
	printf("%d\n", pacientes_criticos(&vetor));
	free_vetor(&vetor);
	return 0;
}
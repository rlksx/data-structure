/* 2)	Construa um algoritmo que contenha uma lista estática heterogênea para guardar dados cadastrais de dez softwares, solicite ao usuário digitar, nome, fabricante, tipo de licença e versão. */
#include <stdio.h>
#include <stdlib.h>

#define TAM 3

typedef struct {
	char nome[50], fabricante[50], licenca[50], versao[50];
} Software;

Software entrada(void);
void saida(Software a);

int main(void) {
	Software bd[TAM];
	int i;

	for (i = 0; i < TAM; i++) {
		system("cls");
		printf("Dados %i\n", i + 1);
		bd[i] = entrada();
	}

	printf("Nome\tFabricante\tLicenca\tVersao\n\n");
	for (i = 0; i < TAM; i++) {
		saida(bd[i]);
	}
	return 0;
}
/* 2)	Construa um algoritmo que contenha uma lista estática heterogênea para guardar dados cadastrais de dez softwares, 
solicite ao usuário digitar, nome, fabricante, tipo de licença e versão. */

#include <stdio.h>
#include <stdlib.h>

#define TAM 3

typedef struct{
	char nome[50], fabricante[50], licenca[50], versao[50];
}Software;

Software entrada(void);
void saida(Software a);

int main(void){
	Software bd[TAM];
	int i;
	
	for(i=0;i<TAM;i++) {
		system("clear");
		printf("Dados %i\n",i+1);
		bd[i]=entrada();
	}
	
	printf("Nome\tFabricante\tLicenca\tVersao\n\n");
	for(i=0;i<TAM;i++){
		saida(bd[i]);
	}
	
	return 0;
}

Software entrada(void) {
	Software a;
	
	printf("Digite o nome: ");
	gets(a.nome); 
	fflush(stdin);
	printf("Digite o fabricante: ");
	gets(a.fabricante); 
	fflush(stdin);
	printf("Digite o licenca: ");
	gets(a.licenca); 
	fflush(stdin);
	printf("Digite o versao: ");
	gets(a.versao); 
	fflush(stdin);
	
	return a;
}
void saida(Software a) {
	printf("%s\t%s\t%s\t%s\n",a.nome,a.fabricante,a.licenca,a.versao);
}
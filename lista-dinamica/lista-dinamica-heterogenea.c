// Lista dinâmica heterogênea;
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	char nome[50];
	int idade;
	struct lista *prox;
}LISTA;

int main(void){
	// variáveis
	LISTA *inicio = NULL;
	int i;
	
	// entrada 1
	for(i=1;i<=3;i++){
		LISTA *novo = (LISTA*) malloc(sizeof(LISTA));
		printf("Digite um nome: ");
		gets(novo->nome);
		fflush(stdin);
		printf("Digite a idade: ");
		scanf("%i",&novo->idade);
		fflush(stdin);
		if(inicio==NULL){
			novo->prox=NULL;
			inicio=novo;
		}else{
			novo->prox=inicio;
			inicio=novo;
		}
	}
		
	// saída
	LISTA *aux = inicio;
	while(aux!=NULL){
		printf("Nome = %s\n",aux->nome);
		printf("Idade = %i\n",aux->idade);
		aux=aux->prox;
	}
	
	return 0;
}
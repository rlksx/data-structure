/* 6. Faça um algoritmo que leia duas sequências de nomes de pessoas e armazene-os em duas listas simplesmente encadeadas lista1 e L2, respectivamente. Em seguida, o programa deve criar uma terceira lista encadeada, contendo os nomes comuns às duas listas e mostrar a lista resultante.
Exemplo:
- lista1 = Joana, Laura, Sérgio, Fábio.
- L2 = Anita, Joaquim, Fábio, Joana, Pedro, Sílvia.
- Resultado = Joana, Fábio. */

/*
6. Faça um algoritmo que leia duas sequências de nomes de pessoas e armazene-os em duas listas simplesmente encadeadas L1 e L2, 
respectivamente. Em seguida, o programa deve criar uma terceira lista encadeada, contendo os nomes comuns às duas 
listas e mostrar a lista resultante.
Exemplo:
- L1 = Joana, Laura, Sérgio, Fábio.
- L2 = Anita, Joaquim, Fábio, Joana, Pedro, Sílvia.
- L3 = Joana, Fábio.
R.:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
	char nome[30];
	struct lista *prox;
}LISTA;

LISTA* inserir (LISTA *l, char nome[]){
	LISTA *aux;
	LISTA *novo = (LISTA*) malloc(sizeof(LISTA));
	strcpy(novo->nome, nome);
	novo->prox = NULL;
	
	if (l == NULL) {
        l = novo;
    } else {
        aux = l;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return l;
}

int main (void){
	LISTA *L1 = NULL;
    LISTA *L2 = NULL;
    LISTA *L3 = NULL;
    // os objetos aux1 e aux2 são objetos auxiliares
    LISTA *aux1, *aux2;
    // apresentando o menu de opções
    int achou;
    char nome[30];

    printf("\n Lista 1 \n Digite um nome ('fim' para parar): ");    
    gets(nome);
    fflush(stdin);
    
    while (strcmp(nome, "fim") != 0) {
        L1 = inserir(L1, nome);
        // leitura do próximo nome
        printf("\n Lista 1 \n Digite um nome ('fim' para parar): ");    
	    gets(nome);
	    fflush(stdin);
    }
    
    // Leitura dos números da 2ª lista 
    printf("\n Lista 2 \n Digite um nome ('fim' para parar): ");    
    gets(nome);
    fflush(stdin);
    while (strcmp(nome, "fim")!=0) {
        L2 = inserir(L2, nome);
        // leitura do próximo nome
        printf("\n Lista 2 \n Digite um nome ('fim' para parar): ");    
	    gets(nome);
	    fflush(stdin);
    }
    
    // Criando a lista contendo os nomes em comum nas duas listas
    aux1 = L1;
    while (aux1 != NULL) {
        aux2 = L2;
        achou = 0;
        while (aux2 != NULL) {
            if (strcmp(aux1->nome, aux2->nome) == 0) {
                achou = 1;
            }
            aux2 = aux2->prox;
        }
        if (achou == 1) {
            L3 = inserir(L3, aux1->nome);
        }
        aux1 = aux1->prox;
    }
    
    // Impressão da lista
    if (L3 == NULL) {
        printf("As listas não possuem nomes em comum.\n");
    } else {
        printf("Nomes presentes em ambas as listas: \n");
        aux1 = L3;
        while (aux1 != NULL) {
            printf("%s\n",aux1->nome);
            aux1 = aux1->prox;
        }
    }
}


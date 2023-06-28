/* 3)	Construa um algoritmo que contenha uma lista dinâmica homogênea para guardar números digitados pelo usuário,
solicite ao usuário a quantidade de número e os números e depois os imprima em tela. */

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
   int n;
   struct lista *prox;
} LISTA;

LISTA *entrada(LISTA *l, int n);
void saida(LISTA *l);

int main(void) {
   system("clear");
   LISTA *inicio = NULL;
   int n, i = 0, qtd;

   printf("Digite a quantidade de numeros: ");
   scanf("%i", &qtd);
   while (i < qtd) {
      printf("Digite o %i numero: ", i+1);
      scanf("%i", &n);
      inicio = entrada(inicio, n);
      i++;
   }
   saida(inicio);
   return 0;
}

LISTA *entrada(LISTA *l, int n) {
   LISTA *novo = (LISTA *)malloc(sizeof(LISTA));
   novo->n = n;
   novo->prox = l;
   l = novo;

   return l;
}

void saida(LISTA *l) {
   while (l != NULL) {
      printf("%i  ", l->n);
      l = l->prox;
   }
}
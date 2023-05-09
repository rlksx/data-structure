/* 5. Elabore um algoritmo que leia uma sequência de números, armazenando-os numa lista simplesmente encadeada e que, em seguida,
verifique se a lista linear encadeada está ordenada. Suponha que a lista não contenha números repetidos. */

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
   int numero;
   struct lista *prox;
} LISTA;

LISTA* inserirNumero(int novoNumero, LISTA *listaAtual) {
   LISTA *novaLista = (LISTA *)malloc(sizeof(LISTA));
   novaLista->numero = novoNumero;
   novaLista->prox = listaAtual;
   return novaLista;
}

void verificarOrdenacao(LISTA *lista) {
   while(lista != NULL && lista->prox != NULL) {
      
      if(lista->numero < lista->prox->numero) {
         printf("lista não esta ordenada");
         return;
      }

      lista = lista->prox;
   }
   printf("lista esta ordenada");
}

int main(void) {
   system("clear");

   LISTA *listaAtual = NULL;
   int qntNumero, i, numero;

   printf("Digite a quantidade de numeros: ");
   scanf("%i", &qntNumero);

   for (i = 0; i < qntNumero; i++) {
      printf("Digite o %i numero: ", i + 1);
      scanf("%i", &numero);

      listaAtual = inserirNumero(numero, listaAtual);
   }
   verificarOrdenacao(listaAtual);

   return 0;
}

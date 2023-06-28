/* 5. Elabore um algoritmo que leia uma sequência de números, armazenando-os numa lista simplesmente encadeada e que, em seguida, verifique se a lista linear encadeada está ordenada. Suponha que a lista não contenha números repetidos. */

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
   int num;
   struct lista *prox;
} LISTA;

// USANDO CONCEITO DE PILHA (LIFO)
LISTA *inserir1(LISTA *lista, int n) {
   LISTA *novaLista = (LISTA *)malloc(sizeof(LISTA));
   novaLista->num = n;
   novaLista->prox = lista;
   lista = novaLista;
   return novaLista;
}

// USANDO CONCEITO DE FILA (FIFO)
LISTA *inserir2(LISTA *lista, int n) {
   LISTA *novaLista = (LISTA *)malloc(sizeof(LISTA));
   LISTA *aux;
   novaLista->num = n;
   novaLista->prox = NULL;

   if (lista == NULL) 
      lista = novaLista;
   else {
      aux = lista;
      while (aux->prox != NULL)
         aux = aux->prox;

      aux->prox = novaLista;
   }
   return lista;
}

LISTA *imprimir(LISTA *lista) {
   if (lista != NULL) {
      printf("%i  ", lista->num);
      return imprimir(lista->prox);
   }
}

int main(void) {
   system("clear");

   LISTA *listaAtual = NULL;
   int numero;

   do {
      printf("Digite os numeros (-1 para parar): ");
      scanf("%i", &numero);
      if (numero != -1)
         listaAtual = inserir1(listaAtual, numero);
   } while (numero != -1);

   imprimir(listaAtual);

   return 0;
}
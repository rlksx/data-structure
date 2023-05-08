/* 5. Elabore um algoritmo que leia uma sequência de números, armazenando-os numa lista simplesmente encadeada e que, em seguida,
verifique se a lista linear encadeada está ordenada. Suponha que a lista não contenha números repetidos. */

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
   int numero;
   struct lista *prox;
}LISTA;


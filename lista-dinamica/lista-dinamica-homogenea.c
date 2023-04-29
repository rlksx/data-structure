/* lista dinâmica heterogênea:
-> sizeof retorna o tamanho em bytes de um tipo de dado e
-> o malloc aloca na memória.
->  (LISTA *) malloc(sizeof(LISTA) faz o casting para o tipo LISTA e aloca o espaço na memória */

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
   int numero;
   struct lista *prox;
} LISTA;

int main(void) {
   LISTA *inicio = NULL;

   // 1° entrada
   LISTA *novo = (LISTA *) malloc(sizeof(LISTA));
   printf("Digite um valor: ");
   scanf("%i", &novo->numero);
   novo->prox = NULL;
   inicio = novo;

   // 2° entrada
   novo = (LISTA *) malloc(sizeof(LISTA));
   printf("Digite um valor: ");
   scanf("%i", &novo->numero);
   novo->prox = NULL;
   inicio = novo;

   // 3° entrada
   novo = (LISTA *) malloc(sizeof(LISTA));
   printf("Digite um valor: ");
   scanf("%i", &novo->numero);
   novo->prox = NULL;
   inicio = novo;

   // saída
   while(inicio != NULL) {
      printf("%i\n", inicio->numero);
      inicio = inicio->prox;
   }


   return 0;
}

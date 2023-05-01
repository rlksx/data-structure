/* 3. Construa um algoritmo que contenha uma lista dinâmica homogênea para guardar números digitados pelo usuário, 
solicite ao usuário a quantidade de número e os números e depois os imprima em tela. */

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
   int numero;
   struct list *prox; 
} LISTA;

LISTA* inserir(LISTA *listaAtual, int novoNumero) {
   LISTA *novaLista = (LISTA *) malloc(sizeof(LISTA));
   novaLista->numero = novoNumero;
   novaLista->prox = listaAtual;
   listaAtual = novaLista;

   return listaAtual;
}

void imprimirLista(LISTA *listaAtual) {
   while(listaAtual != NULL){
      printf("%d  ", listaAtual->numero);
      listaAtual = listaAtual->prox;
   }
}

int main(void) {
   system("clear");
   int qntNumeros, numero;
   LISTA *listaAtual = NULL;

   printf("Quantidade de numeros: ");
   scanf("%d", &qntNumeros);
   fflush(stdin);

   for(int i = 0; i < qntNumeros; i++) {
      printf("Digite o %d numero: ", i+1);
      scanf("%d", &numero);
      fflush(stdin);

      listaAtual = inserir(listaAtual, numero);
   }

   printf("\nNumeros digitados: ");
   imprimirLista(listaAtual);

   return 0;
}


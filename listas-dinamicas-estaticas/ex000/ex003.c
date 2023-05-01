/* 3. Construa um algoritmo que contenha uma lista dinâmica homogênea para guardar números digitados pelo usuário, 
solicite ao usuário a quantidade de número e os números e depois os imprima em tela. */

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
   int numero;
   struct list *prox; 
} LISTA;

LISTA* inserir(LISTA *inicio, int novoNumero){
   LISTA *novo = (LISTA *) malloc(sizeof(LISTA));
   novo->numero = novoNumero;
   novo->prox = inicio;
   inicio = novo; 

   return inicio;
}

void imprimir(LISTA *inicio){
   while(inicio != NULL){
      printf("%d  ", inicio->numero);
      inicio = inicio->prox;
   }
}

int main(void){
   system("clear");
   int qntNumeros, numero;
   LISTA *inicio = NULL;

   printf("Quantidade de numeros: ");
   scanf("%d", &qntNumeros);
   fflush(stdin);

   for(int i = 0; i < qntNumeros; i++){
      printf("Digite o %d numero: ", i+1);
      scanf("%d", &numero);
      fflush(stdin);

      inicio = inserir(inicio, numero);
   }

   printf("\nNumeros digitados: ");
   imprimir(inicio);

   return 0;
}


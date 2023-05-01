/* 3. Construa um algoritmo que contenha uma lista dinâmica homogênea para guardar números digitados pelo usuário, 
solicite ao usuário a quantidade de número e os números e depois os imprima em tela. */

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
   int num;
   struct lista *prox;
} NUMEROS;

int main(void){
   NUMEROS *inicio = NULL;
   NUMEROS *novo = NULL;
   int qntNumeros;

   printf("Quantidade de Numeros: ");
   scanf("%i", &qntNumeros);

   for(int i=0; i<qntNumeros; i++){
      novo = (NUMEROS *) malloc(sizeof(NUMEROS));
      printf("Digite o %i numero: ", i+1);
      scanf("%i", &novo->num); 
      novo->prox = NULL;
      inicio = novo;
   }
   
   int i = 1;
   while(inicio != NULL){
      printf("O %d numero eh: %d", i, inicio->num);
      inicio = inicio->prox;
      i++;
   }

   return 0;
}
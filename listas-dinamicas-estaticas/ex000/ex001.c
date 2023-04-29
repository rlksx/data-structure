/* 1. Construa um algoritmo que contenha uma lista estática homogênea para guardar seis números reais, 
solicite ao usuário os números e apresente para ele a média dos números. */

#include <stdio.h>
#include <stdlib.h>

int main(void){
   float num[6], media;

   for(int i=0; i<6; i++){
      printf("Digite um numero: ");
      scanf("%f", &num[i]);
   }

   for(int i=0; i<6; i++){
      media += num[i];
   }
   media /= 6;

   printf("A media dos numeros digitados eh: %.2f\n", media);
}
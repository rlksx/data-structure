/* 1. Construa um algoritmo que contenha uma lista estática homogênea para guardar seis números reais, 
solicite ao usuário os números e apresente para ele a média dos números. */

#include <stdio.h> 
#include <stdlib.h>

void entrada(float *n);
float media(float *n);

int main(void) {
   float n[6];

   entrada(n);
   printf("A media é %f ", media(n));

   return 0;
}

void entrada(float *n) {
   int i;
   for(i = 0; i < 6; i++) {
      printf("Digite %i numero: ", i+1);
      scanf("%f", &n[i]);
   }
}

float media(float *n) {
   float m=0;
   int i=0;
   
   for(i=0; i<6; i++) {
      m+=n[i];
   }

   return m/6;
}
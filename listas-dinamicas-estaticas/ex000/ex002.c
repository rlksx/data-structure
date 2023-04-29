/* 2. Construa um algoritmo que contenha uma lista estática heterogênea para guardar dados cadastrais de dez softwares,
solicite ao usuário digitar, nome, fabricante, tipo de licença e versão. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
   char nome[30];
   char fabricante[30];
   char tipoLicenca[30];
   float versao;
} Software;

int main(void){
   Software software[10];

   for(int i = 0; i < 10; i++){
      printf("*======================================*\n");

      printf("Nome do %i software: ", i+1);
      scanf("%s", software[i].nome);
      fflush(stdin);

      printf("Fabricante do %i software: ", i+1);
      scanf("%s", software[i].fabricante);
      fflush(stdin);

      printf("Tipo de Licenca do %i software: ", i+1);
      scanf("%s", software[i].tipoLicenca);
      fflush(stdin);

      printf("Versao do %i software: ", i+1);
      scanf("%f", &software[i].versao);
      fflush(stdin);
   }
   printf("*======================================*\n");
}
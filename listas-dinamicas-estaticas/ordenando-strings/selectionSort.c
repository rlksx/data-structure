#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort(char strings[5][50], int tamanho);

int main() {
   system("clear");
   char strings[5][50] = {"Pedro", "Ryan", "Gabriel", "Guilherme", "Amanda"};
   int i;

   selectionSort(strings, 5);
   printf("Strings ordenados:  ");
   for (i = 0; i < 5; i++) {
      printf("%s  ", strings[i]);
   }
   return 0;
}
// não ordenavel e ordenavel
void selectionSort(char strings[5][50], int tamanho) {
   int i, j, k;
   char aux[50];

   for (i = 0; i < tamanho - 1; i++) {
      k = i;
      for (j = i + 1; j < tamanho; j++) {
         if (strcmp(strings[j], strings[k]) < 0)
            k = j;
      }
      if (k != i)
      {
         strcpy(aux, strings[i]);
         strcpy(strings[i], strings[k]);
         strcpy(strings[k], aux);
      }
   }
}
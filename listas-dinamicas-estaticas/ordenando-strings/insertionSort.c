#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(char strings[5][50], int n); 

int main() {
   system("clear");
   char strings[5][50] = {"Pedro", "Ryan", "Gabriel", "Guilherme", "Amanda"};
   int i;

   insertionSort(strings, 5);
   printf("Nomes ordenados:  ");
   for (i = 0; i < 5; i++) {
      printf("%s  ", strings[i]);
   }
   return 0;
}
// esquerda para direita
void insertionSort(char strings[5][50], int n) {
   int i, j;
   char aux[100];
   for (i = 1; i < n; i++) {
      strcpy(aux, strings[i]);
      j = i - 1;
      while (j >= 0 && strcmp(strings[j], aux) > 0) {
         strcpy(strings[j + 1], strings[j]);
         j--;
      }

      strcpy(strings[j + 1], aux);
   }
}
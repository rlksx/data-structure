#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(char strings[5][50], int low, int high);

int main() {
   system("clear");
   char strings[5][50] = {"Pedro", "Ryan", "Gabriel", "Guilherme", "Amanda"};
   int i;

   quicksort(strings, 0, 5 - 1);
   
   printf("Strings ordenadas:  ");
   for (i = 0; i < 5; i++) {
      printf("%s  ", strings[i]);
   }

   return 0;
}

void quicksort(char strings[5][50], int low, int high) {
   if (low < high) {
      char pivo[50];
      strcpy(pivo, strings[high]);
      int i = low - 1;
      
      for (int j = low; j <= high; j++) {
         if (strcmp(strings[j], pivo) < 0) {
            char aux[50];
            strcpy(aux, strings[i + 1]);
            strcpy(strings[i + 1], strings[j]);
            strcpy(strings[j], aux);
            i++;
         }
      }

      char aux[50];
      strcpy(aux, strings[i + 1]);
      strcpy(strings[i + 1], strings[high]);
      strcpy(strings[high], aux);
      int pi = i + 1;

      quicksort(strings, low, pi - 1);
      quicksort(strings, pi + 1, high);
   }
}

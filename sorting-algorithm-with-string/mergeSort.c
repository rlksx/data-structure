#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intercalar(char string[][50], int inicio, int meio, int fim);
void mergeSort(char string[][50], int inicio, int fim);

int main() {
   system("clear");
   char string[5][50] = {"Pedro", "Ryan", "Gabriel", "Guilherme", "Amanda"};
   int i;

   mergeSort(string, 0, 5 - 1);

   printf("Strings ordenadas: ");
   for (i = 0; i < 5; i++) {
      printf("%s  ", string[i]);
   }

   return 0;
}
// dividindo até ordenar e voltar ordenando
void mergeSort(char string[][50], int inicio, int fim) {
   if (inicio < fim) {
      int meio = inicio + (fim - inicio) / 2;

      mergeSort(string, inicio, meio);
      mergeSort(string, meio + 1, fim);

      intercalar(string, inicio, meio, fim);
   }
}

void intercalar(char string[][50], int inicio, int meio, int fim) {
   int i, j, k;
   int n1 = meio - inicio + 1;
   int n2 = fim - meio;

   char L[n1][50], R[n2][50];

   for (i = 0; i < n1; i++) {
      strcpy(L[i], string[inicio + i]);
   }
   for (j = 0; j < n2; j++) {
      strcpy(R[j], string[meio + 1 + j]);
   }

   i = 0;
   j = 0;
   k = inicio;

   while (i < n1 && j < n2) {
      if (strcmp(L[i], R[j]) <= 0) {
         strcpy(string[k], L[i]);
         i++;
      }
      else {
         strcpy(string[k], R[j]);
         j++;
      }
      k++;
   }

   while (i < n1) {
      strcpy(string[k], L[i]);
      i++;
      k++;
   }

   while (j < n2) {
      strcpy(string[k], R[j]);
      j++;
      k++;
   }
}
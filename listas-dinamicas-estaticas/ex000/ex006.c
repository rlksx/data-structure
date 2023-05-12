/* 6. Faça um algoritmo que leia duas sequências de nomes de pessoas e armazene-os em duas listas simplesmente encadeadas L1 e L2, respectivamente. Em seguida, o programa deve criar uma terceira lista encadeada, contendo os nomes comuns às duas listas e mostrar a lista resultante. 
Exemplo: 
- L1 = Joana, Laura, Sérgio, Fábio. 
- L2 = Anita, Joaquim, Fábio, Joana, Pedro, Sílvia. 
- L3 = Joana, Fábio. */

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
   char nome[15];
   struct list *list;
} LISTA;

int main(void) {
   LISTA *lista1 = NULL;
   LISTA *lista2 = NULL;
   LISTA *resultado = NULL;
   int i, qnt;
   char nome[15];

   printf("Quantidade de nomes da primeira lista: ");
   scanf("%i", &qnt);
   
   for(i = 0; i < qnt; i++) {
      printf("digite o %i nome: ", i+1);
      gets(nome);
   }
}
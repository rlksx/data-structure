/* 6. Faça um algoritmo que leia duas sequências de nomes de pessoas e armazene-os em duas listas simplesmente encadeadas L1 e L2, respectivamente. Em seguida, o programa deve criar uma terceira lista encadeada, contendo os nomes comuns às duas listas e mostrar a lista resultante.
Exemplo:
- L1 = Joana, Laura, Sérgio, Fábio.
- L2 = Anita, Joaquim, Fábio, Joana, Pedro, Sílvia.
- L3 = Joana, Fábio. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
   char nome[15];
   struct list *prox;
} LISTA;

LISTA *inserirNome(LISTA *listaAtual, char nome[15])
{
   LISTA *novaLista = (LISTA *)malloc(sizeof(LISTA));
   strcpy(novaLista->nome, nome);
   novaLista->prox = listaAtual;

   return novaLista;
}

LISTA *compararListas(LISTA *lista1, LISTA *lista2)
{
   LISTA *resultado = NULL;
   while (lista1 != NULL)
   {
      while (lista2 != NULL)
      {
         if (strcmp(lista1->nome, lista2->nome) == 0)
         {
            resultado = inserirNome(resultado, lista1->nome);
            break;
         }
         lista2 = lista2->prox;
      }
      lista1 = lista1->prox;
   }
   return resultado;
}

void imprimirResultado(LISTA *resultado)
{
   while (resultado != NULL)
   {
      printf("%s  ", resultado->nome);
      resultado = resultado->prox;
   }
}

int main(void)
{
   system("clear");
   LISTA *lista1 = NULL;
   LISTA *lista2 = NULL;
   LISTA *resultado = NULL;
   int i, qnt;
   char nome[15];

   printf("Quantidade de nomes da primeira lista: ");
   scanf("%i", &qnt);
   fflush(stdin);

   for (i = 0; i < qnt; i++)
   {
      printf("digite o %i nome: ", i + 1);
      scanf("%s", nome);
      fflush(stdin);

      lista1 = inserirNome(lista1, nome);
   }

   printf("Quantidade de nomes da segunda lista: ");
   scanf("%i", &qnt);
   fflush(stdin);

   for (i = 0; i < qnt; i++)
   {
      printf("digite o %i nome: ", i + 1);
      scanf("%s", nome);
      fflush(stdin);

      lista2 = inserirNome(lista2, nome);
   }

   resultado = compararListas(lista1, lista2);
   printf("Nomes em comum: ");
   imprimirResultado(resultado);

   return 0;
}
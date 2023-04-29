/* lista dinâmica hemogenea:
-> sizeof retorna o tamanho em bytes de um tipo de dado e
-> o malloc aloca na memória.
->  (LISTA *) malloc(sizeof(LISTA) faz o casting para o tipo LISTA e aloca o espaço na memória */

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
   int numero;        // campo de dados do nó, neste caso, um número inteiro
   struct lista *prox; // ponteiro para o próximo nó da lista
} LISTA;

int main(void) {
   LISTA *inicio = NULL;  // cria um ponteiro para o início da lista, inicialmente vazio

   // 1° entrada
   LISTA *novo = (LISTA *) malloc(sizeof(LISTA));  // aloca memória para um novo nó da lista
   printf("Digite um valor: ");
   scanf("%i", &novo->numero);  // lê um número inteiro digitado pelo usuário e o armazena no campo de dados do novo nó
   novo->prox = NULL;  // define o próximo nó como nulo, pois este é o último nó da lista
   inicio = novo;  // faz o ponteiro de início apontar para o novo nó, tornando-o o primeiro nó da lista

   // 2° entrada
   novo = (LISTA *) malloc(sizeof(LISTA));  // aloca memória para um novo nó da lista
   printf("Digite um valor: ");
   scanf("%i", &novo->numero);  // lê um número inteiro digitado pelo usuário e o armazena no campo de dados do novo nó
   novo->prox = NULL;  // define o próximo nó como nulo, pois este é o último nó da lista
   inicio = novo;  // faz o ponteiro de início apontar para o novo nó, tornando-o o primeiro nó da lista

   // 3° entrada
   novo = (LISTA *) malloc(sizeof(LISTA));  // aloca memória para um novo nó da lista
   printf("Digite um valor: ");
   scanf("%i", &novo->numero);  // lê um número inteiro digitado pelo usuário e o armazena no campo de dados do novo nó
   novo->prox = NULL;  // define o próximo nó como nulo, pois este é o último nó da lista
   inicio = novo;  // faz o ponteiro de início apontar para o novo nó, tornando-o o primeiro nó da lista

   // saída
   while(inicio != NULL) {  // enquanto não chegou ao fim da lista (ou seja, enquanto o ponteiro de início não é nulo)
      printf("%i\n", inicio->numero);  // imprime o campo de dados do nó atual
      inicio = inicio->prox;  // faz o ponteiro de início apontar para o próximo nó da lista
   }

   return 0;
}


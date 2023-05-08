/* 4. Construa um algoritmo que contenha uma lista dinâmica heterogênea onde o usuário deverá informar quantidade de disciplinas que ele tem e os dados de cada disciplina como: sala, dia da semana, nome disciplina e semestre e depois o algoritmo deve imprimir estes dados em tela. */

#include <stdio.h>
#include <stdlib.h>

typedef struct diciplina{
   int sala;
   char dia[30];
   char nome[50];
   int semestre;
} Diciplina;

typedef struct list {
   Diciplina diciplina;
   struct list *prox;
} LISTA;

LISTA *inserir(LISTA *listaAtual, Diciplina novaDiciplina);
void imprimirLista(LISTA *lista);

int main(void) {
   system("clear");

   LISTA *listaAtual = NULL;
   int qntDiciplina;

   printf("Quantidade de diciplina: ");
   scanf("%d", &qntDiciplina);
   

   Diciplina diciplina;
   for(int i = 0; i < qntDiciplina; i++) {
      printf("\n * Adicione %d diciplina * \n", i+1);

      printf("Nome: "); scanf("%s", &diciplina.nome);  getchar();
      printf("Semestre: "); scanf("%d", &diciplina.semestre); 
      printf("Sala: "); scanf("%d", &diciplina.sala); 
      printf("Dia: "); scanf("%s", &diciplina.dia); getchar();

      listaAtual = inserir(listaAtual, diciplina);
   }

   system("clear");
   imprimirLista(listaAtual);

   return 0;
}

LISTA *inserir(LISTA *listaAtual, Diciplina novaDiciplina) {
   LISTA *novaLista = (LISTA *)malloc(sizeof(LISTA));
   novaLista->diciplina = novaDiciplina;
   novaLista->prox = listaAtual;
   listaAtual = novaLista;

   return listaAtual;
}

void imprimirLista(LISTA *lista){
   int i = 1;
   while (lista != NULL) {
      printf("%d: ", i);
      printf("Nome: %s | Semestre: %d | ", lista->diciplina.nome, lista->diciplina.semestre);
      printf("Sala: %d | Dia: %s\n", lista->diciplina.sala, lista->diciplina.dia);

      lista = lista->prox;
      i++;
   }
}

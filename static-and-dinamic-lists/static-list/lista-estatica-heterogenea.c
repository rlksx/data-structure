/* exemplo de lista estática:
-> permite a adição de novos elementos á lista
-> há mais de um tipo de dado na lista, no exemplo um int e um char. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int idade;
   char nome[30];
} Pessoa;

int main(void){
   Pessoa pessoa[10];

   for(int i=0; i<10; i++){
      printf("Digite o nome: ");
      scanf("%s", pessoa[i].nome);
      fflush(stdin);

      printf("Digite a idade: ");
      scanf("%d", &pessoa[i].idade);
      fflush(stdin);
   }

   for(int i=0; i<10; i++){
      printf("Nome: %s\n", pessoa[i].nome);
      printf("Idade: %d\n", pessoa[i].idade);
   }
}
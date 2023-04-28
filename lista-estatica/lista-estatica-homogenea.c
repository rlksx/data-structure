/* exemplo de lista estática homogênea:
-> não permite a adição de novos elementos á lista
-> todo lista é do mesmo tipo, no exempo um int. */

#include <stdio.h>  
#include <stdlib.h>

int main(void){
   int numero[10], i;

   for(i=0; i<10; i++){
      printf("Digite um numero: ");
      scanf("%d", &numero[i]);
   }

   for(i=0; i<10; i++){
      printf("%d\n", numero[i]);
   }
}
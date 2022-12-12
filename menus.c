
#include <stdio.h>
#include <stdlib.h>
#define DEZ 10
#define CEM 100
#define MIL 1000
#define DEZ_MIL 10000
#define CEM_MIL 100000
#define UM_MILHAO 1000000

int get_option() {
  system("cls || clear");
  int option;
    do {
      printf("<----------------------------------------------------------------------->\n");
      printf("Bem vindo...\n");
      printf("Escolha o tipo de relatorio que deseja gerar: \n");
      printf("-> 1- Individual\n");
      printf("-> 2- Completo\n");
      printf("-> 0- Sair\n");
      printf("<----------------------------------------------------------------------->\n");
      printf("-> ");
      scanf("%d",&option);
      if(option < 0 && option > 2) {
        printf("Escolha uma opcao valida!\n");
      }
    } while( option < 0 && option > 2 );
    return option;
}


char get_order() {
  char option;
  do {
    fflush(stdin);
    printf("<----------------------------------------------------------------------->\n");
    printf("Bem vindo...\n");
    printf("Digite um caractere de acordo com sua escolha de ordenacao: \n");
    printf("-> Crescente:   [c]\n");
    printf("-> Decrescente: [d]\n");
    printf("-> Randomico:   [r]\n");
    printf("-> Sair:        [s]\n");
    printf("<----------------------------------------------------------------------->\n");
    printf("-> ");
    option = getchar();
    fflush(stdin); // trocar pro windows cls
    if(option != 'c' && option != 'd'  && option != 'r'  && option != 's') {
      printf("Escolha uma opcao valida!\n");
    }
  } while( option != 'c' && option != 'd'  && option != 'r'  && option != 's' ); // checa se opção escolhida é valida para sair do loop
  return option;
}

int get_algorithm_option() {
  int option;
  do {
    fflush(stdin);
    printf("<----------------------------------------------------------------------->\n");
    printf("Escolha um algoritmo: \n");
    printf("-> Insertion-sort:     [1]\n");
    printf("-> Bubble-sort:        [2]\n");
    printf("-> Selection-sort:     [3]\n");
    printf("-> Shell-sort:         [4]\n");
    printf("-> Merge-sort:         [5]\n");
    printf("-> Quick-sort-Um:      [6]\n");
    printf("-> Quick-sort-Random:  [7]\n");
    printf("-> Quick-sort-Mediana: [8]\n");
    printf("-> Quick-sort-Media:   [9]\n");
    printf("-> Sair:               [0]\n");
    printf("<----------------------------------------------------------------------->\n");
    printf("-> ");
    scanf("%d",&option);
    if(option < 0 && option > 4) {
      printf("Escolha uma opcao valida!\n");
    }
  } while(option < 0 && option > 4); // checa se opção escolhida é valida para sair do loop
  return option;
}

int get_array_size() {
  system("cls || clear");
  int option;
    do {
      printf("<----------------------------------------------------------------------->\n");
      printf("Bem vindo...\n");
      printf("Escolha o tamanho da amostra que deseja testar: \n");
      printf("-> 1- 10\n");
      printf("-> 2- 100\n");
      printf("-> 3- 1000\n");
      printf("-> 4- 10000\n");
      printf("-> 5- 100000\n");
      printf("-> 6- 1000000\n");
      printf("-> 0- Sair\n");
      printf("<----------------------------------------------------------------------->\n");
      printf("-> ");
      scanf("%d",&option);
      if(option < 0 && option > 6) {
        printf("Escolha uma opcao valida!\n");
      }
    } while( option < 0 && option > 6 );
  switch (option) {
    case 1:
      return DEZ;
      break;
    case 2:
      return CEM;
      break;
    case 3:
      return MIL;
      break;
    case 4:
      return DEZ_MIL;
      break;
    case 5:
      return CEM_MIL;
      break;
    case 6:
      return UM_MILHAO;
      break;
    case 0:
      return 0;
      break;
    default:
      break;
  }
}
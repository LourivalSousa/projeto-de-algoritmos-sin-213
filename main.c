#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "algoritmos.c"
#include "menus.c"

#define DEZ 10
#define CEM 100
#define MIL 1000
#define DEZ_MIL 10000
#define CEM_MIL 100000
#define UM_MILHAO 1000000

#define INSERTION "Insertion-Sort"
#define BUBBLE "Bubble-Sort"
#define SELECTION "Selection-Sort"
#define SHELL "Shell-Sort"
#define MERGE "Merge-Sort"
#define QUICK_UM "Quick-Sort-Um"
#define QUICK_DOIS "Quick-Sort-random"
#define QUICK_TRES "Quick-Sort-median"
#define QUICK_QUATRO "Quick-Sort-avarage"

/*
Aluno: Lourival Teixeira de Sousa
Matricula: 6012 
*/

int* aloc_array(int size) {
  return (int*) malloc(size * sizeof(int));
}

void create_nested_folders(char *path, char *sufix) {
  struct stat st = {0};
  char folder_name[30];
  strcpy(folder_name, path);
  strcat(folder_name, sufix);
  if (stat(folder_name, &st) == -1) {
      if (mkdir(folder_name, 0700) == -1) {
        exit(1);
      }
    }
}

void create_folders_setup(char *folder_name) {
  struct stat st = {0};
  int size = DEZ;
  char number_in_str[10];

  if (stat(folder_name, &st) == -1) {
    mkdir(folder_name, 0700);
  }

  while (size <= UM_MILHAO) {
    char path[30];
    sprintf(number_in_str, "%d", size);
    strcpy(path, folder_name);
    strcat(path, "/");
    strcat(path, number_in_str);
    if (stat(path, &st) == -1) {
      if (mkdir(path, 0700) == -1) {
        exit(1);
      }
    }
    create_nested_folders(path,"/crescente");
    create_nested_folders(path,"/decrescente");
    create_nested_folders(path,"/random");
    size *= 10;
  }
  system("cls || clear");
}



double  measure_time_of_exec(int *array, int array_size) {
  clock_t start, end;
  double time_of_exec;
  start = clock();

  insertionSort(array,array_size);

  end = clock();
  time_of_exec = (double)(end - start) / CLOCKS_PER_SEC;
  return time_of_exec;
}

int generate_random_number() {
  time_t t;
  srand((unsigned) time(&t));
  return rand();
}


void populate_array_ASC_order(int *array,int array_size) {
  int seed = generate_random_number();
  int i;
  for(i = 0; i < array_size; i++) {
    array[i] = seed + i;
  }
}

void populate_array_DESC_order(int *array,int array_size) {
  int seed = generate_random_number();
  int i;
  int quant_elements = array_size - 1 ; 
  for(i =0 ; i <= quant_elements; i++) {
    array[i] = seed + (quant_elements - i);
  }
}

void populate_array_RAND_order(int *array,int array_size) {
  int i;
  int seed = generate_random_number();
  srand((unsigned) seed);
  for(i=0; i < array_size; i++) {
    array[i] =  rand();
  }
}


void save_file(int *array,int size, char order, char *file_type, char *algorithm) {
  FILE *file_pointer;
  char path_name[50], file_name[30], number_in_str_format[10];
  sprintf(number_in_str_format, "%d", size); 
  strcpy(path_name,algorithm);
  strcat(path_name,number_in_str_format);
  strcpy(file_name,file_type);
  switch (order) {
    case 'c':
      strcat(path_name,"/crescente/");
      break;
    case 'd':
      strcat(path_name,"/decrescente/");
      break;
    case 'r':
      strcat(path_name,"/random/");
      break;
    default:
      break;
  }
  
  strcat(file_name,".txt");
  strcat(path_name,file_name);

  file_pointer = fopen(path_name,"w");
  fprintf(file_pointer,"%d\n",size);
  int i;
  for(i=0; i<size; i++) {
    fprintf(file_pointer,"%d\n",array[i]);
  }
  fclose(file_pointer);
  
}

void save_file_time_exec(double time,int size, char order, char *algorithm) {
  FILE *file_pointer;
  char path_name[50], file_name[30], number_in_str_format[10];
  sprintf(number_in_str_format, "%d", size); 
  strcpy(path_name,algorithm);
  strcat(path_name,number_in_str_format);
  strcpy(file_name,"tempoexecucao");
  switch (order) {
    case 'c':
      strcat(path_name,"/crescente/");
      break;
    case 'd':
      strcat(path_name,"/decrescente/");
      break;
    case 'r':
      strcat(path_name,"/random/");
      break;
    default:
      break;
  }

  strcat(file_name,".txt");
  strcat(path_name,file_name);

  file_pointer = fopen(path_name,"w");

  fprintf(file_pointer,"%d\n",size);
  fprintf(file_pointer,"%lf\n",time);

  fclose(file_pointer); 

}

void measure_insertion_sort(int *array, int array_size, char order) {
  clock_t start, end;
  double time_of_exec;
  start = clock();
  save_file(array, array_size, order, "entrada","Insertion-Sort/");

  insertionSort(array,array_size);

  end = clock();
  time_of_exec = (double)(end - start) / CLOCKS_PER_SEC;
  save_file(array, array_size, order, "saida","Insertion-Sort/");
  save_file_time_exec(time_of_exec, array_size, order,"Insertion-Sort/");
}

void measure_bubble_sort(int *array, int array_size, char order) {
  clock_t start, end;
  double time_of_exec;
  start = clock();
  save_file(array, array_size, order, "entrada","Bubble-Sort/");

  bubbleSort(array,array_size);

  end = clock();
  time_of_exec = (double)(end - start) / CLOCKS_PER_SEC;
  save_file(array, array_size, order, "saida","Bubble-Sort/");
  save_file_time_exec(time_of_exec, array_size, order,"Bubble-Sort/");
}

void measure_selection_sort(int *array, int array_size, char order) {
  clock_t start, end;
  double time_of_exec;
  start = clock();
  save_file(array, array_size, order, "entrada","Selection-Sort/");

  selection_sort(array,array_size);

  end = clock();
  time_of_exec = (double)(end - start) / CLOCKS_PER_SEC;
  save_file(array, array_size, order, "saida","Selection-Sort/");
  save_file_time_exec(time_of_exec, array_size, order,"Selection-Sort/");
}

void measure_shell_sort(int *array, int array_size, char order) {
  clock_t start, end;
  double time_of_exec;
  start = clock();
  save_file(array, array_size, order, "entrada","Shell-Sort/");

  shellSort(array,array_size);

  end = clock();
  time_of_exec = (double)(end - start) / CLOCKS_PER_SEC;
  save_file(array, array_size, order, "saida","Shell-Sort/");
  save_file_time_exec(time_of_exec, array_size, order,"Shell-Sort/");
}

void measure_merge_sort(int *array, int array_size, char order) {
  clock_t start, end;
  double time_of_exec;
  start = clock();
  save_file(array, array_size, order, "entrada","Merge-Sort/");

  mergeSort(array,0,array_size - 1);

  end = clock();
  time_of_exec = (double)(end - start) / CLOCKS_PER_SEC;
  save_file(array, array_size, order, "saida","Merge-Sort/");
  save_file_time_exec(time_of_exec, array_size, order,"Merge-Sort/");
}

void measure_quick_sort_one(int *array, int array_size, char order) {
  clock_t start, end;
  double time_of_exec;
  start = clock();
  save_file(array, array_size, order, "entrada","Quick-sort-Um/");

  quick_sort_version_one(array,0,array_size - 1);

  end = clock();
  time_of_exec = (double)(end - start) / CLOCKS_PER_SEC;
  save_file(array, array_size, order, "saida","Quick-sort-Um/");
  save_file_time_exec(time_of_exec, array_size, order,"Quick-sort-Um/");
}

void measure_quick_sort_random(int *array, int array_size, char order) {
  clock_t start, end;
  double time_of_exec;
  start = clock();
  save_file(array, array_size, order, "entrada","Quick-sort-random/");

  quick_sort_random_pivot(array,0,array_size - 1);

  end = clock();
  time_of_exec = (double)(end - start) / CLOCKS_PER_SEC;
  save_file(array, array_size, order, "saida","Quick-sort-random/");
  save_file_time_exec(time_of_exec, array_size, order,"Quick-sort-random/");
}

void measure_quick_sort_median(int *array, int array_size, char order) {
  clock_t start, end;
  double time_of_exec;
  start = clock();
  save_file(array, array_size, order, "entrada","Quick-sort-median/");

  quick_sort_median(array,0,array_size - 1);

  end = clock();
  time_of_exec = (double)(end - start) / CLOCKS_PER_SEC;
  save_file(array, array_size, order, "saida","Quick-sort-median/");
  save_file_time_exec(time_of_exec, array_size, order,"Quick-sort-median/");
}

void measure_quick_sort_avarage(int *array, int array_size, char order) {
  clock_t start, end;
  double time_of_exec;
  start = clock();
  save_file(array, array_size, order, "entrada","Quick-sort-avarage/");

  quick_sort_avarage_pivot(array,0,array_size - 1);

  end = clock();
  time_of_exec = (double)(end - start) / CLOCKS_PER_SEC;
  save_file(array, array_size, order, "saida","Quick-sort-avarage/");
  save_file_time_exec(time_of_exec, array_size, order,"Quick-sort-avarage/");
}

int main () {
  create_folders_setup(INSERTION);
  create_folders_setup(BUBBLE);
  create_folders_setup(SELECTION);
  create_folders_setup(SHELL);
  create_folders_setup(MERGE);
  create_folders_setup(QUICK_UM);
  create_folders_setup(QUICK_DOIS);
  create_folders_setup(QUICK_TRES);
  create_folders_setup(QUICK_QUATRO);

  int *array, array_size, test_option;
  char order;

  int algorithm = get_algorithm_option();
  if(algorithm == 0) {
    return 0;
  }
  array_size = get_array_size();
  if(array_size == 0) {
    printf("Saindo...");
    return 0;
  }
  system("cls || clear");
  order = get_order();
  if(order == 's') {
    printf("Saindo...");

  }
  array = aloc_array(array_size);
  if(array == NULL) {
    printf("Erro ao alocar array...");
    return 0;
  }
  switch (order) {
    case 'c':
      populate_array_ASC_order(array, array_size);
      break;
    case 'd':
      populate_array_DESC_order(array, array_size);
      break;
    case 'r':
      populate_array_RAND_order(array, array_size);
      break;
    default:
      break;
  }

   switch (algorithm) {
    case 1:
      measure_insertion_sort(array,array_size,order);
      break;
    case 2:
      measure_bubble_sort(array,array_size,order);
      break;
    case 3:
      measure_selection_sort(array,array_size,order);
      break;
    case 4:
      measure_shell_sort(array,array_size,order);
      break;
    case 5: 
      measure_merge_sort(array,array_size,order);
      break;
    case 6: 
      measure_quick_sort_one(array,array_size,order);
      break;
    case 7: 
      measure_quick_sort_random(array,array_size,order);
      break;
    case 8: 
      measure_quick_sort_median(array,array_size,order);
      break;
    case 9: 
      measure_quick_sort_avarage(array,array_size,order);
      break;
    default:
      break;
  }

  free(array);
  return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "algoritmos.c"


int* aloc_array(int size) {
  return (int*) malloc(size * sizeof(int));
}

int generate_random_number() {
  time_t t;
  srand((unsigned) time(&t));
  return rand();
}

void populate_array_DESC_order(int *array,int array_size) {
  int seed = generate_random_number();
  int i;
  int quant_elements = array_size - 1 ; 
  for(i =0 ; i <= quant_elements; i++) {
    array[i] = seed + (quant_elements - i);
  }
}


void build_min_heap(int *array, int size) {
  int i;
  for (i = size / 2 - 1; i >= 0; i--) {
    heapfy(arr, size, i);
  } 
  printArray(array,size);
}

void heapfy(int *array, int size, int index) {

  int smallest = i;

  int left = 2 * i + 1;

  int right = 2 * i + 2;
  
  if (left < size && arr[left] < arr[smallest]) {
    smallest = left;
  }

  if (right < size && arr[right] < arr[smallest]) {
    smallest = right;
  }

  if (smallest != i) {
    swap(&arr[i], &arr[smallest]);
    heapfy(arr, N, smallest);
  }
}

void printArray(int *array, int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
  int *p = aloc_array(10);
  populate_array_DESC_order(p,10);
  printArray(p,10);

  return 0;
}
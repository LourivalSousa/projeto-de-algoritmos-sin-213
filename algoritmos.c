#include <stdio.h>
#include <stdlib.h>

/*Arquivo contendo todos os algoritmos de ordenação*/

int generate_random_with_range(int range) {
  time_t t;
  srand(rand() * time(0));
  return rand() % range;
}

void insertionSort(int *array, int array_size) { 
    int i, key, j; 
    for (i = 1; i < array_size; i++) { 
        key = array[i]; 
        j = i - 1; 

        while (j >= 0 && array[j] > key)
        { 
            array[j + 1] = array[j]; 
            j = j - 1; 
        } 
        array[j + 1] = key; 
    } 
} 


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selection_sort(int *array, int size)
{
    int i, j, min_idx;
 
    for (i = 0; i < size-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < size; j++)
        if (array[j] < array[min_idx])
            min_idx = j;

        if(min_idx!=i)
            swap(&array[min_idx], &array[i]);
    }
}

int shellSort(int *array, int size)
{
    int gap;
    for (gap = size/2; gap > 0; gap /= 2)
    {
		int i;
        for (i = gap; i < size; i += 1)
        {

            int temp = array[i];

            int j;            
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                array[j] = array[j - gap];

            array[j] = temp;
        }
    }
    return 0;
}

void bubbleSort(int *array, int size) {

  int i, j;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
      }
    }
  }

}

int* alloc_array(int size) {
  return (int*) malloc(size * sizeof(int));
}


void merge(int *array, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = alloc_array(n1);
    if(L == NULL) {
        printf("Erro ao alocar memoria...\n");
        exit(1);
    }

    int *R = alloc_array(n2);
    if(R == NULL) {
        printf("Erro ao alocar memoria...\n");
        exit(1);
    }
    
    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];
 
   
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int *array, int l, int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;
 
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
 
        merge(array, l, m, r);
    }
}

int partition_version_one(int *array, int low, int high)
{
    int first_element = array[0];
    int pivot = first_element; 
    int i = (low- 1); 
  	int j;
    for (j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quick_sort_version_one(int *array, int low, int high)
{
    if (low < high) {
        int pi = partition_version_one(array, low, high);
        quick_sort_version_one(array, low, pi - 1);
        quick_sort_version_one(array, pi + 1, high);
    }
}


int partition_median(int *array, int low, int high)
{   
    int size = sizeof(array) / sizeof(int);
    printf("%d\n",size);
    int median = ((size/2) + (size/2-1)) / 2 ;
    int temp = array[median];
    array[median] = array[low];
    array[low] = temp;

    int pivot = array[low];
    int i = low - 1, j = high + 1;
  
    while (1) {
  
        do {
            i++;
        } while (array[i] < pivot);
  
        do {
            j--;
        } while (array[j] > pivot);
  
        if (i >= j)
            return j;
  
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void quick_sort_median(int *array, int low, int high)
{
    if (low < high) {
        int pi = partition_median(array, low, high);
        quick_sort_median(array, low, pi - 1);
        quick_sort_median(array, pi + 1, high);
    }
}

int partition_avarage_pivot(int *array, int low, int high)
{
    int avarage = (low + high)/2; 
    int temp = array[avarage];
    array[avarage] = array[low];
    array[low] = temp;

    int pivot = array[low];
    int i = low - 1, j = high + 1;
  
    while (1) {
  
        do {
            i++;
        } while (array[i] < pivot);
  
        do {
            j--;
        } while (array[j] > pivot);
  
        if (i >= j)
            return j;
  
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void quick_sort_avarage_pivot(int *array, int low, int high)
{
    if (low < high) {
        int pi = partition_avarage_pivot(array, low, high);
        quick_sort_avarage_pivot(array, low, pi - 1);
        quick_sort_avarage_pivot(array, pi + 1, high);
    }
}

int partition_random_pivot(int *array, int low, int high)
{
    int random = generate_random_with_range(high);
    int temp = array[random];
    array[random] = array[low];
    array[low] = temp;

    int pivot = array[low];
    int i = low - 1, j = high + 1;
  
    while (1) {
  
        do {
            i++;
        } while (array[i] < pivot);
  
        do {
            j--;
        } while (array[j] > pivot);
  
        if (i >= j)
            return j;
  
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void quick_sort_random_pivot(int *array, int low, int high)
{
    if (low < high) {
        int pi = partition_random_pivot(array, low, high);
        quick_sort_random_pivot(array, low, pi - 1);
        quick_sort_random_pivot(array, pi + 1, high);
    }
}

// algoritmos do heap sort

void printArray(int *arr, int N) {
  if(N > 1000) {
    char op;
    printf("Este vetor possui muitos elementos para imprimir na tela!!!\nDeseja exibir mesmo assim? (s/n) \n");
    op = getchar();
    if(op == 'n' || op == 'N') return;
  }
  for (int i = 0; i < N; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void heapfy(int *array, int size, int i) {

  int smallest = i;

  int left = 2 * i + 1;

  int right = 2 * i + 2;
  
  if (left < size && array[left] < array[smallest]) {
    smallest = left;
  }

  if (right < size && array[right] < array[smallest]) {
    smallest = right;
  }

  if (smallest != i) {
    swap(&array[i], &array[smallest]);
    heapfy(array, size, smallest);
  }
}

void build_min_heap(int *array, int size) {
  int i;
  for (i = size / 2 - 1; i >= 0; i--) {
    heapfy(array, size, i);
  } 
}

void heap_sort(int *array, int size) {
  
  build_min_heap(array,size);
  printf("Chamando a build min heap: \n");
  printArray(array,size);

  int i;
  for (i = size - 1; i >= 0; i--) {
    swap(&array[0], &array[i]);
    heapfy(array, i, 0);
  }
}





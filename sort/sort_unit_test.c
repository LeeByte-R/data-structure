#include "sort.h"
#include <stdio.h>
#include <assert.h>

bool fi(int a, int b){  // sort compare function, non-decreasing order
  return a < b;
}

bool fd(int a, int b){  // sort compare function, decreasing order
  return a > b;
}

void quick_sort_test(){
  int arr[7] = {4, 3, 5, 2, 1, 0, 6};
  
  quick_sort(arr, 7, fi);  // after sorting [4, 3, 5, 2, 1, 0, 6] -> [0, 1, 2, 3, 4, 5, 6]

  for(int i=0; i<=6; i++)
    assert(arr[i] == i);
  
  // just sorting decreasing order in range arr[2]~arr[5]
  // after sorting [0, 1, 2, 3, 4, 5, 6] -> [0, 1, 5, 4, 3, 2, 6]
  quick_sort(&arr[2], 4, fd);

  assert(arr[0] == 0);
  assert(arr[1] == 1);
  assert(arr[2] == 5);
  assert(arr[3] == 4);
  assert(arr[4] == 3);
  assert(arr[5] == 2);
  assert(arr[6] == 6);

  printf("quick sort pass\r\n");
}

void heap_sort_test(){
  int arr[7] = {4, 3, 5, 2, 1, 0, 6};
  
  heap_sort(arr, 7, fi);  // after sorting [4, 3, 5, 2, 1, 0, 6] -> [0, 1, 2, 3, 4, 5, 6]

  for(int i=0; i<=6; i++)
    assert(arr[i] == i);
  
  // just sorting decreasing order in range arr[2]~arr[5]
  // after sorting [0, 1, 2, 3, 4, 5, 6] -> [0, 1, 5, 4, 3, 2, 6]
  heap_sort(&arr[2], 4, fd);

  assert(arr[0] == 0);
  assert(arr[1] == 1);
  assert(arr[2] == 5);
  assert(arr[3] == 4);
  assert(arr[4] == 3);
  assert(arr[5] == 2);
  assert(arr[6] == 6);

  printf("heap sort pass\r\n");
}

void merge_sort_test(){
  int arr[7] = {4, 3, 5, 2, 1, 0, 6};
  
  merge_sort(arr, 7, fi);  // after sorting [4, 3, 5, 2, 1, 0, 6] -> [0, 1, 2, 3, 4, 5, 6]

  for(int i=0; i<=6; i++)
    assert(arr[i] == i);
  
  // just sorting decreasing order in range arr[2]~arr[5]
  // after sorting [0, 1, 2, 3, 4, 5, 6] -> [0, 1, 5, 4, 3, 2, 6]
  merge_sort(&arr[2], 4, fd);

  assert(arr[0] == 0);
  assert(arr[1] == 1);
  assert(arr[2] == 5);
  assert(arr[3] == 4);
  assert(arr[4] == 3);
  assert(arr[5] == 2);
  assert(arr[6] == 6);

  printf("merge sort pass\r\n");
}

int main(){
  quick_sort_test();
  heap_sort_test();
  merge_sort_test();

  return 0;
}


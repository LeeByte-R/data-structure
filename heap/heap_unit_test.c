#include "heap.h"
#include <stdio.h>
#include <assert.h>

bool f(int a, int b){  // min heap compare function
  return a < b;
}

void heap_init_test(){
  heap test_h;

  heap_init(&test_h, f);
  assert(test_h.size == 0);
  assert(test_h.cmp == f);

  printf("heap_init pass\r\n");
}

void heap_push_test(){
  heap test_h;

  heap_init(&test_h, f);

  heap_push(&test_h, 2);
  heap_push(&test_h, 1);
  heap_push(&test_h, 3);
  heap_push(&test_h, 0);
  assert(heap_push(&test_h, 99999) == false);

  assert(test_h.nodes[0] == 0);
  assert(test_h.size == 4);

  printf("heap_push pass\r\n");
}

void heap_pop_test(){
  heap test_h;

  heap_init(&test_h, f);

  heap_push(&test_h, 2);
  heap_push(&test_h, 1);
  heap_push(&test_h, 3);
  heap_push(&test_h, 0);

  assert(heap_pop(&test_h) == 0);
  assert(heap_pop(&test_h) == 1);
  assert(heap_pop(&test_h) == 2);
  assert(heap_pop(&test_h) == 3);
  assert(test_h.size == 0);

  printf("heap_pop pass\r\n");
}

void heap_peek_test(){
  heap test_h;

  heap_init(&test_h, f);

  heap_push(&test_h, 2);
  heap_push(&test_h, 1);
  heap_push(&test_h, 3);
  heap_push(&test_h, 0);

  assert(heap_peek(&test_h) == 0);
  assert(test_h.nodes[0] == 0);
  assert(test_h.size == 4);

  printf("heap_peek pass\r\n");
}

void heap_size_test(){
  heap test_h;

  heap_init(&test_h, f);

  heap_push(&test_h, 2);
  heap_push(&test_h, 1);
  heap_push(&test_h, 3);
  heap_push(&test_h, 0);

  assert(heap_size(&test_h) == 4);

  printf("heap_size pass\r\n");
}

void heap_is_empty_test(){
  heap test_h;

  heap_init(&test_h, f);

  heap_push(&test_h, 0);
  assert(heap_is_empty(&test_h) == false);
  heap_pop(&test_h);
  assert(heap_is_empty(&test_h) == true);

  printf("heap_is_empty pass\r\n");
}

void heap_is_full_test(){
  heap test_h;

  heap_init(&test_h, f);

  heap_push(&test_h, 2);
  heap_push(&test_h, 1);
  heap_push(&test_h, 3);
  heap_push(&test_h, 0);

  assert(heap_is_full(&test_h) == true);
  heap_pop(&test_h);
  assert(heap_is_full(&test_h) == false);

  printf("heap_is_full pass\r\n");
}

void heap_clear_test(){
  heap test_h;

  heap_init(&test_h, f);

  heap_push(&test_h, 2);
  heap_push(&test_h, 1);
  heap_push(&test_h, 3);
  heap_push(&test_h, 0);

  assert(heap_is_empty(&test_h) == false);
  heap_clear(&test_h);
  assert(heap_is_empty(&test_h) == true);

  printf("heap_clear pass\r\n");
}

void array2heap_test(){
  heap test_h;
  int arr[4] = {3, 2, 1, 0};

  heap_init(&test_h, f);

  assert(array2heap(&test_h, arr, 4) == true);
  assert(heap_pop(&test_h) == 0);
  assert(heap_pop(&test_h) == 1);
  assert(heap_pop(&test_h) == 2);
  assert(heap_pop(&test_h) == 3);

  printf("array2heap pass\r\n");
}

int main(){
  heap_init_test();
  heap_push_test();
  heap_pop_test();
  heap_peek_test();
  heap_size_test();
  heap_is_empty_test();
  heap_is_full_test();
  heap_clear_test();
  array2heap_test();

  return 0;
}


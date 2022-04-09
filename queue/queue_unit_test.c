#include "queue.h"
#include <stdio.h>
#include <assert.h>

void queue_init_test(){
  queue test_q;

  queue_init(&test_q);
  assert(test_q.front == 0);
  assert(test_q.back == 0);

  printf("queue_init pass\r\n");
}

void queue_push_test(){
  queue test_q;

  queue_init(&test_q);

  queue_push(&test_q, 0);
  queue_push(&test_q, 1);
  queue_push(&test_q, 2);

  assert(queue_push(&test_q, 4) == false);
  
  assert(test_q.elements[1] == 0);
  assert(test_q.elements[2] == 1);
  assert(test_q.elements[3] == 2);

  printf("queue_push pass\r\n");
}

void queue_pop_test(){
  queue test_q;

  queue_init(&test_q);

  queue_push(&test_q, 0);
  queue_push(&test_q, 1);
  queue_push(&test_q, 2);

  assert(queue_pop(&test_q) == 0);
  assert(queue_pop(&test_q) == 1);
  assert(queue_pop(&test_q) == 2);

  printf("queue_pop pass\r\n");
}

void queue_peek_test(){
  queue test_q;

  queue_init(&test_q);

  queue_push(&test_q, 0);
  queue_push(&test_q, 1);
  queue_push(&test_q, 2);

  assert(queue_peek(&test_q) == 0);
  assert(test_q.elements[1] == 0);

  printf("queue_peek pass\r\n");
}

void queue_size_test(){
  queue test_q;

  queue_init(&test_q);

  queue_push(&test_q, 0);
  queue_push(&test_q, 1);
  queue_push(&test_q, 2);

  assert(queue_size(&test_q) == 3);

  printf("queue_size pass\r\n");
}

void queue_is_empty_test(){
  queue test_q;

  queue_init(&test_q);

  queue_push(&test_q, 0);
  assert(queue_is_empty(&test_q) == false);
  queue_pop(&test_q);
  assert(queue_is_empty(&test_q) == true);

  printf("queue_is_empty pass\r\n");
}
void queue_is_full_test(){
  queue test_q;

  queue_init(&test_q);

  queue_push(&test_q, 0);
  queue_push(&test_q, 1);
  queue_push(&test_q, 2);

  assert(queue_is_full(&test_q) == true);
  queue_pop(&test_q);
  assert(queue_is_full(&test_q) == false);

  printf("queue_is_full pass\r\n");
}

int main(){
  queue_init_test();
  queue_push_test();
  queue_pop_test();
  queue_peek_test();
  queue_size_test();
  queue_is_empty_test();
  queue_is_full_test();
  return 0;
}
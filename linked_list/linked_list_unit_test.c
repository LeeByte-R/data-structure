#include "linked_list.h"
#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <stdbool.h>

void list_init_test(){
  list test_l;
  list_init(&test_l);

  assert(test_l.head != NULL);
  assert(test_l.tail != NULL);
  assert(test_l.len == 0);

  printf("list_init pass\r\n");
}

void list_push_back_test(){
  list test_l;
  list_init(&test_l);
  
  // construct linked list 0 -> 1 -> 2
  list_push_back(&test_l, 0);
  assert(test_l.head->next->data == 0);
  list_push_back(&test_l, 1);
  assert(test_l.head->next->next->data == 1);
  list_push_back(&test_l, 2);
  assert(test_l.head->next->next->next->data == 2);
  
  printf("list_push_back pass\r\n");
}

void list_push_test(){ 
  list test_l;
  list_init(&test_l);
  
  // construct linked list 0 -> 1 -> 2
  list_push_back(&test_l, 0);
  list_push_back(&test_l, 1);
  list_push_back(&test_l, 2);

  // insert end 0 -> 1 -> 2 -> 333
  list_push(&test_l, 333, 3);
  assert(test_l.head->next->next->next->next->data == 333);

  // insert middle 0 -> 222 -> 1 -> 2 -> 333
  list_push(&test_l, 222, 1);
  assert(test_l.head->next->next->data == 222);

  // insert front 111 -> 0 -> 222 -> 1 -> 2 -> 333
  list_push(&test_l, 111, 0);
  assert(test_l.head->next->data == 111);
 
  assert(list_push(&test_l, 999, 100) == false);  // insert wrong index(over length of linked list)
  assert(list_push(&test_l, 999, -100) == false);  // insert wrong index(under length of linked list)

  printf("list_push pass\r\n");
}

void list_pop_back_test(){
  list test_l;
  list_init(&test_l);
  
  // construct linked list 0 -> 1 -> 2
  list_push_back(&test_l, 0);
  list_push_back(&test_l, 1);
  list_push_back(&test_l, 2);

  assert(list_pop_back(&test_l) == 2);
  assert(test_l.head->next->next->next == NULL);
  assert(list_pop_back(&test_l) == 1);
  assert(test_l.head->next->next == NULL);
  assert(list_pop_back(&test_l) == 0);
  assert(test_l.head->next == NULL);
  assert(test_l.len == 0);
  
  printf("list_pop_back pass\r\n");
}

void list_pop_test(){
  list test_l;
  list_init(&test_l);
  
  // construct linked list 0 -> 1 -> 2
  list_push_back(&test_l, 0);
  list_push_back(&test_l, 1);
  list_push_back(&test_l, 2);

  // remove middle 0 -> 2
  assert(list_pop(&test_l, 1) == 1);
  assert(test_l.head->next->next->data == 2);

  // remove front 2
  assert(list_pop(&test_l, 0) == 0);
  assert(test_l.head->next->data == 2);

  // remove end
  assert(list_pop(&test_l, 0) == 2);

  assert(test_l.len == 0);
  assert(test_l.head == test_l.tail);
  
  printf("list_pop pass\r\n");
}

void list_peek_back_test(){
  list test_l;
  list_init(&test_l);
  
  // construct linked list 0 -> 1 -> 2
  list_push_back(&test_l, 0);
  list_push_back(&test_l, 1);
  list_push_back(&test_l, 2);

  assert(list_peek_back(&test_l) == 2);
  
  printf("list_peek_back pass\r\n");
}

void list_peek_test(){
  list test_l;
  list_init(&test_l);
  
  // construct linked list 0 -> 1 -> 2
  list_push_back(&test_l, 0);
  list_push_back(&test_l, 1);
  list_push_back(&test_l, 2);

  assert(list_peek(&test_l, 1) == 1);
  assert(list_peek(&test_l, 0) == 0);
  assert(list_peek(&test_l, 2) == 2);

  printf("list_peek pass\r\n");
}

void list_size_test(){
  list test_l;
  list_init(&test_l);
  
  assert(list_size(&test_l) == 0);

  // construct linked list 0 -> 1 -> 2
  list_push_back(&test_l, 0);
  list_push_back(&test_l, 1);
  list_push_back(&test_l, 2);

  assert(list_size(&test_l) == 3);

  printf("list_size pass\r\n");
}

void list_is_empty_test(){
  list test_l;
  list_init(&test_l);
  
  // construct linked list 0 -> 1 -> 2
  list_push_back(&test_l, 0);
  list_push_back(&test_l, 1);
  list_push_back(&test_l, 2);

  assert(list_is_empty(&test_l) == false);

  // clear linked list
  list_pop_back(&test_l);
  list_pop_back(&test_l);
  list_pop_back(&test_l);

  assert(list_is_empty(&test_l) == true);

  printf("list_is_empty pass\r\n");
}

void list_clear_test(){
  list test_l;
  list_init(&test_l);
  
  // construct linked list 0 -> 1 -> 2
  list_push_back(&test_l, 0);
  list_push_back(&test_l, 1);
  list_push_back(&test_l, 2);

  list_clear(&test_l);
  assert(test_l.head->next == NULL);
  assert(test_l.head == test_l.tail);
  assert(test_l.len == 0);

  printf("list_clear pass\r\n");
}

void list_reverse_test(){
  list test_l;
  list_init(&test_l);
  
  // construct linked list 0 -> 1 -> 2
  list_push_back(&test_l, 0);
  list_push_back(&test_l, 1);
  list_push_back(&test_l, 2);

  list_reverse(&test_l);

  assert(test_l.head->next->data == 2);
  assert(test_l.head->next->next->data == 1);
  assert(test_l.head->next->next->next->data == 0);
  assert(test_l.tail->data == 0);
  assert(test_l.head->next->data == 2);

  printf("list_reverse pass\r\n");
}

int main(){
  list_init_test();
  list_push_back_test();
  list_push_test();
  list_pop_back_test();
  list_pop_test();
  list_peek_back_test();
  list_peek_test();
  list_size_test();
  list_is_empty_test();
  list_clear_test();
  list_reverse_test();
  
  return 0;
}


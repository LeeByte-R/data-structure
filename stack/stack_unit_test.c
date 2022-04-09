#include "stack.h"
#include <stdio.h>
#include <assert.h>

void stack_init_test(){
  stack test_st;

  stack_init(&test_st);
  assert(test_st.top == -1);

  printf("stack_init pass\r\n");
}

void stack_push_test(){
  stack test_st;

  stack_init(&test_st);

  stack_push(&test_st, 0);
  stack_push(&test_st, 1);
  stack_push(&test_st, 2);
  assert(stack_push(&test_st, 3) == false);

  assert(test_st.elements[0] == 0);
  assert(test_st.elements[1] == 1);
  assert(test_st.elements[2] == 2);
  assert(test_st.top == 2);

  printf("stack_push pass\r\n");
}

void stack_pop_test(){
  stack test_st;

  stack_init(&test_st);

  stack_push(&test_st, 0);
  stack_push(&test_st, 1);
  stack_push(&test_st, 2);

  assert(stack_pop(&test_st) == 2);
  assert(stack_pop(&test_st) == 1);
  assert(stack_pop(&test_st) == 0);
  assert(test_st.top == -1);

  printf("stack_pop pass\r\n");
}

void stack_peek_test(){
  stack test_st;

  stack_init(&test_st);

  stack_push(&test_st, 0);
  stack_push(&test_st, 1);
  stack_push(&test_st, 2);

  assert(stack_peek(&test_st) == 2);
  assert(test_st.elements[2] == 2);

  printf("stack_peek pass\r\n");
}

void stack_size_test(){
  stack test_st;

  stack_init(&test_st);

  stack_push(&test_st, 0);
  stack_push(&test_st, 1);
  stack_push(&test_st, 2);

  assert(stack_size(&test_st) == 3);

  printf("stack_size pass\r\n");
}

void stack_is_empty_test(){
  stack test_st;

  stack_init(&test_st);

  stack_push(&test_st, 0);
  assert(stack_is_empty(&test_st) == false);
  stack_pop(&test_st);
  assert(stack_is_empty(&test_st) == true);

  printf("stack_is_empty pass\r\n");
}

void stack_is_full_test(){
  stack test_st;

  stack_init(&test_st);

  stack_push(&test_st, 0);
  stack_push(&test_st, 1);
  stack_push(&test_st, 2);

  assert(stack_is_full(&test_st) == true);
  stack_pop(&test_st);
  assert(stack_is_full(&test_st) == false);

  printf("stack_is_full pass\r\n");
}

int main(){
  stack_init_test();
  stack_push_test();
  stack_pop_test();
  stack_peek_test();
  stack_size_test();
  stack_is_empty_test();
  stack_is_full_test();

  return 0;
}


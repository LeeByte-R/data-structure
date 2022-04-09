#include "stack.h"

void stack_init(stack *st){
  st->top = -1;
}

bool stack_push(stack *st, data_type d){
  if(st->top+1 == STACK_CAPACITY)  // stack is full
    return false;

  st->top++;
  st->elements[st->top] = d;

  return true;
}

data_type stack_pop(stack *st){
  if(st->top == -1)  // stack is empty
    return st->elements[0];
  
  st->top--;

  return st->elements[st->top+1];
}

int stack_size(stack *st){
  return st->top + 1;
}

bool stack_is_empty(stack *st){
  return (st->top + 1 == 0);
}

bool stack_is_full(stack *st){
  return (st->top + 1 == STACK_CAPACITY);
}
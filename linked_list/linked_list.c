#include "linked_list.h"
#include <stdlib.h>
#include <stddef.h>

void list_init(list *l){
  list_node *tmp = (list_node *)malloc(sizeof(list_node));
  tmp->next = NULL;

  l->head = tmp;
  l->tail = tmp;
  l->len = 0;
}

bool list_push_back(list *l, data_type d){
  list_node *tmp = (list_node *)malloc(sizeof(list_node));
  if(tmp == NULL)  // error in allocating memory
    return false;
  
  tmp->data = d;
  tmp->next = NULL;

  l->tail->next = tmp;
  l->tail = tmp;
  l->len++;

  return true;
}

bool list_push(list *l, data_type d, int location){
  if(location > l->len || location < 0)  // invalid index, valid index should be 0 ~ len-1
    return false;

  list_node *tmp = (list_node *)malloc(sizeof(list_node));
  if(tmp == NULL)  // error in allocating memory
    return false;

  tmp->data = d;
  tmp->next = NULL;
  
  list_node *p = l->head;
  for(int i=0; i<location; i++){  // find previous location index pointer
    p = p->next;
  }

  list_node *tmp_p = p->next;
  p->next = tmp;
  tmp->next = tmp_p;
  l->len++;

  return true;
}

data_type list_pop_back(list *l){
  if(l->len == 0)
    return l->head->data;

  list_node *p = l->head;
  while(p->next != l->tail){  // find node before tail node
    p = p->next;
  }

  data_type tmp_d = p->next->data;

  free(p->next);
  p->next = NULL;
  l->tail = p;
  l->len--;

  return tmp_d;
}

data_type list_pop(list *l, int location){
  if(location > l->len || location < 0)  // invalid index, valid index should be 0 ~ len-1
    return l->head->data;

  list_node *p = l->head;
  for(int i=0; i<location; i++){  // find previous location index pointer
    p = p->next;
  }

  if(p->next == l->tail)
    l->tail = p;
  
  list_node *tmp_p = p->next->next;
  data_type tmp_d = p->next->data;

  free(p->next);
  p->next = tmp_p;
  l->len--;

  return tmp_d;
}

data_type list_peek_back(list *l){
  return l->tail->data;
}

data_type list_peek(list *l, int location){
  if(location > l->len || location < 0)  // invalid index, valid index should be 0 ~ len-1
    return l->head->data;

  list_node *p = l->head;
  for(int i=0; i<=location; i++){  // find location index pointer
    p = p->next;
  }

  return p->data;
}

int list_size(list *l){
  return l->len;
}

bool list_is_empty(list *l){
  return (l->len == 0);
}

void list_clear(list *l){
  list_node *p = l->head->next, *tmp_p;

  while(p != NULL){
    tmp_p = p;
    p = p->next;
    free(tmp_p);
  }

  l->head->next = NULL;
  l->tail = l->head;
  l->len = 0;
}

void list_reverse(list *l){
  list_node *prev_p = NULL;
  list_node *p = l->head->next;
  list_node *next_p = NULL;
  
  while(p != NULL) {
    next_p = p->next;
    p->next = prev_p;
    prev_p = p;
    p = next_p;
  }

  l->tail = l->head->next;
  l->head->next = prev_p;
}

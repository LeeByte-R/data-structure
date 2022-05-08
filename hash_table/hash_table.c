#include "hash_table.h"
#include <stdlib.h>
#include <stdio.h>

#define A 0.618033
#define FLOOR(x) ((double)(int)x)

int hash_f(int k)  // hash function multiplication method
{
  double tmp = k * A;
  return (int)(TABLE_CAPACITY * (tmp - FLOOR(tmp)));
}


void hash_init(hash *ha, int (*f)(key_type))
{
  for(int i=0; i<TABLE_CAPACITY; i++)
    ha->table[i].next = NULL;
  ha->prehash_f = f;
  ha->size = 0;
}

bool hash_insert(hash *ha, key_type k, data_type d)
{
  int index = hash_f(ha->prehash_f(k));

  list_node *cur = ha->table[index].next;

  while(cur){
      if(cur->key == k){  // key is already in table
          cur->data = d;
          return true;
      }
      cur = cur->next;
  }

  list_node *node = (list_node *)malloc(sizeof(list_node));
  if(node == NULL)  // error in allocating memory
    return false;
  
  node->key = k;
  node->data = d;

  list_node *tmp = ha->table[index].next;
  ha->table[index].next = node;
  node->next = tmp;
  ha->size++;

  return true;
}

bool hash_find(hash *ha, key_type k, data_type *d)
{
  int index = hash_f(ha->prehash_f(k));

  list_node *cur = ha->table[index].next;

  while(cur){
      if(cur->key == k){  // find key
          *d = cur->data;
          return true;
      }
      cur = cur->next;
  }

  return false;
}

void hash_delete(hash *ha, key_type k)
{
  int index = hash_f(ha->prehash_f(k));

  list_node *cur = &ha->table[index];

  while(cur->next){
      if(cur->next->key == k){  // find key
        list_node *tmp = cur->next;
        cur->next = cur->next->next;
        free(tmp);
        ha->size--;
        return ;
      }
      cur = cur->next;
  }
}

int hash_size(hash *ha)
{
  return ha->size;
}

bool hash_is_empty(hash *ha)
{
  return (ha->size == 0);
}

void hash_clear(hash *ha)
{
  list_node *cur, *tmp;

  for(int i=0; i<TABLE_CAPACITY; i++){
    cur = ha->table[i].next;

    while(cur){
      tmp = cur;
      cur = cur->next;
      
      free(tmp);
    }
  }

  ha->size = 0;
}

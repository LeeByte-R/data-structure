#include "hash_table.h"
#include <stdio.h>
#include <assert.h>

int prehash(char *s){
  int a = 0;

  while(*s){
    a = a * 10 + *s;
    s++;
  }
}

void hash_init_test(){
  hash test_ha;

  hash_init(&test_ha, prehash);
  assert(test_ha.size == 0);
  assert(test_ha.prehash_f == prehash);

  hash_clear(&test_ha);
  printf("hash_init pass\r\n");
}

void hash_insert_test(){
  hash test_ha;

  hash_init(&test_ha, prehash);

  assert(hash_insert(&test_ha, "ABC", 0) == true);
  assert(hash_insert(&test_ha, "V", 1) == true);
  assert(hash_insert(&test_ha, "VCBNA", 2) == true);

  hash_clear(&test_ha);
  printf("hash_insert pass\r\n");
}

void hash_find_test(){
  hash test_ha;
  int x;

  hash_init(&test_ha, prehash);

  hash_insert(&test_ha, "ABC", 0);
  hash_insert(&test_ha, "V", 1);
  hash_insert(&test_ha, "VCBNA", 2);

  assert(hash_find(&test_ha, "V", &x) == true);
  assert(x == 1);
  assert(hash_find(&test_ha, "ABC", &x) == true);
  assert(x == 0);
  assert(hash_find(&test_ha, "VCBNA", &x) == true);
  assert(x == 2);
  assert(hash_find(&test_ha, "VXX", &x) == false);

  hash_clear(&test_ha);
  printf("hash_find pass\r\n");
}

void hash_delete_test(){
  hash test_ha;
  int x;

  hash_init(&test_ha, prehash);

  hash_insert(&test_ha, "ABC", 0);
  hash_insert(&test_ha, "V", 1);
  hash_insert(&test_ha, "VCBNA", 2);

  assert(hash_find(&test_ha, "V", &x) == true);
  assert(x == 1);
  
  hash_delete(&test_ha, "V");
  assert(hash_find(&test_ha, "V", &x) == false);

  hash_clear(&test_ha);
  printf("hash_delete pass\r\n");
}

void hash_size_test(){
  hash test_ha;

  hash_init(&test_ha, prehash);

  hash_insert(&test_ha, "ABC", 0);
  hash_insert(&test_ha, "V", 1);
  hash_insert(&test_ha, "VCBNA", 2);

  assert(hash_size(&test_ha) == 3);

  hash_clear(&test_ha);
  printf("hash_size pass\r\n");
}

void hash_is_empty_test(){
  hash test_ha;

  hash_init(&test_ha, prehash);
  assert(hash_is_empty(&test_ha) == true);
  hash_insert(&test_ha, "ABC", 0);

  assert(hash_is_empty(&test_ha) == false);

  hash_clear(&test_ha);
  printf("hash_is_empty pass\r\n");
}

void hash_clear_test(){
  hash test_ha;

  hash_init(&test_ha, prehash);

  hash_insert(&test_ha, "ABC", 0);
  hash_insert(&test_ha, "V", 1);
  hash_insert(&test_ha, "VCBNA", 2);

  assert(hash_is_empty(&test_ha) == false);
  hash_clear(&test_ha);
  assert(hash_is_empty(&test_ha) == true);

  printf("hash_clear pass\r\n");
}

int main(){
  hash_init_test();
  hash_insert_test();
  hash_find_test();
  hash_delete_test();
  hash_size_test();
  hash_is_empty_test();
  hash_clear_test();

  return 0;
}
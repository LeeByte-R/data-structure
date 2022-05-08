/**
* @file
* @author Lee Byte
* @version 1.0
*
* @section LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* @section DESCRIPTION
* c hash table
* 
* @mainpage 
* c hash table implement, hash function multiplication method, list chaining \n
* change typedef [***] key_type;  for apply different key type \n
* change typedef [***] data_type; for apply different data type \n
* beacause hash table nodes are dynamic allocated, if no longer use hash table, remember call hash_clear to free all nodes
*/


#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <stdbool.h>

#define TABLE_CAPACITY 8  ///< hash table bucket size

typedef char* key_type;   ///< change typedef [***] key_type;  for apply different key type, in this example data type is string
typedef int   data_type;  ///< change typedef [***] data_type; for apply different data type, in this example data type is int

/**
 * linked list node to chain
*/
struct list_node{
  key_type  key;
  data_type data;
  struct list_node *next;   ///< point to next node
};
typedef struct list_node list_node;

/**
 * hash table structure
*/
typedef struct{
  list_node table[TABLE_CAPACITY];  ///< table
  int (*prehash_f)(key_type);       ///< prehash function pointer, convert key to int
  int size;                         ///< how much (key, value) in table 
} hash;

/**
 * construct hash_table
 *
 * @param ha hash_table pointer to initialize
 * @param f  prehash function pointer
 */
void hash_init(hash *ha, int (*f)(key_type));

/**
 * insert data to hash_table, if key is already in hash_table then replace original data
 *
 * @param ha hash_table pointer to insert
 * @param k  key to insert
 * @param d  data to insert
 * @return   whether hash_insert success
 */
bool hash_insert(hash *ha, key_type k, data_type d);

/**
 * if key is in hash_table, return true, value of key. if key is not in hash_table, return false \n
 *
 * @param ha hash_table pointer to find
 * @param k  key to find
 * @param d  value of key, if hash is empty, return value will be undetermined.
 * @return   whether key in hash_table
 */
bool hash_find(hash *ha, key_type k, data_type *d);

/**
 * remove key from hash_table, if key is not in table then this function do nothing.
 *
 * @param ha hash_table pointer to delete
 * @param k  key to delete
 */
void hash_delete(hash *ha, key_type k);

/**
 * get size of hash_table
 *
 * @param ha hash_table pointer
 * @return   size of hash_table
 */
int hash_size(hash *ha);

/**
 * check if hash_table is empty
 *
 * @param ha hash_table pointer
 * @return   whether hash_table is empty
 */
bool hash_is_empty(hash *ha);

/**
 * clear hash_table
 * beacause hash table nodes are dynamic allocated, if no longer use hash table, remember call hash_clear to free all nodes
 *
 * @param ha hash_table pointer to clear
 */
void hash_clear(hash *ha);

#endif // HASH_TABLE_H

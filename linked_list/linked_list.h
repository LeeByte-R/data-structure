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
* c linked list
* 
* @mainpage 
* c linked list implement \n
* change typedef [***] data_type; for apply different data type \n
* beacause linked list nodes are dynamic allocated, if no longer use linked list, remember call list_clear to free all nodes
*/


#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>

typedef int data_type;  ///< change typedef [***] data_type; for apply different data type, in this example data type of node is int

/**
 * linked list node to chain
*/
struct list_node{
  data_type data;  ///< node data
  struct list_node *next;      ///< point to next node
};
typedef struct list_node list_node;

/**
 * linked list structure
*/
typedef struct{
  list_node *head;  ///< point head node, next pointer of head is first node of linked list
  list_node *tail;  ///< point end node of linked list
  int len;     ///< length of linked list
} list;

/**
 * construct linked list
 *
 * @param l linked list pointer to initialize
 */
void list_init(list *l);

/**
 * insert data at end of linked list
 *
 * @param l linked list pointer to insert
 * @param d data to insert
 * @return whether list_push_back success
 */
bool list_push_back(list *l, data_type d);

/**
 * insert data at given index of linked list
 *
 * @param l linked list pointer to insert
 * @param d data to insert
 * @param location where to insert
 * @return whether list_push success
 */
bool list_push(list *l, data_type d, int location);

/**
 * remove node at end of linked list \n
 * if list is empty, return value will be undetermined. check list is not empty before use.
 *
 * @param l linked list pointer to pop
 * @return data of end node of linked list
 */
data_type list_pop_back(list *l);

/**
 * remove node at given index of linked list \n
 * if location index is invaild(valid index should be 0 ~ len-1), return value will be undetermined. check location before use.
 *
 * @param l linked list pointer to pop
 * @param location where to pop
 * @return data of given index node of linked list
 */
data_type list_pop(list *l, int location);

/**
 * get data of node at end of linked list \n
 * if list is empty, return value will be undetermined. check list is not empty before use.
 *
 * @param l linked list pointer to peek
 * @return data of end node of linked list
 */
data_type list_peek_back(list *l);

/**
 * get data of node at given index of linked list \n
 * if location index is invaild(valid index should be 0 ~ len-1), return value will be undetermined. check location before use.
 *
 * @param l linked list pointer to peek
 * @param location where to peek
 * @return data of given index node of linked list
 */
data_type list_peek(list *l, int location);

/**
 * get size of linked list
 *
 * @param l linked list pointer
 * @return size of linked list
 */
int list_size(list *l);

/**
 * check if linked list is empty
 *
 * @param l linked list pointer
 * @return whether linked list is empty
 */
bool list_is_empty(list *l);

/**
 * clear linked list
 * beacause linked list nodes are dynamic allocated, if no longer use linked list, remember call list_clear to free all nodes
 *
 * @param l linked list pointer to clear
 */
void list_clear(list *l);

/**
 * reverse linked list
 *
 * @param l linked list pointer to reverse
 */
void list_reverse(list *l);

#endif // LINKED_LIST_H

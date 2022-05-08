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
* c heap
* 
* @mainpage 
* c heap implement \n
* change typedef [***] data_type; for apply different data type \n
* HEAP_CAPACITY is max size of heap
*/

#ifndef HEAP_H
#define HEAP_H
#include <stdbool.h>

#define HEAP_CAPACITY 4  ///< max size of heap

typedef int data_type;  ///< change typedef [***] data_type; for apply different data type, in this example data type of heap is int

/**
 * heap structure
*/
typedef struct{
  data_type nodes[HEAP_CAPACITY];     ///< elements of heap
  bool (*cmp)(data_type, data_type);  ///< compare function for heap, ex: bool cmp(parent, child) return parent < child; mean min meap
  int size;                           ///< current size of heap
} heap;

/**
 * construct heap pass compare function to heap structure
 *
 * @param h   heap pointer to initialize
 * @param cmp heap value compare function
 */
void heap_init(heap *h, bool (*cmp)(data_type, data_type));

/**
 * push data to heap
 *
 * @param h heap pointer to push
 * @param d data to push
 * @return whether heap_push success
 */
bool heap_push(heap *h, data_type d);

/**
 * pop data at root node of heap \n
 * if heap is empty, return value will be undetermined. check size of heap before use.
 *
 * @param h heap pointer to pop
 * @return data of root node of heap
 */
data_type heap_pop(heap *h);

/**
 * peek data at root node of heap \n
 * if heap is empty, return value will be undetermined. check heap is not empty before use.
 *
 * @param h heap pointer to peek
 * @return data of root node of heap
 */
data_type heap_peek(heap *h);

/**
 * get size of heap
 *
 * @param h heap pointer
 * @return size of heap
 */
int heap_size(heap *h);

/**
 * check if heap is empty
 *
 * @param h heap pointer
 * @return whether heap is empty
 */
bool heap_is_empty(heap *h);

/**
 * check if heap is full
 *
 * @param h heap pointer
 * @return whether heap is full
 */
bool heap_is_full(heap *h);

/**
 * clear heap content
 *
 * @param h heap pointer
 */
void heap_clear(heap *h);

/**
 * convert array to heap
 *
 * @param h heap pointer
 * @param arr array pointer
 * @param n len of array
 * @return whether convert successfully
 */
bool array2heap(heap *h, data_type *arr, int n);

#endif  // HEAP_H

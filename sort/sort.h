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
* c sort algorithm
* 
* @mainpage 
* c sort algorithm implement \n
* change typedef [***] data_type; for apply different data type
*/


#ifndef SORT_H
#define SORT_H
#include <stdbool.h>

typedef int data_type;  ///< change typedef [***] data_type; for apply different data type


/**
 * quick sort
 * time  complexity -> best case: O(N*logN) average case: O(N*logN) worst case: O(N^2)
 * space complexity -> best case: O(logN)   average case: O(logN)   worst case: O(N)   <- stack size from recursive call
 *
 * worst case:
 * 1) Array is already sorted in the same order. 
 * 2) Array is already sorted in reverse order. 
 * 3) All elements are the same
 *
 * @param arr   array to sort
 * @param n     size of array
 * @param cmp   compare function pointer
 */
void quick_sort(data_type *arr, int n, bool (*cmp)(data_type a, data_type b));

/**
 * heap sort
 * time  complexity -> best case: O(N*logN) average case: O(N*logN) worst case: O(N*logN)
 * space complexity -> best case: O(1)      average case: O(1)      worst case: O(1)
 *
 * @param arr   array to sort
 * @param n     size of array
 * @param cmp   compare function pointer
 */
void heap_sort(data_type *arr, int n, bool (*cmp)(data_type a, data_type b));

/**
 * merge sort
 * time  complexity -> best case: O(N*logN) average case: O(N*logN) worst case: O(N*logN)
 * space complexity -> best case: O(N)      average case: O(N)      worst case: O(N)
 *
 * @param arr   array to sort
 * @param n     size of array
 * @param cmp   compare function pointer
 */
void merge_sort(data_type *arr, int n, bool (*cmp)(data_type a, data_type b));


#endif // SORT_H

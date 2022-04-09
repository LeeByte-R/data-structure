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
* c stack
* 
* @mainpage 
* c stack implement \n
* change typedef [***] data_type; for apply different data type
* change STACK_CAPACITY for give max size of stack
*/


#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

#define STACK_CAPACITY 3  ///< max size of stack

typedef int data_type;  ///< change typedef [***] data_type; for apply different data type, in this example data type of stack is int

/**
 * stack structure
*/
typedef struct{
  data_type elements[STACK_CAPACITY];
  int top;  ///< top element of stack
} stack;

/**
 * construct stack
 *
 * @param st stack pointer to initialize
 */
void stack_init(stack *st);

/**
 * push data at top of stack
 *
 * @param st stack pointer to push
 * @param d data to push
 * @return whether stack_push success
 */
bool stack_push(stack *st, data_type d);

/**
 * pop data at top of stack \n
 * if stack is empty, return value will be undetermined. check size of stack before use.
 *
 * @param st stack pointer to pop
 * @return data of top of stack
 */
data_type stack_pop(stack *st);

/**
 * peek data at top of stack \n
 * if stack is empty, return value will be undetermined. check stack is not empty before use.
 *
 * @param st stack pointer to peek
 * @return data of end node of stack
 */
data_type stack_peek(stack *st);

/**
 * get size of stack
 *
 * @param st stack pointer
 * @return size of stack
 */
int stack_size(stack *st);

/**
 * check if stack is empty
 *
 * @param st stack pointer
 * @return whether stack is empty
 */
bool stack_is_empty(stack *st);

/**
 * check if stack is full
 *
 * @param st stack pointer
 * @return whether stack is full
 */
bool stack_is_full(stack *st);

#endif // STACK_H

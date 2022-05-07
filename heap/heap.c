#include "heap.h"

// to get index of parent of node at index i
#define PARENT(i) ((i - 1) / 2)

// to get index of left child of node at index i
#define LEFT(i)   (2 * i + 1)

// to get index of right child of node at index i
#define RIGHT(i)  (2 * i + 2)

// to swap values of two nodes
#define SWAP(x, y) \
  data_type tmp = x; \
  x = y; \
  y = tmp;

void heapify(heap *h, int i)
{
  int l, r, super;

  while(true){
    // find min or max in (node i, left child of node i, right child of node i)
    int l = LEFT(i);
    int r = RIGHT(i);
    int super = i;
    if(l < h->size && h->cmp(h->nodes[l], h->nodes[i]))
      super = l;
    if(r < h->size && h->cmp(h->nodes[r], h->nodes[super]))
      super = r;

    if(super == i)
      break;
    
    SWAP(h->nodes[i], h->nodes[super]);
    i = super;
  }

}

void heap_init(heap *h, bool (*cmp)(data_type, data_type))
{
  h->cmp = cmp;
  h->size = 0;
}

bool heap_push(heap *h, data_type d)
{
  if(h->size == HEAP_CAPACITY)  // heap is full
    return false;

  int i = h->size;
  h->nodes[i] = d;
  h->size++;

  // fix the min heap property if it is violated
  while(i != 0 && !h->cmp(h->nodes[PARENT(i)], h->nodes[i])){
    SWAP(h->nodes[i], h->nodes[PARENT(i)]);
    i = PARENT(i);
  }

  return true;
}

data_type heap_pop(heap *h)
{
  if(h->size <= 0)
    return -1;
  if(h->size == 1){
    h->size--;
    return h->nodes[0];
  }
  
  // store the minimum value, and remove it from heap
  data_type root = h->nodes[0];
  h->nodes[0] = h->nodes[h->size-1];  // take last node to root
  h->size--;
  heapify(h, 0);
  
  return root;
}

data_type heap_peek(heap *h)
{
  if(h->size == 0)  // heap is empty
    return -1;
  else
    return h->nodes[0];  // return root node value
}

int heap_size(heap *h)
{
  return h->size;
}

bool heap_is_empty(heap *h)
{
  return (h->size == 0);
}

bool heap_is_full(heap *h)
{
  return (h->size == HEAP_CAPACITY);
}

void heap_clear(heap *h)
{
  h->size = 0;
}

bool array2heap(heap *h, data_type *arr, int n)
{
  if(n > HEAP_CAPACITY)
    return false;
  else
    h->size = n;

  for(int i=0; i<n; i++)
    h->nodes[i] = arr[i];
  
  n = PARENT(n-1);  // get last non-leaf node index

  for(int i=n; i>=0; i--)  // heapify last non-leaf node to root node sequentially
    heapify(h, i);

  return true;
}


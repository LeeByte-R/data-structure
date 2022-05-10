#include "sort.h"

#define MIN(xx, yy) ( ( (xx) < (yy) )? (xx) : (yy) )

// to get index of parent of node at index i
#define PARENT(i) ((i - 1) / 2)

// to get index of left child of node at index i
#define LEFT(i)   (2 * i + 1)

// to get index of right child of node at index i
#define RIGHT(i)  (2 * i + 2)

#define SWAP(x, y){ \
  data_type tmp = x; \
  x = y; \
  y = tmp; \
}

int partition(data_type *arr, int front, int end, bool (*cmp)(data_type a, data_type b))
{
  data_type pivot = arr[end];
  int i = front - 1;

  for(int j = front; j < end; j++){
    if(cmp(arr[j], pivot)){
      i++;
      SWAP(arr[i], arr[j]);
    }
  }

  i++;
  SWAP(arr[i], arr[end]);
 
  return i;
}

void quick(data_type *arr, int front, int end, bool (*cmp)(data_type a, data_type b))
{
  if(front < end){
    int pivot = partition(arr, front, end, cmp);
    quick(arr, front, pivot - 1, cmp);
    quick(arr, pivot + 1, end, cmp);
  }
}

void quick_sort(data_type *arr, int n, bool (*cmp)(data_type a, data_type b))
{
  quick(arr, 0, n-1, cmp);
}

void heapify(data_type *arr, int i, int n, bool (*cmp)(data_type a, data_type b))
{
  int l, r, super;

  while(true){
    int l = LEFT(i);
    int r = RIGHT(i);
    int super = i;
    if(l < n && !cmp(arr[l], arr[super]))
      super = l;
    if(r < n && !cmp(arr[r], arr[super]))
      super = r;

    if(super == i)
      break;
    
    SWAP(arr[i], arr[super]);
    i = super;
  }
}

void heap_sort(data_type *arr, int n, bool (*cmp)(data_type a, data_type b))
{
  int i = PARENT(n-1);  // get last non-leaf node index

  for(; i>=0; i--)  // heapify last non-leaf node to root node sequentially
    heapify(arr, i, n, cmp);

  for(i=n-1; i>0; i--){
    SWAP(arr[0], arr[i]);
    heapify(arr, 0, i, cmp);
  }
}

void merge(int arr[], int l, int m, int r, bool (*cmp)(data_type a, data_type b))
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 =  r - m;
 
  /* create temp arrays */
  int L[n1], R[n2];
 
  /* Copy data to temp arrays L[] and R[] */
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1+ j];
 
  /* Merge the temp arrays back into arr[l..r]*/
  i = 0;
  j = 0;
  k = l;
  while(i < n1 && j < n2){
    if(cmp(L[i], R[j])){
      arr[k] = L[i];
      i++;
    }else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }
 
  /* Copy the remaining elements of L[], if there are any */
  while(i < n1){
    arr[k] = L[i];
    i++;
    k++;
  }
 
  /* Copy the remaining elements of R[], if there are any */
  while(j < n2){
    arr[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(int *arr, int n, bool (*cmp)(data_type a, data_type b))
{
  int curr_size;  // For current size of subarrays to be merged curr_size varies from 1 to n/2
  int left_start; // For picking starting index of left subarray to be merged
 
  // Merge subarrays in bottom up manner.  First merge subarrays of
  // size 1 to create sorted subarrays of size 2, then merge subarrays
  // of size 2 to create sorted subarrays of size 4, and so on.
  for(curr_size=1; curr_size<=n-1; curr_size = 2*curr_size){
    // Pick starting point of different subarrays of current size
    for(left_start=0; left_start<n-1; left_start += 2*curr_size){
      // Find ending point of left subarray. mid+1 is starting point of right
      int mid = MIN(left_start + curr_size - 1, n-1);
 
      int right_end = MIN(left_start + 2*curr_size - 1, n-1);
 
      // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
      merge(arr, left_start, mid, right_end, cmp);
    }
  }
}

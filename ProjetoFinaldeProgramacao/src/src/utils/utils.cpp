#include "../../include/utils.h"

/**
 * A iterative binary search function.
 *
 * This binary search a task.
 *
 * @param values Container whose values are summed.
 * @return location of x in given array arr[l..r] if present, otherwise -1
 */
int binarySearch(Task** arr, int l, int r, int x) {
    while (l <= r) {

        int m = l + (r-l)/2;
                
        // Check if x is present at mid
        if ((int)arr[m]->getTaskID() == x){
            return m;    
        }
        
        // If x greater, ignore left half
        if ((int)arr[m]->getTaskID() < x){
            l = m + 1;    
        } else { // If x is smaller, ignore right half
            r = m - 1;    
        }
        
    }
    // if we reach here, then element was not present
    return -1;
}

/**
 * A function to sort an array using shellSort.
 *
 * This sum is the arithmetic sum, not some other kind of sum that only
 * mathematicians have heard of.
 *
 * @param arr, n Container whose values are summed.
 * @return void
 */
void shellSort(Task** arr, int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            Task* temp = arr[i];
  
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;

            for (j = i; j >= gap && arr[j - gap]->getTaskPriority() > temp->getTaskPriority(); j -= gap)
                arr[j] = arr[j - gap];
              
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}

/**
 * A function to sort an array using insertionSort.
 *
 * This sum is the arithmetic sum, not some other kind of sum that only
 * mathematicians have heard of.
 *
 * @param values Container whose values are summed.
 * @return sum of `values`, or 0.0 if `values` is empty.
 */
void insertionSort(Task** arr, int n)
{
    int i, j;
    Task* temp;

    for (i = 1; i < n; i++) {
        temp = arr[i];
        
        j = i - 1;
 
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j]->getTaskPriority() > temp->getTaskPriority()) {
            
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = temp; 
    }
}
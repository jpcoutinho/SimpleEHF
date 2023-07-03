#include <stdio.h>
#include "./task.h"

/**
 * A iterative binary search function.
 *
 * This binary search a task.
 *
 * @param values Container whose values are summed.
 * @return location of x in given array arr[l..r] if present, otherwise -1
 */
int binarySearch(Task** arr, int l, int r, int x);

/**
 * A function to sort tasks by priority using shellSort.
 *
 * This sorting method works better for bigger arrays.
 *
 * @param arr an array of Task pointers.
 * @param n 
 * @return void
 */
void shellSort(Task** arr, int n);

/**
 * A function to sort tasks by priority using insertionSort.
 *
 * This sorting method works better for smaller arrays.
 *
 *
 * @param arr an array of Task pointers.
 * @param n 
 * @return void
 */
void insertionSort(Task** arr, int n);
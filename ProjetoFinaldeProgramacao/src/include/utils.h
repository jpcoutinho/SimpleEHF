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
 * A function to sort an array using shellSort.
 *
 * This sum is the arithmetic sum, not some other kind of sum that only
 * mathematicians have heard of.
 *
 * @param arr, n Container whose values are summed.
 * @return void
 */
void shellSort(Task** arr, int n);

/**
 * A function to sort an array using insertionSort.
 *
 * This sum is the arithmetic sum, not some other kind of sum that only
 * mathematicians have heard of.
 *
 * @param values Container whose values are summed.
 * @return sum of `values`, or 0.0 if `values` is empty.
 */
void insertionSort(Task** arr, int n);
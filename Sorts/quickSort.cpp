#include "sort.h"

// This function partitions the vector for the quickSort function.
// Since the vector is passed by reference, the original vector will be
// affected and sorted correctly.

void partition(vector<int> &v, int left, int right){

    // Ints i and j are used to increment through the elements of the vector.
    int i = left;
    int j = right;
    // Int tmp is used as a temporary placeholder.
    int tmp;
    // All elements will be moved to the left or right of the pivot.
    int pivot = v[abs(left + (right - left) / 2)];

    // Partitioning step
    // While loops increment through vector, comparing the elements with the pivot
    while (i <= j){
        while (v[i] < pivot){
            ++i;
        }
        while (v[j] > pivot){
            --j;
        }
        // If the i(left) is less than or equal to the j(right), i becomes j and vice versa.
        if (i <= j){
            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            ++i;
            --j;
        }
    }
    // Recursion steps
    if (left < j){
        partition(v, left, j);
    }

    if (i < right){
        partition(v, i, right);
    }
}

// Sets a left and a right, then calls the partition function using those variables.
void quickSort(vector<int> &v)
{
    // The left and right set the boundaries for the vector to be partitioned
    int left = 0;
    // The right side is the last element, which is the size minus 1.
    int right = v.size() - 1;
    partition(v, left, right);
}
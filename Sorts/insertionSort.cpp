#include "sort.h"

// insertionSort() sorts the vector of ints using the Insertion sort algorithm (outlined by the textbook).
void insertionSort(vector <int> &v)
{
    int sizeOfList = v.size() - 1;

    // This algorithm copies the next value to be inserted into newElement.
    for (int i = 1; i <= sizeOfList; ++i) {
        int newElement = v[i];
        int location = i - 1;
        // The while loop makes space for this new element by moving all elements that
        // are larger one position down in the array.
        while ((location >= 0) && (v[location] > newElement)) {
            v[location + 1] = v[location];
            location = location - 1;
        }
        // The new element is then put in the proper place in the vector.
        v[location + 1] = newElement;
    }
}
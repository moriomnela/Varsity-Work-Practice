/*Task 7                Remove all occurrences of a particular element from an array

Consider an array named source. Write a method/function named removeAll( source,
size, element) that removes all the occurrences of the given element in the source
array. You must execute the method by passing an array, its size and the element to be
removed. After calling the method, print the array to show whether all the occurrences
of the element have been removed properly.*/

#include <stdio.h>
void removeAll(int source[], int size, int element) {
    int j = 0; // Index for placing the non-element values


    // Iterate through the array
    for (int i = 0; i < size; i++) {
        if (source[i] != element) {

            source[j++] = source[i];
        }
    }

    while (j < size) {
        source[j++] = 0;
    }
}


int main() {
    int source[] = {10, 2, 30, 2, 50, 2, 2, 0, 0};
    int size = 9;
    int element = 2;


    removeAll(source, size, element);


    for (int i = 0; i < size; i++) {
        printf("%d ", source[i]);
    }
    printf("\n");


    return 0;
}

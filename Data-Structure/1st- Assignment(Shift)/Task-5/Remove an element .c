/*  Remove an element from an array

Consider an array named source. Write a method/function named remove( source,
size, idx) that removes the element in index idx of the source array. You must execute
the method by passing an array, its size and the idx( that is the index of the element to
be removed). After calling the method, print the array to show whether the element of
that particular index has been removed properly.*/

#include <stdio.h>


void removeElement(int source[], int size, int idx) {

    if (idx < 0 || idx >= size) {
        printf("Index out of bounds\n");
        return;
    }


    for (int i = idx; i < size - 1; i++) {
        source[i] = source[i + 1];
    }


    source[size - 1] = 0;
}


int main() {
    int source[] = {10, 20, 30, 40, 50, 0, 0};
    int size = 7;
    int idx = 2;


    removeElement(source, size, idx);



    for (int i = 0; i < size; i++) {
        printf("%d ", source[i]);
    }
    printf("\n");


    return 0;
}



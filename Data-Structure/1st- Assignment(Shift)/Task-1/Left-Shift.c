/*Task1                                  Shift Left k Cells

Consider an array named source. Write a method/function named shiftLeft( source, k)
that shifts all the elements of the source array to the left by 'k' positions. You must
execute the method by passing an array and number of cells to be shifted. After calling
the method, print the array to show whether the elements have been shifted properly.*/

#include <stdio.h>
#include <stdlib.h>


void shiftLeft(int source[], int size, int k) {
    // Allocate memory for a temporary array
    int *temp = (int *)malloc(size * sizeof(int));


    // Initialize the temporary array with 0
    for (int i = 0; i < size; i++) {
        temp[i] = 0;
    }


    // Shift elements from source to temp array
    for (int i = 0; i < size; i++) {
        if (i >= k) {
            temp[i - k] = source[i];
        }
    }


    // Copy the temporary array back to the source array
    for (int i = 0; i < size; i++) {
        source[i] = temp[i];
    }


}


int main() {
    int source[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(source) / sizeof(source[0]);
    int k = 3;


    shiftLeft(source, size, k);


    // Print the array after shifting
    for (int i = 0; i < size; i++) {
        printf("%d ", source[i]);
    }
    printf("\n");


    return 0;
}



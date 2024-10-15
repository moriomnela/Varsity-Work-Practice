/*Task3                                          Rotate Left k cells

Consider an array named source. Write a method/function named rotateLeft( source, k)
that rotates all the elements of the source array to the left by 'k' positions. You must
execute the method by passing an array and number of cells to be shifted. After calling
the method, print the array to show whether the elements have been shifted properly.*/

#include <stdio.h>
#include <stdlib.h>


void rotateLeft(int source[], int size, int k) {


    int *temp = (int *)malloc(size * sizeof(int));

    // Rotate elements from source to temp array
    for (int i = 0; i < size; i++) {
        temp[i] = source[(i + k) % size];
    }




    for (int i = 0; i < size; i++) {
        source[i] = temp[i];
    }


}


int main() {
    int source[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(source) / sizeof(source[0]);
    int k = 3;


    rotateLeft(source, size, k);


    // Print the array after rotating
    for (int i = 0; i < size; i++) {
        printf("%d ", source[i]);
    }
    printf("\n");


    return 0;
}



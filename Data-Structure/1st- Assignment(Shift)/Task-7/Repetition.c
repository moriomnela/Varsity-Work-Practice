/*Task 8                      Repetition

Write a method that takes in an array as a parameter and counts the repetition of each
element. That is, if an element has appeared in the array more than once, then its
‘repetition’ is its number of occurrences. The method returns true if there are at least
two elements with the same number of ‘repetition’. Otherwise, return false.*/

#include <stdio.h>
#include <stdbool.h>


#define MAX_ELEMENTS 100


void countFrequencies(int source[], int size, int frequencies[], int *uniqueCount) {
    int count[MAX_ELEMENTS] = {0};
    *uniqueCount = 0;


    for (int i = 0; i < size; i++) {
        if (count[source[i]] == 0) {
            (*uniqueCount)++;
        }
        count[source[i]]++;
    }


    int index = 0;
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (count[i] > 0) {
            frequencies[index++] = count[i];
        }
    }
}


// Function to check if there are at least two elements with the same frequency
bool hasSameRepetition(int frequencies[], int uniqueCount) {
    for (int i = 0; i < uniqueCount; i++) {
        for (int j = i + 1; j < uniqueCount; j++) {
            if (frequencies[i] == frequencies[j]) {
                return true;
            }
        }
    }
    return false;
}


bool checkRepetition(int source[], int size) {
    int frequencies[MAX_ELEMENTS] = {0};
    int uniqueCount = 0;


    countFrequencies(source, size, frequencies, &uniqueCount);
    return hasSameRepetition(frequencies, uniqueCount);
}


int main() {
    int source1[] = {4, 5, 6, 6, 4, 3, 6, 4};
    int size1 = sizeof(source1) / sizeof(source1[0]);


    if (checkRepetition(source1, size1)) {
        printf("True\n");
    } else {
        printf("False\n");
    }


    int source2[] = {3, 4, 6, 3, 4, 7, 4, 6, 8, 6, 6};
    int size2 = sizeof(source2) / sizeof(source2[0]);


    if (checkRepetition(source2, size2)) {
        printf("True\n");
    } else {
        printf("False\n");
    }


    return 0;
}

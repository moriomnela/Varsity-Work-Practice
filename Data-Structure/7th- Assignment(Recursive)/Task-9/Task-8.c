/*9. Find the Maximum Element in an Array:
Question: Write a recursive function to find the maximum element in an array of
integers.*/

#include <stdio.h>
int findMax(int arr[], int n) {
    if (n == 1)
        return arr[0];

    int max = findMax(arr, n - 1);  // Recursive case
    if (arr[n - 1] > max)
        return arr[n - 1];
    else
        return max;
}

int main() {
    int arr[] = {2, 9, 4, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum element = %d\n", findMax(arr, n));

    return 0;
}

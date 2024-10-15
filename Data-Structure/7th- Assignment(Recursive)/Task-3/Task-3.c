/*3. Sum of Digits:
Question: Write a recursive function to find the sum of the digits of a given
positive integer n. The function should return the sum of all individual digits of the
number.*/

#include <stdio.h>
int sum_of_digits(int n) {
    if (n == 0)
        return 0;
    else
        return (n % 10) + sum_of_digits(n / 10); // Recursive case
}

int main() {
    int n = 1234;
    printf("Sum of digits = %d\n", sum_of_digits(n));

    return 0;
}


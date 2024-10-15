/*1. Factorial Calculation:
Question: Write a recursive function to compute the factorial of a given integer n.
Factorial of n is the product of all positive integers less than or equal to n
(denoted as n!).*/

#include <stdio.h>
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1); // Recursive  case
}
int main() {
    int n = 5;
    printf("%d! = %d\n", n, factorial(n));

    n = 0;
    printf("%d! = %d\n", n, factorial(n));

    return 0;
}

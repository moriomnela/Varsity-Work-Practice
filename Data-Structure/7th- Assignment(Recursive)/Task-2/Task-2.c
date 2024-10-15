/*2. Fibonacci Series:
Question: Write a recursive function to compute the nth Fibonacci number. The
Fibonacci sequence is defined as follows: F(0) = 0, F(1) = 1, and for n >=
2, F(n) = F(n-1) + F(n-2).*/

#include <stdio.h>
int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main() {
    int n = 6;
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));

    return 0;
}

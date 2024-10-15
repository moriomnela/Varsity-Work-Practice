/*6. Greatest Common Divisor (GCD):
○ Question: Write a recursive function to compute the greatest common divisor
(GCD) of two integers a and b using the Euclidean algorithm.*/

#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b); // Recursive case
}

int main() {
    int a = 48, b = 18;
    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));

    return 0;
}


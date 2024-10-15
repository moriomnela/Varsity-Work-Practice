/*4. Power Calculation:
Question: Write a recursive function to calculate the power of a number x raised
to y (x^y). You must not use loops or the pow function.*/

#include <stdio.h>
int power(int x, int y) {
    if (y == 0)
        return 1;
    else
        return x * power(x, y - 1); // Recursive case
}

int main() {
    int x = 2, y = 3;
    printf("%d^%d = %d\n", x, y, power(x, y));

    x = 5; y = 0;
    printf("%d^%d = %d\n", x, y, power(x, y));

    return 0;
}

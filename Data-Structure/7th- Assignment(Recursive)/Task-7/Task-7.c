/*7. Decimal to Binary Conversion:
Question: Write a recursive function to convert a decimal number into its binary
representation.*/

#include <stdio.h>

void decimalToBinary(int n) {
    if (n > 1)
        decimalToBinary(n / 2);  // Recursive case
    printf("%d", n % 2);
}
int main() {
    int n = 10;
    printf("Binary of %d = ", n);
    decimalToBinary(n);
    printf("\n");

    return 0;
}

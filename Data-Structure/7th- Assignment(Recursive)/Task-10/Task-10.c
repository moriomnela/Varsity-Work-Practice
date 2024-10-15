/*10. Towers of Hanoi (BONUS):
○ Question: Write a recursive function to solve the Towers of Hanoi problem. The
task is to move n disks from the source rod to the destination rod, using an
auxiliary rod, while following the rules of the puzzle.*/


#include <stdio.h>

void towersOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;  // Base case
    }
    towersOfHanoi(n - 1, from_rod, aux_rod, to_rod);  // Move n-1 disks from from_rod to aux_rod
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towersOfHanoi(n - 1, aux_rod, to_rod, from_rod);  // Move n-1 disks from aux_rod to to_rod
}
int main() {
    int n = 3;
    towersOfHanoi(n, 'A', 'C', 'B');
    return 0;
}

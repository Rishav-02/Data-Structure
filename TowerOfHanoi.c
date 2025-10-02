#include <stdio.h>

int moveCount = 0;

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        moveCount++;
        printf("Move %d: Disk 1 from %c to %c\n", moveCount, source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the nth disk from source to destination
    moveCount++;
    printf("Move %d: Disk %d from %c to %c\n", moveCount, n, source, destination);

    // Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("\nSequence of moves to solve Tower of Hanoi with %d disks: \n", n);
    towerOfHanoi(n, 'A', 'B', 'C');// A, B and C are names of rods
    printf("\nTotal moves required: %d", moveCount);

    return 0;
}
// The above code sorts an array of strings in a case-insensitive manner using the Bubble Sort algorithm.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 5
#define SIZE 100

// Use strcasecmp for case-insensitive comparison
// If not available, define your own version below
int case_insensitive_cmp(const char *a, const char *b) {
    while (*a && *b) {
        char ca = tolower((unsigned char)*a);
        char cb = tolower((unsigned char)*b);
        if (ca != cb)
            return ca - cb;
        a++;
        b++;
    }
    return tolower((unsigned char)*a) - tolower((unsigned char)*b);
}

void Bubble_sort(char arr[][SIZE], int n);

int main()
{
    char A[MAX][SIZE];
    int i;

    printf("Enter %d strings:\n", MAX);
    for(i = 0; i < MAX; i++)
    {
        scanf("%s", A[i]);  // For single-word strings
    }

    Bubble_sort(A, MAX);

    printf("\nStrings after sorting :\n");
    for(i = 0; i < MAX; i++)
    {
        printf("%s\n", A[i]);
    }

    return 0;
}

void Bubble_sort(char A[][SIZE], int N)
{
    int i, j;
    char temp[SIZE];

    for(i = 0; i < N - 1; i++)
    {
        for(j = 0; j < N - 1 - i; j++)
        {
            if(case_insensitive_cmp(A[j], A[j+1]) > 0)
            {
                // Swap strings
                strcpy(temp, A[j]);
                strcpy(A[j], A[j+1]);
                strcpy(A[j+1], temp);
            }
        }
    }
}

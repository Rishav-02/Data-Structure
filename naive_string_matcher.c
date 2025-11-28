#include <stdio.h>
#include <string.h>

// In this algorithm, we search for occurrences of a pattern in a given text
void naiveStringMatcher(char text[], char pattern[]) {
    int N = strlen(text);
    int M = strlen(pattern);
    int i, j;

    // Iterate through all possible starting positions (shifts) in the text
    for (i = 0; i <= N - M; i++) {

        // Compare the current window of text with the pattern
        for (j = 0; j < M; j++) {
            if (text[i + j] != pattern[j]) {
                break; // Mismatch found, move to the next shift
            }
        }

        // If the inner loop completed, it means the pattern was found
        if (j == M) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[100];
    char pattern[100];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin); // Use fgets for safer input
    text[strcspn(text, "\n")] = 0; // Remove trailing newline character and strcspn() is used to get the length of initial segment which consists of characters not in the specified set

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin); // Use fgets for safer input
    pattern[strcspn(pattern, "\n")] = 0; // Remove trailing newline character

    naiveStringMatcher(text, pattern);

    return 0;
}
#include <stdio.h>                                                                                                                                                  
#include <string.h>

#define d 256        // number of characters in input alphabet
#define q 101        // a prime number for hashing we use 101 because it's a small prime

void rabinKarp(char text[], char pattern[]) {
    int N = strlen(text);
    int M = strlen(pattern);
    int i, j, p = 0, t = 0, h = 1;      // hash value for text(t) and pattern(p)
   
    // The value of h = pow(d, M-1) % q
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values for pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text
    for (i = 0; i <= N - M; i++) {

        // If hash values match, then check characters one by one
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate hash for next window
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + 1*M]) % q;

            // If t becomes negative, convert it to positive
            if (t < 0)
                t = t + q;
        }
    }
}

int main() {
    char text[100], pattern[100];

    printf("Enter text: ");
    // gets(text);
    fgets(text, sizeof(text), stdin);// Use fgets for safer input
    text[strcspn(text, "\n")] = 0; // Remove trailing newline character

    printf("Enter pattern: ");
    // gets(pattern);
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = 0;

    rabinKarp(text, pattern);

    return 0;
}
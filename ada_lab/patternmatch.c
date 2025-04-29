#include <stdio.h>
#include <string.h>

void patternMatching(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    // Check each possible position in the text
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    patternMatching(text, pattern);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>

int main() {
    int c;
    int lines = 0, words = 0, characters = 0;
    bool inWord = false;

    printf("Enter text (Press Ctrl+D(EOF) to end input):\n");

    while ((c = getchar()) != EOF) {
        characters++;

        if (c == '\n') {
            lines++;
        }

        if (c == ' ' || c == '\t' || c == '\n') {
            if (inWord) {
                inWord = false;
                words++;
            }
        } else {
            inWord = true;
        }
    }

    // If the last character is part of a word
    if (inWord) {
        words++;
    }

    printf("\nStatistics:\n");
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);

    return 0;
}

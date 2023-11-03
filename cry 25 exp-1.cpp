#include <stdio.h>
#include <string.h>

void caesarCipher(char text[], int shift) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
        }
    }
    printf("Shift %d: %s\n", shift, text);
}

int main() {
    char input[100];
    printf("Enter a message to encrypt: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    int shift;
    for (shift = 1; shift <= 25; shift++) {
        char encrypted[100];
        strcpy(encrypted, input);
        caesarCipher(encrypted, shift);
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to perform polyalphabetic substitution cipher
void polyalphabeticCipher(char *text, char *key) {
    int keyLength = strlen(key);
    int textLength = strlen(text);

    for (int i = 0; i < textLength; i++) {
        if (isalpha(text[i])) {
            char baseChar = islower(text[i]) ? 'a' : 'A';
            int shift = tolower(key[i % keyLength]) - 'a';

            // Apply the shift to the current character
            text[i] = baseChar + (text[i] - baseChar + shift) % 26;
        }
    }
}

int main() {
    char plaintext[1000];
    char key[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove the newline character from input

    printf("Enter the key: ");
    scanf("%s", key);

    polyalphabeticCipher(plaintext, key);

    printf("Ciphertext: %s\n", plaintext);

    return 0;
} 

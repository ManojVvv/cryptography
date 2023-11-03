#include <stdio.h>
#include <string.h>
#include <ctype.h>
char monoalphabetic_encrypt(char plain_char, char key[]) {
    if (isalpha(plain_char)) {
        int index = toupper(plain_char) - 'A';  
        return isupper(plain_char) ? toupper(key[index]) : tolower(key[index]);
    }
    return plain_char; 
}
int main() {
    char plain_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
    char cipher_alphabet[] = "QWERTYUIOPASDFGHJKLZXCVBNM";  
    char plaintext[100];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    int len = strlen(plaintext);
    printf("Encrypted Text: ");
    for (int i = 0; i < len; i++) {
        char encrypted_char = monoalphabetic_encrypt(plaintext[i], cipher_alphabet);
        putchar(encrypted_char);
    }
    printf("\n");
    return 0;
}

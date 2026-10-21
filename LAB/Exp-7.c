#include <stdio.h>
#include <string.h>

int main(void) {
    char cipher[2000];
    char key[100];

    printf("Enter ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);

    printf("Enter 26-letter decryption key:\n");
    scanf("%26s", key);

    if (strlen(key) != 26) {
        printf("Invalid key. Enter exactly 26 letters.\n");
        return 1;
    }

    printf("Decrypted text:\n");

    for (int i = 0; cipher[i] != '\0'; i++) {
        char c = cipher[i];

        if (c >= 'A' && c <= 'Z')
            putchar(key[c - 'A']);
        else if (c >= 'a' && c <= 'z')
            putchar(key[c - 'a'] + ('a' - 'A'));
        else
            putchar(c);
    }

    return 0;
}

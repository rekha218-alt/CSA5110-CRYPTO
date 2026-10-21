#include <stdio.h>
#include <ctype.h>

int main(void) {
    char text[1000];
    char key[] = "CIPHERABDFGJKLMNOQSTUVWXYZ";

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Encrypted text: ");

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            putchar(key[text[i] - 'A']);
        else if (text[i] >= 'a' && text[i] <= 'z')
            putchar(tolower(key[text[i] - 'a']));
        else
            putchar(text[i]);
    }

    return 0;
}

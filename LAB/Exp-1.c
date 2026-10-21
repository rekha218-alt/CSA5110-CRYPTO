#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char text[1000];
    int key, i;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key (1-25): ");
    scanf("%d", &key);

    key = ((key % 26) + 26) % 26;

    for (i = 0; text[i] != '\0'; i++) {
        if (isupper((unsigned char)text[i])) {
            text[i] = 'A' + (text[i] - 'A' + key) % 26;
        } else if (islower((unsigned char)text[i])) {
            text[i] = 'a' + (text[i] - 'a' + key) % 26;
        }
    }

    printf("Encrypted text: %s", text);

    return 0;
}

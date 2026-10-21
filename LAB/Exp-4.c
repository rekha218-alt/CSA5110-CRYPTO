```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char text[1000], key[100];
    int i, j = 0, shift;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter keyword: ");
    scanf("%99s", key);

    if (strlen(key) == 0) {
        printf("Invalid key.\n");
        return 1;
    }

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            shift = toupper((unsigned char)key[j % strlen(key)]) - 'A';

            if (isupper((unsigned char)text[i])) {
                text[i] = 'A' + (text[i] - 'A' + shift) % 26;
            } else {
                text[i] = 'a' + (text[i] - 'a' + shift) % 26;
            }

            j++;
        }
    }

    printf("Encrypted text: %s", text);

    return 0;
}
```

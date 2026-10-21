```c
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char text[1000];
    char key[27];
    int i, valid = 1;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter 26-letter substitution key: ");
    scanf("%26s", key);

    if (key[26] != '\0') {
        valid = 0;
    }

    int seen[26] = {0};

    for (i = 0; i < 26; i++) {
        key[i] = (char)toupper((unsigned char)key[i]);

        if (key[i] < 'A' || key[i] > 'Z' ||
            seen[key[i] - 'A']) {
            valid = 0;
            break;
        }

        seen[key[i] - 'A'] = 1;
    }

    if (!valid) {
        printf("Invalid key. Enter 26 unique letters.\n");
        return 1;
    }

    for (i = 0; text[i] != '\0'; i++) {
        if (isupper((unsigned char)text[i])) {
            text[i] = key[text[i] - 'A'];
        } else if (islower((unsigned char)text[i])) {
            text[i] = (char)tolower(
                (unsigned char)key[text[i] - 'a']);
        }
    }

    printf("Encrypted text: %s", text);

    return 0;
}
```

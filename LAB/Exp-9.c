#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void createMatrix(char key[]) {
    int used[26] = {0};
    char letters[25];
    int n = 0;

    used['J' - 'A'] = 1;

    for (int i = 0; key[i] != '\0'; i++) {
        char c = toupper((unsigned char)key[i]);

        if (c == 'J') c = 'I';

        if (c >= 'A' && c <= 'Z' && !used[c - 'A']) {
            used[c - 'A'] = 1;
            letters[n++] = c;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!used[i])
            letters[n++] = 'A' + i;
    }

    n = 0;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matrix[i][j] = letters[n++];
}

void findPos(char c, int *r, int *col) {
    if (c == 'J') c = 'I';

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == c) {
                *r = i;
                *col = j;
                return;
            }
}

int main(void) {
    char key[100], cipher[1000];
    int r1, c1, r2, c2;

    printf("Enter keyword: ");
    scanf("%99s", key);

    printf("Enter ciphertext: ");
    scanf(" %999[^\n]", cipher);

    createMatrix(key);

    printf("Decrypted text: ");

    for (int i = 0; cipher[i] != '\0'; ) {
        while (cipher[i] == ' ' || cipher[i] == '\n')
            i++;

        if (cipher[i] == '\0')
            break;

        char a = toupper((unsigned char)cipher[i++]);

        while (cipher[i] == ' ' || cipher[i] == '\n')
            i++;

        if (cipher[i] == '\0')
            break;

        char b = toupper((unsigned char)cipher[i++]);

        findPos(a, &r1, &c1);
        findPos(b, &r2, &c2);

        if (r1 == r2) {
            putchar(matrix[r1][(c1 + 4) % 5]);
            putchar(matrix[r2][(c2 + 4) % 5]);
        } else if (c1 == c2) {
            putchar(matrix[(r1 + 4) % 5][c1]);
            putchar(matrix[(r2 + 4) % 5][c2]);
        } else {
            putchar(matrix[r1][c2]);
            putchar(matrix[r2][c1]);
        }
    }

    printf("\n");
    return 0;
}

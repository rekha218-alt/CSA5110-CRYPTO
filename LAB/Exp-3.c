#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void generateMatrix(char key[]) {
    int used[26] = {0};
    char combined[26];
    int count = 0, i, j;

    used['J' - 'A'] = 1;

    for (i = 0; key[i] != '\0'; i++) {
        char c = (char)toupper((unsigned char)key[i]);

        if (c == 'J')
            c = 'I';

        if (c >= 'A' && c <= 'Z' && !used[c - 'A']) {
            used[c - 'A'] = 1;
            combined[count++] = c;
        }
    }

    for (i = 0; i < 26; i++) {
        if (!used[i])
            combined[count++] = (char)('A' + i);
    }

    count = 0;

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            matrix[i][j] = combined[count++];
}

void findPosition(char c, int *row, int *col) {
    int i, j;

    if (c == 'J')
        c = 'I';

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

int main(void) {
    char key[100], text[1000], prepared[2000];
    int i, n = 0, row1, col1, row2, col2;

    printf("Enter keyword: ");
    scanf("%99s", key);

    printf("Enter plaintext: ");
    scanf(" %999[^\n]", text);

    generateMatrix(key);

    for (i = 0; text[i] != '\0'; i++) {
        char c = (char)toupper((unsigned char)text[i]);

        if (c >= 'A' && c <= 'Z') {
            if (c == 'J')
                c = 'I';

            if (n > 0 && prepared[n - 1] == c) {
                prepared[n++] = 'X';
            }

            prepared[n++] = c;
        }
    }

    if (n % 2 != 0)
        prepared[n++] = 'X';

    prepared[n] = '\0';

    printf("Encrypted text: ");

    for (i = 0; i < n; i += 2) {
        findPosition(prepared[i], &row1, &col1);
        findPosition(prepared[i + 1], &row2, &col2);

        if (row1 == row2) {
            printf("%c%c",
                   matrix[row1][(col1 + 1) % 5],
                   matrix[row2][(col2 + 1) % 5]);
        } else if (col1 == col2) {
            printf("%c%c",
                   matrix[(row1 + 1) % 5][col1],
                   matrix[(row2 + 1) % 5][col2]);
        } else {
            printf("%c%c",
                   matrix[row1][col2],
                   matrix[row2][col1]);
        }
    }

    printf("\n");
    return 0;
}

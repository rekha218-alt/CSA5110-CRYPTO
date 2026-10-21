#include <stdio.h>
#include <ctype.h>
#include <string.h>

char matrix[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};

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
    char text[1000], prepared[2000];
    int n = 0, r1, c1, r2, c2;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        char c = toupper((unsigned char)text[i]);

        if (c >= 'A' && c <= 'Z') {
            if (c == 'J') c = 'I';

            if (n > 0 && prepared[n - 1] == c)
                prepared[n++] = 'X';

            prepared[n++] = c;
        }
    }

    if (n % 2 != 0)
        prepared[n++] = 'X';

    printf("Encrypted text: ");

    for (int i = 0; i < n; i += 2) {
        findPos(prepared[i], &r1, &c1);
        findPos(prepared[i + 1], &r2, &c2);

        if (r1 == r2) {
            putchar(matrix[r1][(c1 + 1) % 5]);
            putchar(matrix[r2][(c2 + 1) % 5]);
        } else if (c1 == c2) {
            putchar(matrix[(r1 + 1) % 5][c1]);
            putchar(matrix[(r2 + 1) % 5][c2]);
        } else {
            putchar(matrix[r1][c2]);
            putchar(matrix[r2][c1]);
        }
    }

    printf("\n");
    return 0;
}

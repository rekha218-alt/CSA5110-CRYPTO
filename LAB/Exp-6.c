#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(void) {
    char cipher[1000];
    int a, b, i, inv;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    for (a = 1; a < 26; a++) {
        if (gcd(a, 26) != 1)
            continue;

        for (inv = 1; inv < 26; inv++) {
            if ((a * inv) % 26 == 1)
                break;
        }

        for (b = 0; b < 26; b++) {
            printf("\na=%d, b=%d: ", a, b);

            for (i = 0; cipher[i] != '\0'; i++) {
                if (isupper((unsigned char)cipher[i])) {
                    printf("%c",
                        'A' + (inv * (cipher[i] - 'A' - b + 26) % 26));
                } else if (islower((unsigned char)cipher[i])) {
                    printf("%c",
                        'a' + (inv * (cipher[i] - 'a' - b + 26) % 26));
                } else {
                    putchar(cipher[i]);
                }
            }
        }
    }

    return 0;
}

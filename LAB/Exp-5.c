#include <stdio.h>
#include <ctype.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(void) {
    char text[1000];
    int a, b, i;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    if (gcd(a, 26) != 1) {
        printf("Invalid a. It must be coprime to 26.\n");
        return 1;
    }

    b = ((b % 26) + 26) % 26;
    a = ((a % 26) + 26) % 26;

    for (i = 0; text[i] != '\0'; i++) {
        if (isupper((unsigned char)text[i])) {
            text[i] = 'A' +
                (a * (text[i] - 'A') + b) % 26;
        } else if (islower((unsigned char)text[i])) {
            text[i] = 'a' +
                (a * (text[i] - 'a') + b) % 26;
        }
    }

    printf("Encrypted text: %s", text);

    return 0;
}

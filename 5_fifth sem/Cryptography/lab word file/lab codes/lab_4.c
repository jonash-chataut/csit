#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char plaintext[100], ciphertext[100];
    int key[2][2];
    int i, j = 0;

    printf("===================================\n");
    printf("||       Hill Cipher             ||\n");
    printf("|| Compiled by :- Jonash Chataut ||\n");
    printf("===================================\n\n");

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    printf("Enter 2x2 Key Matrix:\n");
    for (i = 0; i < 2; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            scanf("%d", &key[i][k]);
        }
    }

    int len = strlen(plaintext);

    // Convert to uppercase
    for (i = 0; i < len; i++)
    {
        plaintext[i] = toupper(plaintext[i]);
    }

    // Add X if length is odd
    if (len % 2 != 0)
    {
        plaintext[len] = 'X';
        plaintext[len + 1] = '\0';
        len++;
    }

    for (i = 0; i < len; i += 2)
    {
        int p1 = plaintext[i] - 'A';
        int p2 = plaintext[i + 1] - 'A';

        int c1 = (key[0][0] * p1 + key[0][1] * p2) % 26;
        int c2 = (key[1][0] * p1 + key[1][1] * p2) % 26;

        ciphertext[j++] = c1 + 'A';
        ciphertext[j++] = c2 + 'A';
    }

    ciphertext[j] = '\0';

    printf("\nPlaintext  : %s\n", plaintext);
    printf("Ciphertext : %s\n", ciphertext);

    return 0;
}
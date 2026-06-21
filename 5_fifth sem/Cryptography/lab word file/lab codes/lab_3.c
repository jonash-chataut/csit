#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void generateMatrix(char key[])
{
    int used[26] = {0};
    int row = 0, col = 0;

    used['J' - 'A'] = 1;

    for (int i = 0; key[i] != '\0'; i++)
    {
        char ch = toupper(key[i]);

        if (ch == 'J')
            ch = 'I';

        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A'])
        {
            matrix[row][col++] = ch;
            used[ch - 'A'] = 1;

            if (col == 5)
            {
                row++;
                col = 0;
            }
        }
    }

    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        if (!used[ch - 'A'])
        {
            matrix[row][col++] = ch;

            if (col == 5)
            {
                row++;
                col = 0;
            }
        }
    }
}

void findPosition(char ch, int *row, int *col)
{
    if (ch == 'J')
        ch = 'I';

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

int main()
{
    char key[50], plaintext[100], prepared[100];
    char ciphertext[100];

    printf("===================================\n");
    printf("||     Playfair Cipher           ||\n");
    printf("|| Compiled by :- Jonash Chataut ||\n");
    printf("===================================\n\n");

    printf("Enter keyword: ");
    scanf("%s", key);

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    generateMatrix(key);

    int k = 0;

    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char ch = toupper(plaintext[i]);

        if (ch == 'J')
            ch = 'I';

        prepared[k++] = ch;

        if (plaintext[i + 1] != '\0' &&
            toupper(plaintext[i]) == toupper(plaintext[i + 1]))
        {
            prepared[k++] = 'X';
        }
    }

    if (k % 2 != 0)
        prepared[k++] = 'X';

    prepared[k] = '\0';

    int c = 0;

    for (int i = 0; i < k; i += 2)
    {
        int r1, c1, r2, c2;

        findPosition(prepared[i], &r1, &c1);
        findPosition(prepared[i + 1], &r2, &c2);

        if (r1 == r2)
        {
            ciphertext[c++] = matrix[r1][(c1 + 1) % 5];
            ciphertext[c++] = matrix[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2)
        {
            ciphertext[c++] = matrix[(r1 + 1) % 5][c1];
            ciphertext[c++] = matrix[(r2 + 1) % 5][c2];
        }
        else
        {
            ciphertext[c++] = matrix[r1][c2];
            ciphertext[c++] = matrix[r2][c1];
        }
    }

    ciphertext[c] = '\0';

    printf("\nPlayfair Matrix:\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nPrepared Plaintext : %s\n", prepared);
    printf("Encrypted Message  : %s\n", ciphertext);

    return 0;
}
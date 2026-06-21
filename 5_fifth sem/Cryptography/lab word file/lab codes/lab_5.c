#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], cipher[100], decrypt[100];
    int rails, len, i, j;

    printf("===================================\n");
    printf("||      Rail Fence Cipher        ||\n");
    printf("|| Compiled by :- Jonash Chataut ||\n");
    printf("===================================\n\n");

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';
    len = strlen(text);

    printf("Enter number of rails: ");
    scanf("%d", &rails);

    char rail[rails][100];

    // Initialize matrix
    for (i = 0; i < rails; i++)
        for (j = 0; j < len; j++)
            rail[i][j] = '\n';

    // Encryption
    int row = 0, dir = 1;

    for (i = 0; i < len; i++)
    {
        rail[row][i] = text[i];

        if (row == 0)
            dir = 1;
        else if (row == rails - 1)
            dir = -1;

        row += dir;
    }

    int k = 0;
    for (i = 0; i < rails; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (rail[i][j] != '\n')
                cipher[k++] = rail[i][j];
        }
    }
    cipher[k] = '\0';

    // Decryption
    for (i = 0; i < rails; i++)
        for (j = 0; j < len; j++)
            rail[i][j] = '\n';

    row = 0;
    dir = 1;

    for (i = 0; i < len; i++)
    {
        rail[row][i] = '*';

        if (row == 0)
            dir = 1;
        else if (row == rails - 1)
            dir = -1;

        row += dir;
    }

    k = 0;
    for (i = 0; i < rails; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (rail[i][j] == '*' && k < len)
                rail[i][j] = cipher[k++];
        }
    }

    row = 0;
    dir = 1;

    for (i = 0; i < len; i++)
    {
        decrypt[i] = rail[row][i];

        if (row == 0)
            dir = 1;
        else if (row == rails - 1)
            dir = -1;

        row += dir;
    }
    decrypt[len] = '\0';

    printf("\nOriginal Message : %s\n", text);
    printf("Encrypted Message: %s\n", cipher);
    printf("Decrypted Message: %s\n", decrypt);

    return 0;
}
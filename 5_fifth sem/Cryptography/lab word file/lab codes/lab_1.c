#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], encrypted[100], decrypted[100];
    int key, i;

    printf("===================================\n");
    printf("||     Caesar Cipher Algorithm   ||\n");
    printf("|| Compiled by :- Jonash Chataut ||\n");
    printf("===================================\n\n");

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline character if present
    text[strcspn(text, "\n")] = '\0';

    printf("Enter shift key: ");
    scanf("%d", &key);

    // Encryption
    for (i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            encrypted[i] = ((ch - 'A' + key) % 26) + 'A';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            encrypted[i] = ((ch - 'a' + key) % 26) + 'a';
        }
        else
        {
            encrypted[i] = ch;
        }
    }
    encrypted[i] = '\0';

    // Decryption
    for (i = 0; encrypted[i] != '\0'; i++)
    {
        char ch = encrypted[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            decrypted[i] = ((ch - 'A' - key + 26) % 26) + 'A';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            decrypted[i] = ((ch - 'a' - key + 26) % 26) + 'a';
        }
        else
        {
            decrypted[i] = ch;
        }
    }
    decrypted[i] = '\0';

    printf("\nOriginal Message : %s\n", text);
    printf("Encrypted Message: %s\n", encrypted);
    printf("Decrypted Message: %s\n", decrypted);

    return 0;
}
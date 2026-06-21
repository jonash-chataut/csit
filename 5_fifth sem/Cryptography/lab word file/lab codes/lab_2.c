#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100], key[100];
    char encrypted[100], decrypted[100];
    int i, j;

    printf("===================================\n");
    printf("||    Vigenere Cipher Algorithm  ||\n");
    printf("|| Compiled by :- Jonash Chataut ||\n");
    printf("===================================\n\n");

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter keyword: ");
    scanf("%s", key);

    int keyLen = strlen(key);

    // Encryption
    for (i = 0, j = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            char base = isupper(text[i]) ? 'A' : 'a';

            encrypted[i] = ((toupper(text[i]) - 'A') +
                            (toupper(key[j % keyLen]) - 'A')) %
                               26 +
                           base;

            j++;
        }
        else
        {
            encrypted[i] = text[i];
        }
    }
    encrypted[i] = '\0';

    // Decryption
    for (i = 0, j = 0; encrypted[i] != '\0'; i++)
    {
        if (isalpha(encrypted[i]))
        {
            char base = isupper(encrypted[i]) ? 'A' : 'a';

            decrypted[i] = ((toupper(encrypted[i]) - 'A') -
                            (toupper(key[j % keyLen]) - 'A') + 26) % 26 + base;
            j++;
        }
        else
        {
            decrypted[i] = encrypted[i];
        }
    }
    decrypted[i] = '\0';

    printf("\nOriginal Message : %s\n", text);
    printf("Encrypted Message: %s\n", encrypted);
    printf("Decrypted Message: %s\n", decrypted);

    return 0;
}
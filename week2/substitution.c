#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int length = strlen(key);

    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabet characters.\n");
            return 1;
        }
    }
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (key[i] == key[j] || key[i] == (key[j] - 32) || key[i] == (key[j] + 32))
            {
                printf("Key must only contain 1 of each letter.\n");
                return 1;
            }
        }
    }
    string plaintext = get_string("plaintext: ");
    int textlen = strlen(plaintext);
    for (int i = 0; i < textlen; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]))
            {
                plaintext[i] = tolower(key[plaintext[i] - 'a']);
            }
            else if (isupper(plaintext[i]))
            {
                plaintext[i] = toupper(key[plaintext[i] - 'A']);
            }
        }
    }
    printf("ciphertext: %s\n", plaintext);
    return 0;
}
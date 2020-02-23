#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    string key = argv[1];
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    
    // convert key to lower-case to ensure case-insentivity
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        key[i] = tolower(key[i]);
    }

    string text = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char current = text[i];

        if (!isalpha(current))
        {
            printf("%c", current);
        }

        char ciphered;
        if (isupper(current))
        {
            int offset = current - 'A';
            ciphered = toupper(key[offset]);
        }
        else
        {
            int offset = current - 'a';
            ciphered = key[offset];
        }

        printf("%c", ciphered);
    }
    
    printf("\n");
    return 0;
}
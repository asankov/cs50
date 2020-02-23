#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int EXPECTED_SUM = 2847;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int sum = 0;
    char previous;
    // convert key to lower-case to ensure case-insentivity
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain only letters.\n");
            return 1;
        }


        key[i] = tolower(key[i]);
        
        if (key[i] == previous) 
        {
            printf("Key must not contain repeative characters.\n");
            return 1;
        }
        previous = key[i];
        sum += key[i];
    }
    if (sum != EXPECTED_SUM)
    {
        printf("Key must not contain repeative characters.\n");
        return 1;
    }

    string text = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char current = text[i];

        if (!isalpha(current))
        {
            printf("%c", current);
            continue;
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
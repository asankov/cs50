#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");

    int letters = 0, words = 1, sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char current = text[i];
        if (isalpha(current))
        {
            letters++;
        } else if (current == ' ')
        {
            words++;
        } else if (current == '.' || current == '!' || current == '?')
        {
            sentences++;
        }
    }

    float coef = (100 / (float) words)
    float l = coaf * letters;
    float s = coaf * sentences;

    float index = 0.0588 * l - 0.296 * s - 15.8;


    if (index > 16)
    {
        printf("Grade 16+")
    } else if (index < 1)
    {
        printf("Below Grade 1")
    } else 
    {
        printf("Grade: %.0f\n", index);
    }
}

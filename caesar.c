#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char, int);

int main(int argc, string argv[])
{
    // There should be single argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Key must be decimal
    string KEY = argv[1];
    for (int i = 0; i < strlen(KEY); i++)
    {
        if (isdigit(KEY[i]) == 0)
        {
            return 1;
        }
    }

    // Take user input
    string text = get_string("plaintext: ");

    // Rotate through alphabets
    int key = atoi(argv[1]);
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (toupper(text[i]) >= 65 && toupper(text[i]) <= 90)
        {
            char c_letter = rotate(text[i], key);
            printf("%c", c_letter);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

char rotate(char letter, int key)
{
    // Rotating the letter by key
    char c_letter;
    if (letter >= 65 && letter <= 90)
    {
        c_letter = (((letter - 65) + key) % 26) + 65;
    }
    if (letter >= 97 && letter <= 122)
    {
        c_letter = (((letter - 97) + key) % 26) + 97;
    }
    return c_letter;
}

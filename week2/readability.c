#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int indexRound = round(index);

    if (indexRound < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (indexRound > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", indexRound);
    }
}
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words + 1;
}

int count_sentences(string text)
{
    int sents = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sents++;
        }
    }
    return sents;
}

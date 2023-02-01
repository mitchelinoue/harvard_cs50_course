#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    float l = count_letters(text) / (float) count_words(text) * 100;
    float s = count_sentences(text) / (float) count_words(text) * 100.00;
    float index = 0.0588 * l - 0.296 * s - 15.8;

    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",(int) round(index));
    }
}

int count_letters(string text)
{
    int index = strlen(text);
    int is_letter = 0;
    for (int i = 0; i < index; i++)
    {
        if (isalpha(text[i]))
        {
            is_letter++;
        }
    }
    return is_letter;
}

int count_words(string text)
{
    int index = strlen(text);
    int is_space = 1;
    for (int i = 0; i < index; i++)
    {
        if (isspace(text[i]))
        {
            if (!isspace(text[i + 1]) || !isspace(text[i + 1]))
            {
                is_space++;
            }
        }
    }
    return is_space;
}

int count_sentences(string text)
{
    int index = strlen(text);
    int is_sentence = 0;
    for (int i = 0; i < index; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            if (text[i - 1] != '.' && text[i - 1] != '!' && text[i - 1] != '?')
            {
                is_sentence++;
            }
        }
    }
    return is_sentence;
}
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

void calc_reading_level(int num_letters, int num_words, int num_sentences);

int main(void)
{
    // prompt user for a string of text using get_string()
    string text = get_string("Text: ");

    // count the number of letters
    int num_letters = count_letters(text);
    // printf("%i letters\n", num_letters);

    // count number of words
    int num_words = count_words(text);
    // printf("%i words\n", num_words);

    // count sentences in the text
    int num_sentences = count_sentences(text);
    // printf("%i sentences\n", num_sentences);

    // print "Grade X", where grade X is htre grade level computed by the Coleman-Liau formula
    // (rounded to the nearest integer. if higher than 16, print "Grade 16+". If less than 1,
    //"Before Grade 1")
    calc_reading_level(num_letters, num_words, num_sentences);
}

int count_letters(string text)
{
    int len = strlen(text);
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int len = strlen(text);
    // count for the number of words
    int count = 0;
    // bool to turn on when a word begins and is to be turned off when a word ends
    bool is_word = false;
    // iterate through the string
    for (int i = 0; i < len; i++)
    {
        // is there is a letter and we arent already tracking a word, turn word-tracker on
        if (isalpha(text[i]) && is_word == false)
        {
            is_word = true;
        }
        // if the word-tracker is on and there is a space or puncuation, add the  word to the word count and turn off word counter.
        else if ((isspace(text[i]) || text[i] == 46 || text[i] == 33 || text[i] == 63) && is_word == true)
        {
            is_word = false;
            count++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int len = strlen(text);
    // count for the number of words
    int count = 0;
    // iterate through the string
    for (int i = 0; i < len; i++)
    {
        // count the number of punctuations
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            count++;
        }
    }
    return count;
}

void calc_reading_level(int num_letters, int num_words, int num_sentences)
{
    float L = (float) num_letters / (float) num_words * 100;
    float S = (float) num_sentences / (float) num_words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index >= 16.0)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1.0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}
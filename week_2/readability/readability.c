// Program to determine the grade level readability of some text
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get input from user some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = 0;
    int words = 0;
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Letters are counted as any a-z or A-Z character
        if (isalpha(text[i]))
        {
            letters++;
        }
        // Words are counted as any sequence of characters separated by spaces assuming the previous character is a letter
        else if (isspace(text[i]) && isalpha(text[i - 1]))
        {
            words++;
        }
        // Sentences are counted as any sequence of characters ending in a period, exclamation point, or question mark assuming the previous character is a letter
        else if ((text[i] == '.' || text[i] == '!' || text[i] == '?') && isalpha(text[i - 1]))
        {
            words++;
            sentences++;
        }
    }
    // Use the Coleman-Liau index to determine the grade level readability of the text
    //  index = 0.0588 * L - 0.296 * S - 15.8 where L is the average number of letters per 100 words in the text and S is the average number of sentences per 100 words in the text
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //  Output "Grade X" where X is the grade level
    //  If the grade level is 16 or greater, output "Grade 16+"
    //  If the grade level is less than 1, output "Before Grade 1"
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

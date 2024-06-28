// Scrabble-like game that calculates the score of a word

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Prompt player 1 for a word
    string word1 = get_string("Player 1: ");
    // Prompt player 2 for a word
    string word2 = get_string("Player 2: ");
    // Calculate the score of each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    // Print the winner with "Player 1 wins!" or "Player 2 wins!" or "Tie!"
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // initialize score
    int score = 0;

    // iterate over each character in the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isalpha(word[i]))
        {
            // calculate the score of the letter and add it to the total score
            score += POINTS[toupper(word[i]) - 'A'];
        }
    }
    // return the total score
    return score;
}

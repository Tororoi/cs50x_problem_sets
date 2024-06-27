// Scrabble-like game that calculates the score of a word

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

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
    // Compare the scores of each word
    // Print the winner with "Player 1 wins!" or "Player 2 wins!" or "Tie!"
}

int compute_score(string word)
{
}

// Encrypt messages using a cipher
#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

const int KEY_LENGTH = 26;
// Program should accept 1 command-line argument: a key to use for the substitution.
// The key itself should be case-insensitive and should contain 26 characters.
// Return an error if the program is called with the wrong number of arguments
// Return an error if the key is invalid (not 26 characters, not alphabetic, or repeated characters)
bool validate_key(string key);
void encrypt_text(string plaintext, string key);

int main(int argc, string argv[])
{
    // Check for correct number of arguments
    if (argc != 2)
    {
        printf("Wrong number of arguments.\nUsage: ./substitution KEY\n");
        return 1;
    }

    string provided_key = argv[1];
    // Validate key
    if (!validate_key(provided_key))
    {
        return 1;
    }
    // Get plaintext from user
    string text = get_string("plaintext: ");
    // Encrypt plaintext
    printf("ciphertext: ");
    encrypt_text(text, provided_key);
    return 0;
}

bool validate_key(string key)
{
    // Check for key length
    if (strlen(key) != KEY_LENGTH)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    // Check for repeated characters using an array
    int key_array[KEY_LENGTH] = {0};
    for (int i = 0; i < KEY_LENGTH; i++)
    {
        // Check for alphabetic characters
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }
        // Convert to lowercase and normalize value for key_array and key
        key[i] = tolower(key[i]);
        int c = key[i] - 'a';
        // Check for repeated characters
        if (key_array[c] > 0)
        {
            printf("Key must not contain repeated characters.\n");
            return false;
        }
        key_array[c]++;
    }
    return true;
}

void encrypt_text(string plaintext, string key)
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // if character is part of alphabet, encrypt it
        if (isalpha(plaintext[i]))
        {
            char substituted_char = key[tolower(plaintext[i]) - 'a'];
            if (isupper(plaintext[i]))
            {
                printf("%c", toupper(substituted_char));
            }
            else
            {
                printf("%c", tolower(substituted_char));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

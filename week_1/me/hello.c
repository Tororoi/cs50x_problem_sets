#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for their name
    string name = get_string("What's your name? ");

    // Say hello to the user using their name
    printf("Hello, %s\n", name);
}

#include <cs50.h>
#include <stdio.h>

void print_row(int height, int blocks_per_side, int gap);
void print_pyramid(int height);
int main(void)
{
    // Prompt user for a positive integer between 1 and 8 inclusive
    int n;
    do
    {
        n = get_int("Choose the height of your pyramid between 1 and 8, inclusive: ");
    } while (n < 1 || n > 8);

    // Print a pyramid of blocks as hashes the height of the user's chosen integer
    print_pyramid(n);
}

void print_pyramid(int height)
{
    // Maintain a space of 2 blocks between each side of the pyramid.
    int gap = 2;
    // Print the pyramid
    for (int i = 0; i < height; i++)
    {
        // Row
        // Row width: height of the pyramid * 2 plus a gap of 2 blocks
        // Number of blocks on each side of the pyramid for this row: Row index plus 1
        print_row(height, i + 1, gap);
    }
}

void print_row(int height, int blocks_per_side, int gap)
{
    for (int i = 0; i < height * 2 + gap; i++)
    {
        // Column
        // if i is before the gap and past the value of the height of the pyramid minus the number of blocks per side on this row
        bool left_conditional = (i < height && i >= (height - blocks_per_side));
        // if i is past the left side plus the gap and less than or equal to that amount plus the number of blocks for this row
        int right_side_start = height + gap - 1;
        bool right_conditional = i > right_side_start && i <= right_side_start + blocks_per_side;
        if (left_conditional || right_conditional)
        {
            printf("#");
        }
        else if (i <= right_side_start)
        {
            printf(" ");
        }
        else
        {
            // escape loop, row is finished
            break;
        }
    }
    printf("\n");
}

#include <cs50.h>
#include <stdio.h>

void validate_card(unsigned long long int cc);
int main(void)
{
    // Prompt the user for their credit card
    unsigned long long int credit_card_number = get_long("Credit Card #: ");
    // Validate card number
    validate_card(credit_card_number);
}

void validate_card(unsigned long long int cc)
{
    int sum1 = 0;
    int sum2 = 0;
    int length = 0;
    int first_digit;
    int second_digit;
    // Check sum
    while (cc > 0)
    {
        // odd digit from right to left
        if (cc > 9)
        {
            second_digit = cc % 10;
            printf("Odd digit: %i\n", second_digit);
            sum1 += second_digit;
            cc /= 10;
            length++;
            // even digit from right to left
            if (cc > 9)
            {
                second_digit = cc % 10;
                printf("Even digit: %i\n", second_digit);
                // Multiply every other digit by 2, starting with the second to last digit
                int product = second_digit * 2;
                // Separately add each digit of the product
                if (product > 9)
                {
                    printf("Product digit: %i\n", product % 10);
                    sum2 += product % 10;
                    product /= 10;
                }
                printf("Product digit: %i\n", product);
                sum2 += product;
            }
            else
            {
                // first digit
                first_digit = cc;
                printf("Even digit: %i\n", first_digit);
                // Multiply every other digit by 2, starting with the second to last digit
                int product = first_digit * 2;
                // Separately add each digit of the product
                if (product > 9)
                {
                    printf("Product digit: %i\n", product % 10);
                    sum2 += product % 10;
                    product /= 10;
                }
                printf("Product digit: %i\n", product);
                sum2 += product;
            }
            cc /= 10;
            length++;
        }
        else
        {
            // first digit
            first_digit = cc;
            printf("Odd digit: %i\n", first_digit);
            sum1 += cc;
            cc /= 10;
            length++;
        }
    }
    // Add the sums together
    int total = sum1 + sum2;
    printf("sum1: %i\n", sum1);
    printf("sum2: %i\n", sum2);
    printf("total: %i\n", total);
    printf("length: %i\n", length);
    printf("first digit: %i\n", first_digit);
    printf("second_digit: %i\n", second_digit);
    // If the total's last digit is not 0, credit card is invalid
    if (total % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        // Output AMEX\n or MASTERCARD\n or VISA\n or INVALID\n
        if (length == 15 && first_digit == 3 && (second_digit == 4 || second_digit == 7))
        {
            // AMEX: 15 digits, starts with 34 or 37
            printf("AMEX\n");
        }
        else if (length == 16 && first_digit == 5 && (second_digit > 0 && second_digit < 6))
        {
            // MASTERCARD: 16 digits,starts with 51, 52, 53, 54,55
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && first_digit == 4)
        {
            // VISA:13 or 16 digits, starts with 4
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

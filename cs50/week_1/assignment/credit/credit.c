#include <stdio.h>
#include <stdbool.h>

int num_len(long num);
bool luhn_algorithm(long num);
bool card_name(long num);

int main(void)
{
    int return_value;
    long num;

    // Gets credit card number from user.
    do
    {
        return_value = printf("Number: ");
        scanf("%li", &num);
    }
    while (num < 1 || return_value != 1);

    // Confirms validity through luhn's algorithm.
    if (!(luhn_algorithm(num) && card_name(num)))
        printf("INVALID\n");

    return 0;
}

int num_len(long num)
{
    int len = 0;

    // Iterate throught num and calculates the number of digits in num.
    while (num != 0)
    {
        num = num / 10;
        len++;
    }
    
    return len;
}

bool luhn_algorithm(long num)
{
    int counter = 1, sum = 0;

    while (num != 0)
    {
        // Appropriately adds the "underlined" numbers.
        if (counter % 2 == 0)
        {
            int digit = (num % 10) * 2;
            sum += (digit > 9) ? (digit - 9) : digit;
        }

        // Adds none "underlined" numbers to sum.
        else
                sum = sum + (num % 10);

        // Iterate through num.
        num = num / 10;
        counter++;
    }

    // Confirms validity of the number.
    return (sum % 10 == 0);
}

bool card_name(long num)
{
    int number_length = num_len(num);

    // checks for American Express card.
    if (number_length == 15)
    {
        int first_two_num = num / 10000000000000;
        if (first_two_num == 34 || first_two_num == 37)
        {
            printf("American Express\n");
            return true;
        }
        return false;
    }

    // checks for MasterCard.
    else if (number_length == 16)
    {
        int first_two_num = num / 100000000000000;
        if (first_two_num == 51 || first_two_num == 52 || first_two_num == 53 || first_two_num == 54 || first_two_num == 55)
        {
            printf("MasterCard\n");
            return true;
        }
        return false;
    }

    // checks for Visa card.
    if (number_length == 13 || number_length == 16)
    {
        int first_num = num / (number_length == 13 ? 1000000000000 : 1000000000000000);
        if (first_num == 4)
        {
            printf("Visa\n");
            return true;
        }
        return false;
    }

    // No matches found.
    return false;
}

// Week 1 assignment, "Credit"
#include <cs50.h>
#include <stdio.h>
#include <string.h>

char *get_strnum(void);
bool luhn_algorithm(char *n);
int digit_addition(int number);
bool card_identifier(char *n);

int main(void)
{
    // Gets card number from user.
    char *card_number = get_strnum();

    // Checks if card number is syntactically correct.
    if (!luhn_algorithm(card_number))
    {
        printf("INVALID\n");
        return 0;
    }

    // Prints out card name(if any).
    if (!card_identifier(card_number))
    {
        printf("INVALID\n");
        return 0;
    }
}

// Forces user to input a number.
char *get_strnum(void)
{
    char *n;
    do
        n = get_string("Number: ");
    while (strspn(n, "0123456789") != strlen(n));
    return n;
}

// Checks if card number is syntactically correct.
bool luhn_algorithm(char *n)
{
    int length = strlen(n), product[] = {0, 0};

    // Calculates products.
    int i = (length % 2 == 0) ? 0 : 1;
    int j = (length % 2 == 0) ? 1 : 0;
    for (; i < length; i = i + 2)
    {
        int check = (n[i] - '0') * 2;
        if (check > 9)
            check = digit_addition(check);
        product[0] += check;
    }
    for (; j < length; j = j + 2)
        product[1] += (n[j] - '0');

    // Checks if the total modulo 10 is congruent to 0
    return (product[0] + product[1]) % 10 == 0;
}

// Calculates the sum of all the digits of a 2 digit integer.
int digit_addition(int number)
{
    return (number % 10) + (number / 10);
}

// Returns true and prints out the card name
//  or return false if card name is not found.
bool card_identifier(char *n)
{
    int len = strlen(n);
    if (n[0] == '3' && (n[1] == '4' || n[1] == '7') && len == 15)
    {
        printf("AMEX\n");
        return true;
    }
    if (n[0] == '5' && (n[1] >= '1' && n[1] <= '5') && len == 16)
    {
        printf("MASTERCARD\n");
        return true;
    }
    if (n[0] == '4' && (len == 13 || len == 16))
    {
        printf("VISA\n");
        return true;
    }
    return false;
}

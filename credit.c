#include <stdio.h>
#include <cs50.h>

int main() 
{
    long credit_card_number = get_long("Number: ");
    long cc = credit_card_number;

    int sum = 0;
    bool is_other_digit = false;
    while (credit_card_number != 0) 
    {
        int number = credit_card_number % 10;
        if (is_other_digit) 
        {
            number *= 2;
            if (number > 9) 
            {
                int first_digit = number % 10;
                int second_digit = number / 10;
                sum += (first_digit + second_digit);
            } 
            else 
            {
                sum += number;
            }
        }
        else 
        {
            sum += number;
        }

        is_other_digit = !is_other_digit;
        credit_card_number = credit_card_number / 10;
    }

    if (sum % 10 == 0) 
    {
        while (cc > 100)
        {
            cc = cc % 10;
        }
        if (cc >= 51 && cc <= 55) 
        {
            printf("MASTERCARD\n");
        }
        else if (cc == 34 || cc == 37) 
        {
            printf("AMERICAN\n");
        } 
        else if (cc >= 40 && cc <= 49)
        {
            printf("VISA\n");
        }
        printf("INVALID\n");
    } 
    else 
    {
        printf("INVALID\n");
    }
}

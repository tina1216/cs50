#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}



int get_cents(void)
{
    int cents_input = 0;

    do {
        cents_input = get_int("How many cents?: ¢");
    } while (cents_input <= 0);

    if (cents_input > 0) {
        return cents_input;
    } else {
        return 0;
    }

}

int calculate_quarters(int cents) // quarters (25¢)
{
    int quarters = 0;

    if (cents >= 25) {
        quarters = cents / 25;
        cents = cents % 25;
        return quarters;
    }

    return 0;
}

int calculate_dimes(int cents) //dimes (10¢)
{
    int dimes = 0;

    if (cents >= 10) {
        dimes = cents / 10;
        cents = cents % 10;
        return dimes;
    }

    return 0;

}

int calculate_nickels(int cents) //nickels (5¢)
{
    int nickels = 0;

    if (cents >= 5) {
        nickels = cents / 5;
        cents = cents % 5;
        return nickels;
    }

    return 0;

}

int calculate_pennies(int cents) //pennies (1¢)
{
    int pennies = 0;

    if (cents != 0) {
        pennies = cents / 1;
        cents = cents % 1;
        return pennies;
    }

    return 0;
}

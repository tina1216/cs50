#include <stdio.h>
#include <cs50.h>

int main(void) {
    long creditnumber = 0;
    do {
        creditnumber = get_long("Number: ");
    } while (creditnumber < 1 || creditnumber > 9999999999999999);

    // amex: 34 or 37, 15-digit
    // master: 51, 52, 53, 54, or 55, 16-digit
    // visa: 4, 13- and 16- digit
    int arrSize = 0;
    string cardType = "";

    if ((creditnumber >= 340000000000000 && creditnumber <= 349999999999999) || (creditnumber >= 370000000000000 && creditnumber <= 379999999999999)) {
        arrSize = 15;
        cardType = "AMEX";
    } else if((creditnumber >= 5100000000000000 && creditnumber <= 5199999999999999) || (creditnumber >= 5500000000000000 && creditnumber <= 5599999999999999)) {
        arrSize = 16;
        cardType = "MASTERCARD";
    } else if(creditnumber >= 4000000000000000 && creditnumber <= 4999999999999999) {
        arrSize = 16;
        cardType = "VISA";
    } else if (creditnumber >= 4000000000000 && creditnumber <= 4999999999999) {
        arrSize = 13;
        cardType = "VISA";
    } else {
        cardType = "INVALID";
    }

     int arr[arrSize];

    for (int i = arrSize - 1; i >= 0; i--) {
        arr[i] = creditnumber % 10;
        creditnumber /= 10;
    }

    // for (int i = 0; i < arrSize; i++) {
    //     arr[arrSize - 1 - i] = creditnumber % 10;
    //     creditnumber /= 10;
    // }

    int sum = 0;
    for (int i = 0; i < arrSize; i++) {
        if (i % 2 == arrSize % 2) {
            int doubled = arr[i] * 2;
            sum += doubled / 10 + doubled % 10; // Sum digits of doubled values
        } else {
            sum += arr[i];
        }
    }

    // int multipliedSum = 0;
    // int num = 0;
    // for (int i = 0; i < arrSize; i++) {
    //     if (i % 2 == 0) {
    //         num = arr[i] * 2;
    //         while (num != 0) {
    //             multipliedSum += num % 10;
    //             num /= 10;
    //         }
    //     } else {
    //         multipliedSum += arr[i];
    //     }
    // }

    if(sum % 10 == 0) {
        printf("%s\n", cardType);
    } else {
        printf("INVALID\n");
    }

    return 0;
}
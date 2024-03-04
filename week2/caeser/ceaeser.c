#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits();
int rotate(char c, int num);

int main(int argc, string argv[]) {
    int txt = 0;

    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (only_digits(argv[1]) == false) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

     // Convert argv[1]: string -> int
    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    //make cipher
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++) {
        txt = rotate(plaintext[i], key);
        printf("%c", txt);
    }
    printf("\n");


    return 0;
}

//function to make ciphertext
int rotate(char c, int num) {
    int result = 0, ch = 0;

    if (isalpha(c)) {

        if (isupper(c)) {
            ch = c - 65;
            result = (ch + num) % 26;
            ch = result + 65;
        } else if (islower(c)) {
            ch = c - 97;
            result = (ch + num) % 26;
            ch = result + 97;
        }

    } else {
        ch = c;
    }

    return ch;
}


// function to check if every character in argv[1] is a digit
bool only_digits(string argv1) {

    for (int i = 0; i < strlen(argv1); i++) {
        if (isdigit(argv1[i])) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}
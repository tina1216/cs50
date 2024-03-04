#include <stdio.h>
#include <cs50.h>

/*
#
##
###
####
#####
######
*/

// int main (void) {

//     int num = get_int("Height: ");

//     while (num < 0 || num > 8) {
//         num = get_int("Height: ");
//     }

//     for (int i=0; i < num; i++) {
//         for (int j=0; j <= i; j++) {
//             printf("#");
//         }
//         printf("\n");
//     }

//     return 0;
// }


//---------------------------------------

/*
.......#
......##
.....###
*/

int main (void) {

    int num = get_int("Height: ");

    while (num < 0 || num > 8) {
        num = get_int("Height: ");
    }

    for (int i=0; i < num; i++) {

        for (int j=8; j >= i; j--) {
            printf(".");
        }

        for (int j=0; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}


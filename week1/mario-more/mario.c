#include <stdio.h>
#include <cs50.h>

int main(void) {

    int height;

    do {
        height = get_int("Height: ");
    } while(height < 0 || 8 < height );

    for (int i = 0; i < height; i++) {

        for (int j = 8; j >= i; j--) {
            printf(" ");
        }
        // left
        for (int j = 8; j <= i; j++) {
            printf("#");
        }
        printf("  ");
        // right
        for (int j = 0; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
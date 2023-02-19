#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int check_number() {

    while (true) {
        int user_number = 0;
        scanf("%d", &user_number);

        if (user_number < 0 || user_number > 8) {
            printf("Please choose a number between 0 to 8:\n");
            continue;
        }

        return user_number;
    }
}

int main(void) {

    char array[9] = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};

    bool player_x = false;
    bool player_o = false;

    char x = 'X';
    char o = 'O';
    char which_letter;

    while(true) {
        printf("Please choose if you want to be X or O: \n");
        scanf(" %c", &which_letter);

        if (which_letter == 'O' || which_letter == 'X') {
            break;
        } 
    }

    // This variable keeps track of how many X and O's are on the board
    int count = 0;
    
    while(true) {

        if (which_letter == o) {
            player_o = true;
            printf("\nIt's O's turn! Choose a number from 0 to 8: \n");
        } else {
            player_x = true;
            printf("\nIt's X's turn! Choose a number from 0 to 8: \n");
        }

        int user_number = check_number();

        // checks if spot is taken by x or o
        if(array[user_number] == o || array[user_number] == x) {
            printf("That spot is already taken!\n");
            continue;
        }

        // Turn logic
        if (player_o) {
            array[user_number] = 'O';
            player_o = false;
            player_x = true;
            which_letter = 'X';
        } else {
            array[user_number] = 'X';
            player_x = false;
            player_o = true;
            which_letter = 'O';
        }

        // Keeps track to see if there are 9 pieces on the board
        count += 1;

        // print the board
        for (int i = 0; i <= 8; i++) {
            if (i == 2) {
                printf("%c\n", array[i]);
            } else if (i == 5) {
                printf("%c\n", array[i]);
            } else if (i == 8) {
                printf("%c\n", array[i]);
            } else {
                printf("%c", array[i]);
            }
        }

        // check win conditions for x
        if (array[0] == x && array[3] == x && array[6] == x) {
            break;
        }

        if (array[1] == x && array[4] == x && array[7] == x) {
            break;
        }

        if (array[2] == x && array[5] == x && array[8] == x) {
            break;
        }

        if (array[0] == x && array[4] == x && array[8] == x) {
            break;
        }

        if (array[2] == x && array[4] == x && array[6] == x) {
            break;
        }

        // check win conditions for o
        if (array[0] == o && array[3] == o && array[6] == o) {
            break;
        }

        if (array[1] == o && array[4] == o && array[7] == o) {
            break;
        }

        if (array[2] == o && array[5] == o && array[8] == o) {
            break;
        }

        if (array[0] == o && array[4] == o && array[8] == o) {
            break;
        }

        if (array[2] == o && array[4] == o && array[6] == o) {
            break;
        }

        // checks if there are 9 pieces on the board
        if (count == 9) {
            break;
        }
    }

    if (count == 9) {
        printf("Congrats, nobody won");
    } else if (player_o) {
        printf("Congrats, X won");
    } else {
        printf("Congrats, O won");
    }
}
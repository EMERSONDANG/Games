#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void build_man(char * man, int count) {

    if (count >= 0) {
        man[count] = 'O';
        printf(" %c\n", man[0]);

    }

    if (count >= 1) {
        man[count] = '/';
        printf("%c", man[1]);
    }

    if (count >= 2) {
        man[count] = '|';
        printf("%c", man[2]);

    }

    if (count >= 3) {
        man[count] = '/';
        printf("%c\n", man[3]);
    }

    if (count >= 4) {
        man[count] = '|';
        printf("%c", man[4]);
    }

    if (count >= 5) {
        man[count] = '|';
        printf(" %c", man[5]);
    }
}

void print_word(char* check_array, int number_of_letters) {
    for (int i = 0; i < number_of_letters + 1; i++) {
        printf("%c", check_array[i]);
    }
    printf("\n");
}

int main(void) {

    // Intialize an empty string and ask user for the winning word 
    // and store it into the empty string that holds 100 characters
    char winner_word[100];
    scanf("%s", &winner_word);

    // Variable to keep count how many letters in word
    int number_of_letters = strlen(winner_word);

    // Memory allocate a string array to store each letter
    // +1 to deal with null character of string
    char * winner_word_array = malloc(sizeof(char) * number_of_letters + 1);

    // For loop to store each letter of winning word into 
    for (int i = 0; winner_word[i] != '\0'; i++) {
        winner_word_array[i] = winner_word[i];
    }

    // Initialize empty array to check if winner array is same as this one
    char * check_array = malloc(sizeof(char) * number_of_letters + 1);

    // For loop to store each char as '_' and not garbage
    for (int i = 0; i < number_of_letters + 1; i++) {
        check_array[i] = '_';
    }

    // Make the man array to store body partsS
    char * man = malloc(sizeof(char) * 6);

    // Used for checking if a letter is found or not
    bool letter_not_found = true;

    // Used for index of man array
    int count = 0;

    // Int to check if number of letters is equal to number of winner word letters
    int win = 0;

    // Main game logic
    while (true) {
        printf("\nPlease guess a letter: \n");
        char user_letter;
        scanf(" %c", &user_letter);
        
        for (int i = 0; winner_word_array[i] != '\0'; i++) {
            if (winner_word_array[i] == user_letter) {
                check_array[i] = user_letter;
                printf("Letter found! \n");
                print_word(check_array, number_of_letters);
                letter_not_found = false;
                win += 1;
            }

            if (i == number_of_letters - 1 && letter_not_found) {
                printf("Letter not found! \n");
                print_word(check_array, number_of_letters);
                build_man(man, count);
                count += 1;
            }  
        }

        letter_not_found = true;
        
        // If all 5 man parts are made
        if (count == 6) {
            break;
        } 
        
        // if word is guessed
        if (win == number_of_letters) {
            break;
        }
    }

    // Determine if win or lose
    if (count == 6) {
        printf("\nGame over, you lost!");
    } else {
        printf("\nGame won, you win!");
    }
}
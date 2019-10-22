#include <stdio.h>

#define NUM 100 /* number of differen characters */
#define NEWCHARACTER 1
#define OLDCHARACTER 0


/* Print a histogram of the frequencies of different characters in input */

int main() 
{
    int character, num_characters, i, j, state;
    int frequencies[NUM];
    int characters[NUM];

    num_characters = 0;
    


    while ((character = getchar()) != EOF) {
        state = NEWCHARACTER;
        for (i = 0; i < num_characters; ++i) {
            if (character == characters[i]) {
                ++frequencies[i];
                state = OLDCHARACTER;
            } 
        }
        if (state != OLDCHARACTER) {
            state = NEWCHARACTER;
            characters[num_characters] = character;
            frequencies[num_characters] = 1;
            ++num_characters;
        }
        
    }

    printf("\n A histogram of the frequencies of different characters \n");
    for (i = 0; i < num_characters; i++) {
        if (characters[i] == ' ') {
            printf("\\b");
        } else if (characters[i] == '\n') {
            printf("\\n");
        } else if (characters[i] == '\t') {
            printf("\\t");
        } else {
            putchar(characters[i]);
            printf(" ");
        }
        for (j = 0; j < frequencies[i]; ++j) {
            printf(" * ");
        }
        printf("\n");
    }

    return 0;
}
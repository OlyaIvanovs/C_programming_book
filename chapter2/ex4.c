#include <stdio.h>
#define MAXLINE 100

/* Deletes each character in s1 that matches any character in the string s2 */

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[MAXLINE] = "The staccndart library includes a portable implementation of a pseudo-random number generator";
    char s2[MAXLINE] = "abcaasa";

    squeeze(s1, s2);
    printf("%s", s1);

}

void squeeze(char s1[], char s2[]) {
  int i, j, k;

  for (i = 0; s2[i] != '\0'; ++i) {
    for (k = j = 0; s1[k] != '\0'; ++k) {
      if (s1[k] != s2[i]) {
        s1[j++] = s1[k];
      } 
    }
    s1[j] = '\0';
  }
}


void squeeze2(char s1[], char s2[])
{
    int k = 0;
    int next_character;

    for (int i = 0; s1[i] != '\0'; i++) {
        next_character = 1;
        for (int j = 0; s2[j] != '\0' && next_character == 1; j++) {
            if (s1[i] == s2[j]) {  // if there is an occurence of the characters from s2 in s1, stop looping through s2
                next_character = 0;
            }
        }
        if (next_character == 1) {  // if there is no occurence of the characters from s2 in s1
            s1[k++] = s1[i];
        }
    }

    s1[k] = '\0';
}
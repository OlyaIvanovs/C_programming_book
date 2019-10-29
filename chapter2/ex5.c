#include <stdio.h>
#define MAXLINE 100

/* Returns the first location in the string s1 where any character from the string s2 occurs or -1 if s1 contains no characters from s2 */

int any(char s1[], char s2[]);

int main()
{
    char s1[MAXLINE] = "The staccndart library includes a portable implementation of a pseudo-random number generator";
    char s2[MAXLINE] = "abcaaa";

    int res = any(s1, s2); 

    printf("%d", res);

}
int any(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0'; i++) {
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {  // if there is an occurence of the characters from s2 in s1, stop looping through s2
                return i;
            }
        }
    }

    return -1;
}
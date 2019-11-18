#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void reverse(char s[]);

int main()
{
    char s[MAXLEN] = "maxlen";
    reverse(s);
    printf("%s", s);
    return 0;
}

void reverse(char s[]) {   
    int len = strlen(s);
    void reverser(char s[], int i, int  len);

    reverser(s, 0, len);
}
    
void reverser(char s[], int i, int  len) {
    int j, c;

    j = len - (i + 1);
    
    if( i < j )
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;

        reverser(s,++i,len);
    }
}
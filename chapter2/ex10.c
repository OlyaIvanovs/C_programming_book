#include <stdio.h>

/* convert c to lower case */

int lower(int c);

int main()
{
    int character = 'D';

    printf("%c", lower(character));
}

// int lower(int c)
// {
//     if (c >= 'A' && c <= 'Z')
//         return c + 'a' - 'A';
//     else
//         return c;
// }


int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
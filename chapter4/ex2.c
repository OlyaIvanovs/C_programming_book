#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAXLINE 1000

double atof(char s[]);

int main()
{
    char num_str[MAXLINE] = "354.67e-4";
    double  num = atof(num_str );
    printf("%.5e\n", num);
}

double atof(char s[])
{
    double val, power;
    int i, sign, e_sign, e_val;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;

    e_sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (e_val = 0; isdigit(s[i]); i++)
        e_val = 10 * e_val + (s[i] - '0');

    return (sign * val / power) * pow(10, e_sign*e_val);
}
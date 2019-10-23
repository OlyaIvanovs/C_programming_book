#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20


/* Print Fahrenheit-Celsius Table */

float fahr_to_celsius(float fahr)
{
    float celsius;

    celsius = (5.0/9.0) * (fahr-32.0);
    return celsius;
}

int main() 
{
    float fahr, celsius;
    
    fahr = LOWER;
    while (fahr <= UPPER) {
        celsius = fahr_to_celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }   
}
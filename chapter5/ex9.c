#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int main() {
    int day, m, d;

    day = day_of_year(2016, 9, 25);
    printf("%d\n", day);

    month_day(1988, 60, &m, &d);
    printf("%d %d", d, m);
    return 0;
}

/* set day of year from month and day */
int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0));
    for (i = 1; i < month; i++)
        day += *(*daytab + leap*13 + i);
    return day;
}


/* set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday){
    int i, leap;

    leap = (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0));
    for (i = 1; yearday > *(*daytab + leap*13 + i); i++) {
        yearday -= *(*daytab + leap*13 + i);
    }
    *pmonth = i;
    *pday = yearday;
}
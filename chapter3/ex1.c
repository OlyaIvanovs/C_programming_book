#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int n = 11;
    int v[] = {23, 45, 56, 78, 89, 90, 112, 455, 789, 856, 989, 1120};
    int x = 789;
    

    printf("In list number x %d takes a place number %d", x, binsearch(x, v, n));

}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low < high) {
        mid = (low + high)/2;
        if (x <= v[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    if (x == v[low]) 
        return low;
    else if (x == v[high]) 
        return high;
    else 
        return -1;
}
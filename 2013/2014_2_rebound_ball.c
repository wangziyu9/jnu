// 2013#1
// Description:

// a ball can reach half origin hight

// Code:

#include<stdio.h>

int main()
{
    int sum = 0;
    int n = 0;
    int d = 200;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        sum = sum + d;
        d = d / 2;
    }
    printf("%d\n", sum);
    return 0;
}

// Input:

// No input

// Output:

// 2
// 300
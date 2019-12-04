// 2013#1
// Description:

// Calculate the gcd and lcm in sub function

// Code:

#include<stdio.h>

int gcd(int a, int b)
{
    int tmp = 0;
    int mod = 1;
    while(mod != 0)
    {
        if(a < b)
        {
            tmp = a;
            a = b;
            b = tmp;
        }

        mod = a % b;
        a = mod;
    }
    printf("GCD %d\n", b);
    return b;
}

int lcm(int a, int b, int g)
{
    printf("LCM %d\n", a * b / g);
}

int main()
{
    int a = 60;
    int b = 48;
    int product = 0;


    scanf("%d %d", &a, &b);
    int g = gcd(a, b);
    lcm(a, b, g);
    return 0;
}

// 7 8
// GCD 1
// LCM 56
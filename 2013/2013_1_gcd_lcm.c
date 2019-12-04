#include<stdio.h>

int main()
{
    int a = 60;
    int b = 48;
    int product = 0;
    int tmp = 0;
    int mod = 1;

    scanf("%d %d", &a, &b);
    product = a * b;

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
    printf("LCM %d\n", product / b);
    return 0;
}
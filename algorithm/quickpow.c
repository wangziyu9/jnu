#include<stdio.h>

int quickPow(int base,int exp)
{   //快速幂
    int ans = 1;
    while(exp){
        if (exp & 1) 
        {
            ans*=base;
        }
        base *= base;
        exp /= 2;
    }
    return ans;
}

int main()
{
    printf("%d", quickPow(2, 10));
    return 0;
}
#include<stdio.h>

int quickPow(int a,int b)
{   //快速幂
    int ans = 1;
    while(b){
        if(b & 1) ans*=a;
        {
            a *= a;
        }
        b /= 2;
    }
    return ans;
}

int main()
{
    printf("%d", quickPow(2, 9));
    return 0;
}
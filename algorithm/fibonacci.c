#include<stdio.h>

int N = 10000,n;
void Matrix(int (a)[2][2],int b[2][2])
{
    int tmp[2][2] = {0};
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            for(int k = 0; k < 2; ++k)
                tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % N;
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            a[i][j] = tmp[i][j];
}

int main()
{
    int n;
    while(scanf("%d", &n) != 0)
    {
        int temp[2][2] = {1, 1, 1, 0},cot[2][2] = {1, 0, 0, 1};
        while(n)
        {
            if(n & 1) Matrix(cot,temp);
            Matrix(temp,temp);
            n /= 2;
        }
        printf("%d ", cot[0][1]);
    }
    return 0;
}
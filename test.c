#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    for(int i = 0; i < 20; i++)
    {
        printf("%d %d\n", i, i & 10);
    }
    
    return 0;
}
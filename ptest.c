#include<stdio.h>
#include<stdlib.h>
int main ()
{
    int a[10];
    int p[10] = {1, 2, 3, 5, 6, 8};

    for(int i = 0; i < 10; i++)
    {
        p[i] = &a[i];
    }
    for(int i = 0; i < 10; i++)
    {
        printf("%p ", p[i]);
    }
    return 0;
}
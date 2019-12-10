#include<stdio.h>
#include<stdlib.h>
int main ()
{
    int a[10] = {8,9,7,5,7,};
    int *p[10];

    for(int i = 0; i < 10; i++)
    {
        p[i] = &a[i];
    }
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", *p[i]);
    }
    return 0;
}
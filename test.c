#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void swap(int *pa, int *pb)
{
    printf("%d %d\n\n", pa, *pa);
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}
int main()
{
    int a = 1, b = 88;
    swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}
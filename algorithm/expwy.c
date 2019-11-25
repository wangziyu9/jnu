#include<stdio.h>


int notEmpty(int dateset[])
{
    int sum = 0;
    for(int i = 0; i < 20; i++)
    {
        sum += dateset[i];
    }
    return sum;
}

int delNum(int dateset[], int num)
{
    int found = 0;
    for(int i = 0; i < 20; i++)
    {
        if(dateset[i] == num)
        {
            dateset[i] = 0;
            found = 1;
            break;
        }
    }
    return found;
}

int dMax(int dateset[])
{
    int max = 0;
    for(int i = 0; i < 20; i++)
    {
        if(dateset[i] > max)
        {
            max = dateset[i];
        }
    }
    return max;
}

int place(int place[], int dateset[], int N, int left ,int right)
{
    int dtMax, Found = 0;
    if()

}


int main(void)
{
    int dateset[20] = {1,2,2,2,3,3,3,4,5,5,5,6,7,8,10};
    printf("sum is %d" , notEmpty(dateset));
    return 0;
}
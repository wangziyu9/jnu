#include<stdio.h>


int notEmpty(int distSet[])
{
    int sum = 0;
    for(int i = 0; i < 20; i++)
    {
        sum += distSet[i];
    }
    return sum;
}

int delNum(int distSet[], int num)
{
    int found = 0;
    for(int i = 0; i < 20; i++)
    {
        if(distSet[i] == num)
        {
            distSet[i] = 0;
            found = 1;
            break;
        }
    }
    return found;
}

int dMax(int distSet[])
{
    int max = 0;
    for(int i = 0; i < 20; i++)
    {
        if(distSet[i] > max)
        {
            max = distSet[i];
        }
    }
    return max;
}

int place(int place[], int distSet[], int N, int left ,int right)
{
    int dtMax, Found = 0;
    
    if(~notEmpty(distSet))
    {
        return 1;
    }
    dtMax = dMax(distSet);
    
}


int main(void)
{
    int distSet[20] = {1,2,2,2,3,3,3,4,5,5,5,6,7,8,10};
    printf("sum is %d" , notEmpty(distSet));
    return 0;
}
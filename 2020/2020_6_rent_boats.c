#include<stdio.h>

void sort(int n[], int length)
{
    int t = 0;
    for(int i = 0; i < length; i++)
    {
        for(int j = i; j < length; j++)
        {
            if(n[i]>n[j])
            {
                t = n[i];
                n[i] = n[j];
                n[j] = t;
            }
        }
    }
}

int rent_boat(int weight, int n[], int length)
{
    int total_boat = 0;
    int double_boat = 0;
    int i = 0; 
    int j = length - 1;
    for(i; i < j; i++)
    {
        for(j; j > i; j--)
        {
            if(n[i] + n[j] <= weight)
            {
                double_boat++;
                break;
            }
        }
    }
    total_boat = length - double_boat;
    return total_boat;
}
int main()
{
    int length = 5;
    int weight = 0;
    int total_boat = 0;
    int n[50] = {8,9,7,5,7,};

    scanf("%d", &weight);
    scanf("%d", &length);
    for(int i = 0; i < length; i++)
    {
        scanf("%d", &n[i]);
    }
    
    sort(n, length);

    total_boat = rent_boat(weight, n, length);
    printf("total boat count is:%d\n", total_boat);
    return 0;
}

// Input:
// 85 6
// 5 84 85 80 84 83

// Output:
// 5
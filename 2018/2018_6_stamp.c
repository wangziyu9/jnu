#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int a[100][3] = {0};

void init_array()
{
    for(int row = 0; row < 100; row++)
    {
        a[row][0] = 1;
    }
}
void config_array()
{
    int row = 0;
    for(int i = 1 + 1; i <= 1 * 4 + 1; i++)
    {
        for(int j = i + 1; j <= i * 4 + 1; j++)
        {
            a[row][1] = i;
            a[row][2] = j;
            row++;
        }
    }
}

void calculate_value()
{
    int totlemax = 0;
    for(int i = 0; i < 100; i++)
    {
        int value[100] = {0};
        int sum = 0;
        for(int x = 4; x >= 0; x--)
        {
            for(int y = 4 - x; y >= 0; y--)
            {
                for(int z = 4 - x - y; z >= 0; z--)
                {
                    printf("per count:%d %d %d ", x, y, z);
                    printf("per value:%d %d %d ", a[i][0], a[i][1], a[i][2]);
                    sum = x * a[i][0]+ y * a[i][1] + z * a[i][2];
                    value[sum] = 1;
                    printf("total value:%d\n", sum);
                }
            }
        }
        for(int max = 0; max < 100; max++)
        {
            if(value[max] == 0)
            {
                max = max - 1;
                printf("max value:%d\n", max);
                if(max > totlemax)
                {
                    totlemax = max;
                }
                break;
            }
        }
    }
}

int main()
{
    init_array();
    config_array();
    calculate_value();
    // for(int i = 0; i < 100; i++)
    // {
    //     printf("%d\t%d\t%d\n", a[i][0], a[i][1], a[i][2]);
    // }
    return 0;
}
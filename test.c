#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int VALUEFACES = 3;
int COUNTS = 4;
int a[100][3] = {0};

void init_array()
{
    for (int row = 0; row < 100; row++)
    {
        a[row][0] = 1;
    }
}

int config_col(int row, int col, int curr)
{
    for(int i = curr + 1; i <= curr * COUNTS + 1; i++)
    {
        a[row][col] = i;
        row = config_col(row, col + 1,i);
        if(col == COUNTS - 1)
        {
            row++;
            return row;
        }
    }
}

void config_array()
{
    int row = 0;
    config_col(row, 0, 0);
    
}

int main()
{
    init_array();
    config_array();
    // for(int i = 0; i < 100; i++)
    // {
    //     printf("%d\t%d\t%d\n", a[i][0], a[i][1], a[i][2]);
    // }
    return 0;
}
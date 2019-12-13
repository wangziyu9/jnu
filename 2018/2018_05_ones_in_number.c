// 20xx#x
// Description:

// 

// Code:

#include<stdio.h>
#include<stdlib.h>

char *my_itoa(int num, char *str)
{
        if(str == NULL)
        {
            return NULL;
        }
        sprintf(str, "%d", num);
        return str;
}

int calc_len(int num)
{
    int l = 0;
    while (num)
    {
        num = num / 10;
        l++;
    }
    return l;
}

// 遍历数字，数字转化为字符串，实现统计 1 的数量
int traversal_count_ones(int num)
{
    char str[16] = {0};
    int ones = 0;
    for(int i = 0; i <= num; i++)
    {
        my_itoa(i, str);
        for(int j = 0; j < 16; j++)
        {
            if(str[j] == '1')
                ones++;
        }
    }
    
    return ones;
}

int main()
{
    int num = 0;
    while(1)
    {
        scanf("%d", &num);
        printf("the length is:\t%d\n", calc_len(num));
        printf("count of 1 is:\t%d\n", traversal_count_ones(num));
    }
}


// Input:

// No input

// Output:
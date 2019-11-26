// 2017#1
// Description:
// split odd number and even number, put odd numbers in the left of the list

// Code:

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int markL = 0;
    int markR = 12;
    int temp = 0;
    int num[12] = {1, 9, 71, 5, 7, 42, 5, 4, 6, 1, 2, 39};
    // 分别从左右两端向中间遍历，交换奇偶数
    for (int l = markL; l < markR; l++)
    {
        markL = l;
        if (num[l] % 2 == 0)
        {
            for (int r = markR; r > markL; r--)
            {
                markR = r;
                if (num[r] % 2 == 1)
                {
                    temp = num[l];
                    num[l] = num[r];
                    num[r] = temp;
                    break;
                }
            }
        }        
    }
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", num[i]);
    }
    return 0;
}

// Input:

// Output:
// 1 9 71 5 7 39 5 1 6 4 2 42
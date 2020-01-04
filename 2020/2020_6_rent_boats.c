// 租船问题
#include<stdio.h>

// 冒泡排序数组升序
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

// 两端分别向内遍历有序数组，找到可以同乘的乘客，计算租船数量
int rent_boat(int weight, int n[], int length)
{
    int total_boat = 0;
    int double_boat = 0;
    int i = 0; 
    int j = length - 1;

    // 两端分别向内遍历有序数组，如果小于限重，可两人同乘，如果大于限重，则继续向内遍历，直到两端相遇
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
    // 总租船数 = 总人数 - 两人同乘的船数
    total_boat = length - double_boat;
    return total_boat;
}

// 主函数处理输入输出
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

// Input/Output:
// 85 6
// 5 84 85 80 84 83
// total boat count is:5

// 20 2    
// 11 11
// total boat count is:2
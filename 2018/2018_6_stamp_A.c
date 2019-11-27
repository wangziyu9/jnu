// 2018#6
// Description:

// 题目：假设国家发行了n种不同面值的邮票，并且规定每张信封上最多只允许贴m张邮票。连续邮资问题要求对于给定的n和m的值，给出邮票面值的最佳设计，在1张信封上可贴出从邮资1开始，增量为1的最大连续邮资区间。例如，当n=5和m=4时，面值为(1,3,11,15,32)的5种邮票可以贴出邮资的最大连续邮资区间是1到70。

// 注，本例代码中，n = 3, m <= 4，最大连续邮资区间是 1 到 26。
// 本算法处理题目中所给 n = 5, m = 4，运行时间是不可接受的。应使用动态规划的方法。

// 思路：当 n = 3，构建一个 100 * 3 的二维数组，第一维是序号，大于所有可能的情况数量，第二维存储三种具体的面值
// 首先构造数组。
// 第一种面值固定为一(a = 1)。
// 第二种面值最小值为第一种面值多一(bmin = a + 1)，可以保证不小于第一种邮票面值，避免两种面值相同。
// 最大值是比四张第一种面值多一(bmax = 4 * a + 1)，如此一来可以保证比最多张第一种邮票的总面值只多 1，避免总面值接不上。
// 遍历第二种面值各种可能的情况，第三种面值同理。
// 构造好数组之后，遍历数组，遍历每种面值组合下，各种可能的贴邮票方法组合，得到邮资数组。
// 遍历各个邮资数组，找到最大的连续邮资，并输出。

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int a[100][3] = {0};

// 初始化数组
void init_array()
{
    for(int row = 0; row < 100; row++)
    {
        a[row][0] = 1;
    }
}

// 构造数组
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

// 计算邮资组合
int calculate_value()
{
    int totalmax = 0;
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
                
                if(max > totalmax)
                {
                    totalmax = max;
                    printf("totalmax value:%d\n", totalmax);
                }
                break;
            }
        }
    }
    return(totalmax);
}

// 主函数
int main()
{
    init_array();
    config_array();
    printf("when COUNTs <= 4, FACEVALUEs = 3,max value is %d",calculate_value());
    return 0;
}

// (when COUNTs <= 4, FACEVALUEs = 3)
// output

// per count:4 0 0 per value:1 5 8 total value:4
// per count:3 1 0 per value:1 5 8 total value:8
// per count:3 0 1 per value:1 5 8 total value:11
// per count:3 0 0 per value:1 5 8 total value:3
// per count:2 2 0 per value:1 5 8 total value:12
// per count:2 1 1 per value:1 5 8 total value:15
// per count:2 1 0 per value:1 5 8 total value:7
// per count:2 0 2 per value:1 5 8 total value:18
// per count:2 0 1 per value:1 5 8 total value:10
// per count:2 0 0 per value:1 5 8 total value:2
// per count:1 3 0 per value:1 5 8 total value:16
// per count:1 2 1 per value:1 5 8 total value:19
// per count:1 2 0 per value:1 5 8 total value:11
// per count:1 1 2 per value:1 5 8 total value:22
// per count:1 1 1 per value:1 5 8 total value:14
// per count:1 1 0 per value:1 5 8 total value:6
// per count:1 0 3 per value:1 5 8 total value:25
// per count:1 0 2 per value:1 5 8 total value:17
// per count:1 0 1 per value:1 5 8 total value:9
// per count:1 0 0 per value:1 5 8 total value:1
// per count:0 4 0 per value:1 5 8 total value:20
// per count:0 3 1 per value:1 5 8 total value:23
// per count:0 3 0 per value:1 5 8 total value:15
// per count:0 2 2 per value:1 5 8 total value:26
// per count:0 2 1 per value:1 5 8 total value:18
// per count:0 2 0 per value:1 5 8 total value:10
// per count:0 1 3 per value:1 5 8 total value:29
// per count:0 1 2 per value:1 5 8 total value:21
// per count:0 1 1 per value:1 5 8 total value:13
// per count:0 1 0 per value:1 5 8 total value:5
// per count:0 0 4 per value:1 5 8 total value:32
// per count:0 0 3 per value:1 5 8 total value:24
// per count:0 0 2 per value:1 5 8 total value:16
// per count:0 0 1 per value:1 5 8 total value:8
// per count:0 0 0 per value:1 5 8 total value:0
// totalmax value:26
// when COUNTs <= 4, FACEVALUEs = 3,max value is 26
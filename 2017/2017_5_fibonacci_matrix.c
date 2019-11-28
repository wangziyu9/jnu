// 20xx#x
// Description:

// fibonacci
// O(n) O(logn)

// Explain:

// 斐波那契数列矩阵快速幂实现，时间复杂度 O(logn)。
// 本例中连续输出前 n 项会慢一点，但是其中每一项确实是 O(logn)，很快的。
// 数学原理是
// 矩阵相乘
// [1 1] * [1 1] =  [2 1]
// [1 1]   [1 0]    [2 1]
// 
// [2 1] * [1 1] =  [3 2]
// [2 1]   [1 0]    [3 2]
// ……
// 以此类推
// 将累乘转化成幂运算
// [1 1] * [1 1] ^ n
// [1 1]   [1 0]
// 然后利用　O(logn) 的快速幂思想求解

// Code:

#include <stdio.h>

// 求矩阵乘积，[product] = [a] * [b]
void matrixmult(int product[2][2], int a[2][2], int b[2][2])
{
    product[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    product[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    product[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    product[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
}

// O(logn)
// 求快速幂
void matrixFastPow(int base[2][2], int exp)
{
    int product[2][2] = {{0, 0},{0, 0}};
    int ans[2][2] = {{1,1},{1,1}};

    while (exp)
    {
        if(exp & 1)
        {
            // ans *= base;
            matrixmult(product, ans, base);
            ans[0][0] = product[0][0];
            ans[0][1] = product[0][1];
            ans[1][0] = product[1][0];
            ans[1][1] = product[1][1];
        }

        // base *= base;
        matrixmult(product, base, base);
        base[0][0] = product[0][0];
        base[0][1] = product[0][1];
        base[1][0] = product[1][0];
        base[1][1] = product[1][1];
        
        exp /= 2;
    }
    printf("%d %d\n%d %d\n", ans[0][0], ans[0][1],ans[1][0], ans[1][1]);
    // printf("%d ", ans[0][1]);
}

int main()
{
    for(int i = 0; i < 20; i++)
    {
        int base[2][2] = {{1, 1}, {1, 0}};
        matrixFastPow(base,i);
    }
   
    return 0;
}

// Input:

// No input

// Output:

// 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765
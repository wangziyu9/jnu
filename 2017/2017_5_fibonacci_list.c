// 20xx#x
// Description:

// fibonacci
// O(n) O(logn)

// Explain:

// Code:

#include <stdlib.h>
#include <stdio.h>

// O(n)
// 斐波那契数列数组实现。
int fib[100] = {1, 1};
int main()
{
    // 构造数组。
    for(int i = 2; i < 40; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // 遍历输出数组。
    for(int i = 0; i < 40; i++)
    {
        printf("%d ", fib[i]);
    }
}

// Input:

// No input

// Output:

// 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352 24157817 39088169 63245986 102334155 
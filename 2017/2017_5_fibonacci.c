// 20xx#x
// Description:

// fibonacci
// O(n) O(logn)
// Code:

#include <stdlib.h>
#include <stdio.h>

// O(2^n)
int fib(int a, int b)
{
    printf("%d ", a);
    if(a < 10000000)
        return fib(b, a + b);
}

int main()
{
    int f = fib(1, 1);
    return 0;
}

// Input:

// No input

// Output:

// 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352
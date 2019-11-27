// 20xx#x
// Description:

// fibonacci
// O(n) O(logn)
// Code:

#include <stdlib.h>
#include <stdio.h>

// O(2^n)
void matrixmult(int c[2][2], int a[2][2], int b[2][2])
{
    int tmp[4];
    c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
}

void matrixFastPow(int base[2][2], int n, int mod)
{

}


int main()
{
    int init[2][2] = {{1, 1}, {0, 0}};
    int base[2][2] = {{0, 1}, {1, 1}};
    int c[2][2] = {0};

    matrixmult(c, init, base);
    printf("%d %d ", c[0][0], c[0][1]);

    return 0;
}

// Input:

// No input

// Output:

// 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352
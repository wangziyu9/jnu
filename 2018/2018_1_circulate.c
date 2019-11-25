// 2018#1
// Description:
// left shifting an array 25 positions.the array has 100 int.like [0, 1, 2, ..., 98, 99] --> [25, 26, ..., 99, 0, 1, ..., 24]
// Time complexity O(n), Space Complexity O(1)

// Code:
#include <stdlib.h>
#include <stdio.h>

// reverse the array. start, end index
void reverse(int a[], int s, int e)
{
    int temp = 0;
    for (int i = s, j = e; i < j; i++, j--)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
int main()
{
    int n = 25;

    // config [0-99] array
    int a[100];
    for (int i = 0; i < 100; i++)
    {
        a[i] = i;
    }

    int l = sizeof(a) / sizeof(a[0]);

    reverse(a,0, n - 1);
    reverse(a,25, l - 1);
    reverse(a,0, l - 1);

    for (int i = 0; i < 100; i++)
    {
        printf("%d ", a[i]);
    }
    getchar();
    return 0;
}

// Input:

// No input

// Output:

// 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24

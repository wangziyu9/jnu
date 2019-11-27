// 20xx#x
// Description:

// Define a function
// Calculate the sum of the sequence 1 - 1/2 + 1/3 - 1/4 ...... 1/n
// Call functions in Main function

// Code:

#include<stdio.h>

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
int count_ones(int num)
{
    int ones = 0;
    int n = 1;

    return ones;
}
int main()
{
    printf("%d", calc_len(0));
    printf("%d", count_ones(10));

}


// Input:

// No input

// Output:
// 20xx#x
// Description:

// Define a function
// Calculate the sum of the sequence 1 - 1/2 + 1/3 - 1/4 ...... 1/n
// Call functions in Main function

// Code:

#include<stdio.h>

double sum_of_list(int n)
{
    double sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 == 1)
        {
            // Implicit type conversion
            sum = sum + 1.0 / i;
        }
        else
        {
            sum = sum - 1.0 / i;
        }
    }
    return sum;
}

int main()
{
    // Multiple num
    for (int i = 0; i < 10; i++)
    {
        double result = 0;
        result = sum_of_list(i);
        printf("%d:\t%f\n", i, result);
    }

    // single num
    // int n = 9; // any other Positive integer
    // double result = 0;
    // result = sum_of_list(n);
    // printf("%f", result);
    return 0;
}

// Input:

// No input

// Output:

// 0:	0.000000
// 1:	1.000000
// 2:	0.500000
// 3:	0.833333
// 4:	0.583333
// 5:	0.783333
// 6:	0.616667
// 7:	0.759524
// 8:	0.634524
// 9:	0.745635
// 2018#2
// Description:

// print a 6-row yanghui triangle
// 1   
// 1   1   
// 1   2   1   
// 1   3   3   1   
// 1   4   6   4   1   
// 1   5   10  10  5   1 

// Code:

#include<stdio.h>
int main()
{
    // init array, set all the num in first row as 0
    int arr[10][10] = {0};
    arr[0][1] = 1;
    for(int row = 0; row < 10; row++)
    {
        arr[row][0] = 0;
    }

    // [0 1 0 ......0]
    // [0 1 1 0 ....0]
    // [0 1 2 1 0...0]
    // ...
    // [0 ..........0]
    // config yanghui triangle array, start with the second row, a num is sum of the num in prev-column and this column in prev-row
    for(int row = 1; row < 10; row++)
    {
        for(int col = 1; col < 10; col++)
        {
            arr[row][col] = arr[row - 1][col - 1] + arr[row - 1][col];
        }
    }

    // print the yanghui triangle
    for(int row = 0; row < 6; row++)
    {
        // put space to make triangle be placed in the center
        for(int i = 6; i > row + 1; i--)
        {
            printf("  ");
        }

        // put each row of the triangle
        for(int col = 0; col < 10; col++)
        {
            if(arr[row][col] != 0)
            {
                printf("%-4d", arr[row][col]);
            }
        }
        printf("\n");
    }

    return 0;
}

// Input:

// No input

// Output:

//           1   
//         1   1   
//       1   2   1   
//     1   3   3   1   
//   1   4   6   4   1   
// 1   5   10  10  5   1   
// 20xx#x
// Description:

// find the first char which appear only once
// // Time complexity O(n * n)


// Code:

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    gets(str);
    int l = strlen(str);
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < l; j++)
        {
            // another but not the same char found
            if(str[i] == str[j] && i != j)
            {
                break;
            }
            // another char not found until the tile of the string
            if(j == l - 1)
            {
                printf("%c",str[i]);
                return 0;
            }
        }
    }
    puts(str);
    return 0;
}

// Input:

// Microsoft Corporation
// microsoft Corporationcsf
// icrosoft Corporation
// abaccdgk

// Output:

//
// M
// c
// b
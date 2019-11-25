// 2018#3
// Description:

// input a string from keyboard,end with "!"
// convert the string in caps
// put the string into file "test.txt"

// Code:

#include <stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{

    char str[512] = {0};
    printf("Enter the string:\n>>>");
    scanf("%[^\!]", str);
    
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        str[i] = toupper(str[i]);
    }

    puts(str);
    FILE *fp = NULL;
    fp = fopen("test_2018_3.txt", "w");
    fputs(str, fp);
    fclose(fp);
    return 0;
}


// Input:

// Enter the string:
// >>>balabala
// !

// Output:

// BALABALA

// See the file "test_2018_3.txt"


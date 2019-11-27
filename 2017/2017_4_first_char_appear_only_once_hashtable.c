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
    int tb[128] = {0};
    char str[100];

    // ASCII 编码中，有 128 个字符，只需要开一个 128 的数组，每个字符出现一次，记录在对应 ASCII 编码数组元素中
    gets(str);
    int l = strlen(str);
    for(int i = 0; i < l; i++)
    {
        tb[(int)str[i]]++;
    }
    
    // 再次遍历字符串，输出首个在数组中记录为一的字符
    for(int i = 0; i < l; i++)
    {
        if(tb[(int)str[i]] == 1)
        {
            printf("first sigle char is %c\n", str[i]);
            break;
        }
    }
    return 0;
}

// Input:
// Output:

// Microsoft Corporation
// first sigle char is M

// microsoft Corporationcsf
// first sigle char is m

// icrosoft Corporation
// first sigle char is c
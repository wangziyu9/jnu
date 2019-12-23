#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isLegal(char opreate[])
{
    int stack_ele_counta = 0;
    for(int i = 0; opreate[i] != '\0'; i++)
    {
        if(opreate[i] == 'I')
        {
            stack_ele_counta++;
        }
        else
        {
            stack_ele_counta--;
        }
        if(stack_ele_counta < 0)
        {
            break;
        }
    }
    if(stack_ele_counta != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    char opreate[50];
    scanf("%s", opreate);
    if(isLegal(opreate))
    {
        printf("opreate is legal\n");
    }
    else
    {
        printf("opreate is illegal\n");
    }
    return 0;
}

// Input/Output:

// IOIOIIOO
// opreate is legal

// IOOIOIOI
// opreate is illegal

// IIOOIIIO
// opreate is illegal
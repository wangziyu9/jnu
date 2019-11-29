# include<stdio.h>
# include<stdlib.h>

int main()
{
    int originList[100];
    for(int i = 0; i < 10; i++)
    {
        originList[i] = i + 1;
        // originList[i + 1] = -1;
    }

    int oddList[100];
    int evenList[100];
    int mixList[100];

    int i = 0;
    int oddIndex = 0;
    int evenIndex = 0;

    while (originList[i])
    {
        if(originList[i] % 2 == 1)
        {
            oddList[oddIndex] = originList[i];
            // oddList[oddIndex + 1] = -1;
            oddIndex++;
        }
        else
        {
            evenList[evenIndex] = originList[i];
            // evenList[evenIndex + 1] = -1;
            evenIndex++;
        }
        i++;
    }

    i = 0; 
    oddIndex = 0;
    evenIndex = 0;

    while (oddList[oddIndex])
    {
        mixList[oddIndex] = oddList[oddIndex];
        oddIndex++;
    }
    while (evenList[evenIndex])
    {
        mixList[evenIndex + oddIndex] = evenList[evenIndex];
        // mixList[evenIndex + oddIndex + 1] = -1;
        evenIndex++;
    }
    
    i = 0;
    while (mixList[i])
    {
        printf("%d ", mixList[i]);
        i++;
    }
    
    return 0;
}
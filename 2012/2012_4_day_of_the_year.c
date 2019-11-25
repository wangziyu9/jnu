// 2018#4
// Description:

// input a date
// print it is what day of the year

// Code:

#include<stdio.h>

int is_leap_year(int year)
{
    int leap = 0;
    if(year % 4 == 0 && year % 100 == year % 400)
    {
        leap = 1;
    }

    return leap;
}

int main()
{
    int year, month, day;
    int month_list [15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while(1)
    {
        int what_day = 0;

        printf("Enter a date like '2008-08-08'\n>>>");
        scanf("%d-%d-%d", &year, &month, &day);

        for(int i = 0; i < month; i++)
        {
            what_day = what_day + month_list[i];
        }
        what_day = what_day + day;

        if(month > 2)
        {
            what_day = what_day + is_leap_year(year);
        }
        printf("%d\n", what_day);
    }
   
    return 0;
}

// Input:

// No input

// Output:

// hello world
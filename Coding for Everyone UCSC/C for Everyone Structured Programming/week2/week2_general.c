//Write enumerated types that supports dates. Then add a function that produces a next day. Also write a function printdate(date) that prints a date legibly.

#include <stdio.h>
#include <ctype.h>

typedef enum month{january, february, march, april, may, june, july, august, september, october, november, december} month;
typedef struct date{month m; int d;} date;
int max_days, i;

void printday(date* dt)
{
    switch(dt->m)
    {
        case january:
            printf("January %d\n", dt->d);
            max_days = 31;
            break;
        case february:
            printf("February %d\n", dt->d);
            max_days = 28;
            break;
        case march:
            printf("March %d\n", dt->d);
            max_days = 31;
            break;
        case april:
            printf("April %d\n", dt->d);
            max_days = 30;
            break;
        case may:
            printf("May %d\n", dt->d);
            max_days = 31;
            break;
        case june:
            printf("June %d\n", dt->d);
            max_days = 30;
            break;
        case july:
            printf("July %d\n", dt->d);
            max_days = 31;
            break;
        case august:
            printf("August %d\n", dt->d);
            max_days = 31;
            break;
        case september:
            printf("September %d\n", dt->d);
            max_days = 30;
            break;
        case october:
            printf("October %d\n", dt->d);
            max_days = 31;
            break;
        case november:
            printf("November %d\n", dt->d);
            max_days = 30;
            break;
        case december:
            printf("December %d\n", dt->d);
            max_days = 31;
            break;
    }
}

date* nextday(date* dt){
    if(dt->d < max_days){
        dt->d++; //If we're not in the end of the month, just increment the day
    }
    else{
        dt->d = 1; //If we're in the end of the month, reset the day to 1
        if(dt->m < december){
            dt->m++;
        }
        else{
            dt->m = january; //If we're in the end of the year, reset the month to january
        }
    }
}

int main()
{
    date date1 = {january, 1};
    date date2 = {february, 28};
    date date3 = {march, 14};
    date date4 = {october, 31};
    date date5 = {december, 31};
    date dates[] = {date1, date2, date3, date4, date5};
    
    for (i=0; i<5; i++)
    {
        printf("Date is ");
        printday(&dates[i]);
        printf("\nNext day is ");
        nextday(&dates[i]);
        printday(&dates[i]);
        printf("\n\n");
    }

    return 0;
}

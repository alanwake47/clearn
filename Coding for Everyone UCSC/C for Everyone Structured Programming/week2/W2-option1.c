
#include <stdio.h>

typedef enum month{Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec} month;
typedef struct date{ month m; int d;} date;
// Days of each month, first element 0 because Jan = 1
int daysInAMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void nextDay(date date){
    printf("  The next day is: ");
    if (date.d == daysInAMonth[date.m]){
        date.m = date.m%12 +1;
        date.d = 1;}
    else date.d = date.d +1;

     printDate(date);
}

void printDate(date date){
    switch(date.m){
    case 1:  printf("January ")  ;break;
    case 2:  printf("February ") ;break;
    case 3:  printf("March ")    ;break;
    case 4:  printf("April ")    ;break;
    case 5:  printf("May")       ;break;
    case 6:  printf("June ")     ;break;
    case 7:  printf("July ")     ;break;
    case 8:  printf("August ")   ;break;
    case 9:  printf("September ");break;
    case 10: printf("October ")  ;break;
    case 11: printf("November ") ;break;
    case 12: printf("December ") ;break;
    default: printf("Error");break;
                   }
    printf("%d",date.d);
}

int main(void)
{
    //Test dates:
    struct date d1 ={.m=1,.d=1};   //January 1
    struct date d2 ={.m=2,.d=28};  //February 28
    struct date d3 ={.m=3,.d=14};  //March 14
    struct date d4 ={.m=10,.d=31}; //October 31
    struct date d5 ={.m=12,.d=31}; //December 31
    //print the test dates and the next day:
    printDate(d1);
    nextDay(d1);
    printf("\n");
    printDate(d2);
    nextDay(d2);
    printf("\n");
    printDate(d3);
    nextDay(d3);
    printf("\n");
    printDate(d4);
    nextDay(d4);
    printf("\n");
    printDate(d5);
    nextDay(d5);
    printf("\n");

    return 0;
}

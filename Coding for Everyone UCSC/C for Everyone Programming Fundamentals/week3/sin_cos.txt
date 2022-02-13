/*C program that has a function that prints a table of values for sine and cosine between (0, 1). You will upload your program as a text file*/

#include <stdio.h>
#include <math.h>
#define PI 3.14159265
int main(void)
{
    int i;
    float interval;
    printf("%s\t%s\t%11s\n","Degree","Sin","Cos"); //Headers for the table
    for (i = 0; i <= 10; i++) // looping from 0 degree to 30 degrees
    {
        interval = i/10.0; //0 to 1 values
        printf("%0.1f\t%lf\t%lf\n", interval, fabs(sin(interval*PI/180)), fabs(cos(interval*PI/180))); //printing positive values of sin and cos by converting degree to radians
    }
printf("\n+++++++\n");
return 0;
}
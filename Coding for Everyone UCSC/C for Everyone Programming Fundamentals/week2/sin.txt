/*
Write a program that can give the sine of a value between 0 and 1 (non inclusive). 
You will be graded based on whether the program can output a value in the correct range and whether your code is well-formatted and logically correct.
*/

// Function to scan input output sin value

#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    printf("Enter a value between 0 and 1 (non inclusive): ");
    scanf("%lf", &x);
    printf("sin(%lf) = %lf\n", x, sin(x));
    return 0;
}
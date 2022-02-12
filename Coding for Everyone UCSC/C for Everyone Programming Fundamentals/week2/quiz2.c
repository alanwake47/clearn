#include<stdio.h>

int main(void)
{ 
 int a=3, b=4, c=-2;
 int z;
 z = ++a + ++b;
 printf("++a + b++ = %d", z);
 return 0;
}
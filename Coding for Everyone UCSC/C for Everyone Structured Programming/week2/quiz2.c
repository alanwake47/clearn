#include <stdio.h>

int main(void)
{
    
    struct point{
    double x;
    double y;
    } p1 = {4, p1.x};
    struct point* ptr = &p1;
    printf("%f\n", ptr->y);
}
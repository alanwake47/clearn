#include <stdio.h>

int main() {
    int x = 1;
    switch(x)
    {
        case x:
            printf("case 1 ");
            break;
        case x+1;
            printf("case 2 ");
            break;
        default:
            printf("default block");
            break;
    }
    return 0;
}
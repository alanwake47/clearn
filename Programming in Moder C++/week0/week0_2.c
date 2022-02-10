#include <stdio.h>

enum Covid_prevention {
    Sanitizer = 1,
    Wear_mask = 2,
    Soc_distance = 4
};

int main()
{
    int myCovidPrevention = Wear_mask | Soc_distance;
    printf("%d", myCovidPrevention);
    return 0;
}
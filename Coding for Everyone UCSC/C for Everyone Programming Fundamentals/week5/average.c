/*Compute the average weight for a population of elephant seals read into an array*/

#include <stdio.h>

// Read elephantseals.txt file and Compute the average weight for a population of elephant seals read into an array

int main(void)
{
    int elephantseals[10000], i , sum=0, average , count=0;
    FILE *fp;
    fp = fopen("elephantseals.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    while (fscanf(fp, "%d", &elephantseals[count]) != EOF)
    {
        sum += elephantseals[count];
        count++;
    }
    average = sum / count;
    printf("The average weight of the elephant seals is %d pounds\n", average);
    fclose(fp);
    return 0;
}
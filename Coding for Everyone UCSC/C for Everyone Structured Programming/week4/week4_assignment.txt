/*Open and read a file of integers into an array that is created with the first integer telling you how many to read.
So  4  9  11  12  15  would mean create an int array size 4 and read in the remaining 4 values into data[].
Then compute their average as a double and their max  as an int.  
Print all this out neatly to the screen and to an output file named answer-hw3.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to calculate the average of an array of given size
double average(int d[], int size)
{
    int i;
    double sum=0;
    for (i=0; i<size; i++)
    {
        sum += d[i];
    }
    return(sum/size);
}

//Function to calculate maximum among the elements of an array
int maximum(int d[], int size)
{
    int i, max=d[0];
    for (i=0; i<size; i++)
    {
        if (d[i] > max)
        {
            max = d[i];
        }
    }
    return max;
}

//Function to read a file and store the values into an array
void read(FILE *ip, int d[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        fscanf(ip, "%d", &d[i]);
    }
}

//Function to write/store the average and maximum values into a file along with the data[] array as mentioned in the prompt
void write(FILE *op, int d[], int size, double avg, int max)
{
    //Loop indexes
    int i, j;
    //Character array to store the integers as characters
    char element[10];
    //The first loop iterates through each of the integers in the input array data[] and converts them to string using sprintf
    //The second loop iterates through the converted string and stores it in the file
    for (i=0; i<size; i++)
    {
        sprintf(element,"%d",d[i]);
        for (j=0; j<strlen(element); j++)
        {
            putc(element[j], op);
        }
        putc('\t',op);
    }
    putc('\n',op);

    //declaring strings to be printed
    char maximum[] = "The maximum integer in the array is:\t";
    char average[] = "The average value is:\t";

    //Storing the maximum string followed by its integer value converting using the same code as above
    for (i=0; i<strlen(maximum); i++)
    {
        putc(maximum[i],op);
    }
    sprintf(element,"%d",max);
        for (j=0; j<strlen(element); j++)
        {
            putc(element[j], op);
        }
    
    putc('\n',op);

    //Storing the average string and its value
    for (i=0; i<strlen(average); i++)
    {
        putc(average[i],op);
    }
    sprintf(element,"%f",avg);
        for (j=0; j<strlen(element); j++)
        {
            putc(element[j], op);
        }

    
}

int main()
{
    FILE *ip, *op; //Input and Output files
    int max, n;
    double avg;

    //opening the files
    ip = fopen("integer.txt", "r");
    op = fopen("answer-hw3", "w+");

    //Declaring an array of size n by reading the file till the first element
    if(fscanf(ip, "%d", &n) != 1){
        printf("File empty\n");
        exit(1);
    }
    int data[n];

    read(ip, data, n);

    avg = average(data, n);
    max = maximum(data, n);
    printf("\nThe Average is = %f\nThe Maximum value in the input file is = %d\n\n", avg, max);

    write(op, data, n, avg, max);

    fclose(ip);
    fclose(op);
}
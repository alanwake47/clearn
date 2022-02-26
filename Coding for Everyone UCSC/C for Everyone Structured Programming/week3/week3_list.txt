/*Use the linear linked list code to store a randomly generated set of 100 integers. 
Now write a routine that will rearrange the list in sorted order of these values.
Note you might want to use bubble sort to do this. Print these values in rows of 5 on the screen.

How will this work? Compare two adjacent list elements and if they are out of order swap them.
After a first pass the largest element will have bubbled to the end of the list.
Each pass can look at one less element as the end of a list stays sorted.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL 100 //NUMBER OF INTEGERS

// defining a new struct node with two parts the "data" and pointer to the next node - "link"
struct node
{
    int data;
    struct node* link;
};

//intitializing the "root" pointer variable which is sometimes also referred as the head by some coders
struct node* root = NULL;

//function to initialize as well as append an element to a linked list. Note I combined the "create_list" and "add element" functions into a unified function
void append(int d)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = d;
    temp -> link = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else{
        struct node* p;
        p = root;
        while(p -> link != NULL)
        {
            p = p -> link;
        }
        p -> link = temp;
    }
}
//function to print in the desired formatting & determine the length of our linear linked list
int length_print()
{
    int count= 0 ;
    struct node* temp;
    temp = root;

    while (temp != NULL)
    {
        printf("%d\t", temp -> data);
        if ((count%5) == 4)
        {
            printf("\n");
        }
        count++;
        temp = temp ->link;
    }
    return count;
}

//swapping two data elements from the struct node
void swap(struct node* p1, struct node* p2)
{
    int temp = p1 -> data;
    p1 -> data = p2 -> data;
    p2 -> data = temp;
    return;
}

//bubble sort
void sort_list()
{
    int i, j;
    struct node *p1, *p2;

    for (i=0; i<TOTAL-1; i++)
    {
        p1 = root;
        p2 = p1 -> link;
        for (j=0; j<TOTAL-i-1; j++)
        {
            if (p1 -> data > p2 -> data)
                swap(p1,p2); //calling swap idiom/function
            p1 = p2;
            p2 = p2 -> link;
        }
    }
}

int main()
{
    srand((unsigned)time(0));
    int len = 0;
    for (int i=0; i<TOTAL; i++)
    {
        append(rand()%100);
    }
    printf("Before Sorting:\n");
    len = length_print();
    printf("\n the length of your list is = %d\n\n", len);
    sort_list();
    printf("After Sorting:\n");
    length_print();
    return 0;
}
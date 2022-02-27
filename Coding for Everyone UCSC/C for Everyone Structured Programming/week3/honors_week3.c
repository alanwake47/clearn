/* PROBLEM STATEMENT
Modify the singly linked list to be a doubly linked list.
Now write a routine that removes all duplicate data in the doubly linked list.
The data will be integers generated at random from [0,49]. Initially have a list of 200 elements.  

Now do this in one of two ways. 
Sort the list by its data field.
Remove adjacent elements of the sorted list with the same value.
Or, take the first element—search the remainder of the list for elements with the same data and remove them.
Then take the second element and do the same. Repeat until only one element is left.
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define TOTAL 200

//define double linked list struct type called "node"
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

//initialize the root pointer variable. This is a global variable.
node* root = NULL;

//append a node to a double linked list (works for both initialize and append)
void append(int d)
{
    node* temp;
    temp = (node*)malloc(sizeof(node));
    temp -> data = d;
    temp -> left = NULL;
    temp -> right = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        node* p;
        p = root;
        while (p -> right != NULL)
        {
            p = p -> right;
        }
        p -> right = temp;
        temp -> left = p;
    }
}

//function to print in the desired formatting & determine the length of our linear linked list
int length_print()
{
    int count= 0 ;
    node* temp;
    temp = root; // we create a temp pointer equivalent to root so we dont modify the root header variable.

    while (temp != NULL)
    {
        printf("%d\t", temp -> data);
        if ((count%5) == 4)
        {
            printf("\n");
        }
        count++;
        temp = temp ->right;
    }
    return count;
}

//swapping two data elements from the struct node
void swap(node* p1, node* p2)
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
    node *p1, *p2;

    for (i=0; i<TOTAL-1; i++)
    {
        p1 = root;
        p2 = p1 -> right;
        for (j=0; j<TOTAL-i-1; j++)
        {
            if (p1 -> data > p2 -> data)
                swap(p1,p2); //calling swap function
            p1 = p2;
            p2 = p2 -> right;
        }
    }
}

//function to remove a node in the double linked list. The node to be deleted is identified via the duplicate() function.
void remove_node(node* p)
{
    //if element to be removed is the only element in the list
    if (p -> left == NULL && p -> right == NULL)
    {
        root = NULL;
        p = NULL;
        free(p);
        return;
    }
    //if element to be removed is first element of the list
    else if (p -> left == NULL)
    {
        root = p -> right;
        p -> right -> left = NULL;
        p -> right = NULL;
        free(p);
        return;
    }
    //if element to be removed is last element of the list
    else if (p -> right == NULL)
    {
        p -> left -> right = NULL;
        p -> left = NULL;
        free(p);
        return; 
    }
    else
    {
        p -> left -> right = p -> right;
        p -> right -> left = p -> left;
        p -> right = NULL;
        p -> left  = NULL;
        free(p);
        return;
    }
}
//function to remove duplicates by comparing data between adjacent members of a sorted linked list
void duplicate()
{
    node *p = root;
    while (p -> right != NULL)
    {
        if (p -> data == p -> right -> data)
        {
            remove_node(p -> right); //if the data is equal to next node then remove the next node.
        }
        else
        {
            p = p -> right; //if data between adjacent nodes is different move the pointer one node forward.
        }
    }
}

int main(void)
{
    srand((unsigned)time(0)); //randomizing see of rand() function based on system time
    int i;
    for (i=0; i<TOTAL; i++) //generationg TOTAL = 200 random numbers between [0,49] and appending it to a doubly linked list
    {
        append(rand()%49);
    }
    //priting the list after each function call to see the changes. First the list of 200 elements is printed
    // Then the list is sorted and printed. Finally the list is printed after removal of duplicates
    printf("Before Sorting:\n");
    length_print();
    sort_list();
    printf("\nAfter Sorting:\n");
    length_print(); 
    duplicate();
    printf("\nAfter Removing Duplicates:\n");
    length_print();
    printf("\n\n");
}



/*!
    Pharia Le
    23 February 2022

    Option 1 (General) 
    Use the linear linked list code to store a randomly generated set of 100 integers.  
    Now write a routine that will rearrange the list in sorted order of these values. 
    Note you might want to use bubble sort to do this. Print these values in rows of 5 on the screen.

    How will this work? Compare two adjacent list elements and if they are out of order swap them. 
    After a first pass the largest element will have bubbled to the end of the list. 
    Each pass can look at one less element as the end of a list stays sorted.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Initialize new Node by passing in previous Node pointer (ptr) & data (d)
Node* createNode() {
    Node *nextPtr = malloc(sizeof(Node));
    int rand_data = rand() % 100;
    nextPtr->data = rand_data;
    nextPtr->next = NULL;
    return nextPtr;
}

Node* addNodeToList(Node* prevPtr) {
    Node *nextPtr = createNode();
    prevPtr->next = nextPtr;
    return nextPtr;
}

// Print Node values in rows of 5
void printNodes(Node * ptr) {
    int i = 0;
    while (ptr != NULL) {
        if (i == 5) {
            printf("\n");
            i = 0;
        }
        i++;
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int swap(Node* currentPtr) {
    if (currentPtr->data > currentPtr->next->data) {
        return 1;
    }
    return 0;
}

Node* bubblesort(Node *headPtr, int size) {
    // Referencing current to head
    Node *currentPtr = NULL;
    currentPtr = headPtr;

    // Dummy node pointers
    Node *prevPtr = NULL;
    Node *nextPtr = NULL;
    Node *nextNextPtr = NULL;
    
    // Iterate
    int i, j;
    for (i=0; i<size-1;i++) {
        currentPtr = headPtr;
        for (j=0;j<size-i-1;j++) {
            nextPtr = currentPtr->next;
            nextNextPtr = nextPtr->next;
            if (swap(currentPtr)) {
                nextPtr->next = currentPtr;
                currentPtr->next = nextNextPtr;
                if (j==0) {
                    headPtr = nextPtr;
                }
                if (j!=0) {
                    prevPtr->next = nextPtr;
                } 
                prevPtr = nextPtr;
            } else {
                prevPtr = currentPtr;
                currentPtr = currentPtr->next;
            }
        }
    }
    return headPtr;
}

// Main function
int main(void) {
    // Seed rand()
    srand(time(0));

    // Initialize head pointing to first address Node in the List
    Node *headPtr = NULL;
    Node *currentPtr = NULL;

    // Generate 99 more (100 total) Nodes to link to head Node
    printf("Initialize Linked List:\n");
    int i;
    int size = 100;
    for (i=0; i<size;i++) {
        if (headPtr == NULL) {
            headPtr = createNode();
            currentPtr = headPtr;
        } else {
            Node *nextPtr = addNodeToList(currentPtr);
            currentPtr = nextPtr;
        }
    }

    printNodes(headPtr);
    
    headPtr = bubblesort(headPtr, size);

    printf("\nSorted Linked List:\n");
    
    printNodes(headPtr);

    return 0;
}
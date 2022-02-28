#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

node* root = NULL;

void insert(int d)
{
    //declaring two pointers which are local in nature for the purpose of creating a new node
    node* temp, *p;
    //allocating memory to temp in the form of the node type
    temp = (node*)(malloc(sizeof(node)));
    //assigning data to temp node, i.e. the new node to be inserted. Note the left and right links are NULL at the moment
    temp -> data = d;
    temp -> right = NULL; temp -> left = NULL;
    //allocating root value to parent pointer "p" so that we do not modify the root pointer in further logical operations
    p = root;
    //checking to see if root is pointing to NULL, which would indicate the current node being added is the first node in the BST
    if (root == NULL)
    {
        root = temp;
    }
    //adding node to and existing BST. Note: temp is poiting to the new node to be added
    else
    {
        node* curr = root; //current node same as root pointer so that we do not modify root while traversing the BST
        //while loop will execute until BST doesn't reach end node, i.e. current node being traversed doesnt have NULL as left  || right pointer
        while (curr)
        {
            p = curr;
            //if the data to be intserted is greater than data in the current node we traverse right or vice versa
            if (temp -> data > curr -> data)
            {
                curr = curr -> right;
            }
            else
            {
                curr = curr -> left;
            }
        }
        //after the while loop executes the "curr" node points to NULL and the parent node "p" points to the last node which would be linked to the node to be inserted
        //in the below loop we are checking if the node to be inserted is > || < the last node which would point to it
        if (temp -> data > p -> data)
        {
            p -> right = temp;
        }
        else
        {
            p -> left = temp;
        }
    }
}

void read(FILE *ip, int d[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        fscanf(ip, "%d", &d[i]);
        insert(d[i]);
    }
}

void in_order(node* t)
{
    if (t -> left)
        in_order(t -> left);
    printf("%d -> ", t -> data);
    if (t -> right)
        in_order(t -> right);
    
}


int main()
{
    FILE *ip; //Input and Output files
    int n;

    //opening the file
    ip = fopen("integer.txt", "r");

    //Declaring an array of size n by reading the file till the first element
    if(fscanf(ip, "%d", &n) != 1){
        printf("File empty\n");
        exit(1);
    }
    int d[n];
    //read the file and store into BST
    read(ip, d, n);
    //print the BST in order
    in_order(root);

}




#include<stdio.h>
#include<stdlib.h>



struct Node {
    int data;
    struct Node *link;
};


// Add at end function to add node from scratch to reduce time complexity
struct Node *addNewNodeEnd(struct Node *firstNode, int item)
{
    struct Node *start,*end_node;
    start=firstNode;
    end_node=(struct Node*)malloc(sizeof(struct Node *));
    
    end_node->data=item;
    end_node->link=NULL;

    start->link=end_node;
    return end_node;
}

struct Node * deleteNodeStart(struct Node *Head)
{
    struct Node * start,*temp;
    temp=Head;
    start=Head->link;
    free(temp);
    temp=NULL;
    return start;
}

struct Node * deleteNodeEnd(struct Node *Head)
{
    struct Node * start,*temp;
    temp=Head;
    start=Head->link;

    while(start)
    free(temp);
    temp=NULL;
    return start;
}

struct Node * deleteNodePos(struct Node *Head, int pos)
{
    struct Node * start,*temp;
    temp=Head;
    start=Head->link;
    free(temp);
    temp=NULL;
    return start;
}


int main()
{
    struct Node * start,*ptr;
    start=(struct Node*)malloc(sizeof(struct Node *));
    start->data=10;
    start->link=NULL;
    
    ptr=start;
    ptr=addNewNodeEnd(ptr,20); // returns end Address of node after insertion
    ptr=addNewNodeEnd(ptr,30); 
    ptr=addNewNodeEnd(ptr,40);  
    ptr=start;  // point to start before adding node to start or traversing from start
    
    printf("\nLinked List Before deletion \n");
    //traverse the Linked List 
    while(ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->link;
    }

    ptr=start;
    ptr=deleteNodeStart(ptr);
    
    printf("\nLinked List After deletion \n");

    while(ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->link;
    }

    return 0;
}
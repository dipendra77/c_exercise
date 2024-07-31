#include<stdio.h>
#include<stdlib.h>



struct Node {
    int data;
    struct Node *link;
};


// Add at end function to add node from scratch to reduce time complexity
struct Node *addNewNodeEnd(struct Node *head, int item)
{
    struct Node *start,*newNode;
    start=head;
    newNode=(struct Node*)malloc(sizeof(struct Node *));
    
    newNode->data=item;
    newNode->link=NULL;

    if(start == NULL){ //empty Linked listr
        start=newNode;
    }
    else if(start->link == NULL){  // Linked list with one node
        start->link=newNode;
    }
    else if(start->link != NULL){
        while(start->link){
            start=start->link;
        }
        start->link=newNode;
    }
    
    return head;
}

struct Node * deleteNodeStart(struct Node *head)
{
    struct Node * start,*temp;
    start=head;
    if(start==NULL){
        printf("Linked list is Wmpty!!!!");
    }
    else if(start->link == NULL){    // Linked list with 1 node
        free(start);
        start=NULL;
    }
    else if(start->link!=NULL){
        temp=start;
        start=temp->link;
        free(temp);
        temp=NULL;
    }

    return start;
}

struct Node * deleteNodeEnd(struct Node *Head)
{
    struct Node * start,*temp, *prev;
    
    start = Head;

    while( start!= NULL)
    {
        prev = start;
        start= start->link;
    }
    
    temp = start;
    start = prev;
    free(temp);
    
    return start;
}

struct Node * deleteNodePos(struct Node *Head, int pos)
{
    struct Node * start,*temp;
  
    return start;
}

struct Node *reverseLink(struct Node * head){
    struct Node *start,*current,*prev,*next;
    start=head;
    if( (head==NULL) || (head->link==NULL)){
        printf("Nothing to reverse\n");
        return head;
    }

    prev=NULL;
    next=NULL;
    current=head;
    while(current)
        {   
            next=current->link;
            current->link=prev;
            prev=current;
            current=next;
        }

    return prev;
}

int main()
{
    struct Node *head,*ptr;
    head=(struct Node*)malloc(sizeof(struct Node *));
    head->data=10;
    head->link=NULL;

    head=addNewNodeEnd(head,20); // returns end Address of node after insertion
    head=addNewNodeEnd(head,30); 
    head=addNewNodeEnd(head,40);  
    
    ptr=head;  // point to start before adding node to start or traversing from start
    printf("\nLinked List Before deletion \n");
    //traverse the Linked List 
    while(ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->link;
    }
    
    // head=deleteNodeStart(head);
    // ptr=head;
    // printf("\nLinked List After deletion: ");

    // while(ptr!=NULL)
    // {
    //     printf("%d  ",ptr->data);
    //     ptr=ptr->link;
    // }

    head=reverseLink(head);
    ptr=head;
    printf("\nLinked List After Reversal: ");

    while(ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->link;
    }

    return 0;
}
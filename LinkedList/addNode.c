#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node *link;
};

// TIme Complexity -> O(1) Constant time , No list traversal
struct Node* insertNewNodeStart(struct Node *head, int item)
{
    // struct Node *head;
    struct Node * temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=item;
    // temp->link=NULL;

    temp->link=head;
    head=temp;
    return head;
}

/* 
// Insert node at end

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* endNode;
    SinglyLinkedListNode* newNode;
    endNode=head;
    newNode=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    newNode->data=data;
    newNode->next=NULL;
    
    if(endNode == NULL ){
        head=newNode;
    }
    else if( endNode->next == NULL ){
        endNode->next=newNode;
        
    }
    else if(endNode->next !=NULL ) {
        while(endNode->next !=NULL){
        endNode=endNode->next;
    }
    endNode->next = newNode;
    }

    
    return head;
}

*/
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

// Time coplexity O(n)
struct Node *addNewNodePos(struct Node *head, int item, int addPos)
{
    struct Node *start,*newNode,*prev,*next;
    start=head;
    next=head;
    newNode=(struct Node*)malloc(sizeof(struct Node *));    
    newNode->data=item;
    newNode->link=NULL;
    start=head;
    addPos--;
    if(addPos==0){
        return head;
    }
    else{
        while(addPos){
            prev=next;
            next=next->link;
            addPos--;
        }
        prev->link=newNode;
        newNode->link=next;

    }

    return head;

}



int main()
{
    struct Node * head,*ptr;
    head=(struct Node*)malloc(sizeof(struct Node *));
    head->data=500;
    head->link=NULL;
    head=insertNewNodeStart(head,40);  // Returns start addresss 
    head=insertNewNodeStart(head,30);
    head=insertNewNodeStart(head,20);
    
    head=addNewNodeEnd(head,50); // returns start Address of node after insertion
    head=addNewNodeEnd(head,60); 
    head=addNewNodeEnd(head,70);  
    head=addNewNodePos(head, 100, 2);


    //traverse the Linked List 
    ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr=NULL;

    ptr=head;
    while(ptr != NULL)
    {
        printf("\n%d  ",ptr->data);
        ptr=ptr->link;
        
    }

    return 0;
}
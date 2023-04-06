#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node *link;
};

// TIme Complexity -> O(1) Constant time , No list traversal
struct Node* insertNewNodeStart(struct Node *firstNode, int item)
{
    printf("Insert New node at Start\n");
    struct Node *start,*temp_ptr;
    start=firstNode;
    temp_ptr=(struct Node*)malloc(sizeof(struct Node *));
    temp_ptr->data=item;
    temp_ptr->link=start;
    return temp_ptr;
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

// Time coplexity O(n)
struct Node *addNewNodePos(struct Node *firstNode, int item, int addPos)
{
    struct Node *start,*temp_node,*add_node;
    start=firstNode;
    add_node=(struct Node*)malloc(sizeof(struct Node *));    
    add_node->data=item;
    add_node->link=NULL;
    temp_node=start;
    int pos=0;
    pos++;
    addPos--;
    while(pos!=addPos){
        temp_node=temp_node->link;
        pos++;

    }
    
    add_node->link=temp_node->link; 
    temp_node->link=add_node;

    return start;

}



int main()
{
    struct Node * start,*ptr;
    start=(struct Node*)malloc(sizeof(struct Node *));
    start=NULL;
    // start->data=10;
    // start->link=NULL;
    
    ptr=start;
    ptr=addNewNodeEnd(ptr,20); // returns end Address of node after insertion
    ptr=addNewNodeEnd(ptr,30); 
    ptr=addNewNodeEnd(ptr,40);  
    ptr=start;  // point to start before adding node to start or traversing from start
    ptr=insertNewNodeStart(ptr,40);  // Returns start addresss 
    ptr=insertNewNodeStart(ptr,30);
    ptr=insertNewNodeStart(ptr,20);
    ptr=addNewNodePos(ptr, 100, 4);


    //traverse the Linked List 
    while(ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
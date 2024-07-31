#include <stdlib.h>
#include<stdio.h>


struct Node{
    int data;
    struct Node *link;
};

struct Node *head=NULL;
struct Node *current=NULL;

// int createSingleNode(struct Node* headNode){
        
//         headNode->data=45;
//         headNode->link=NULL;
//     printf("Data: %d\n",headNode->data);
// }

struct Node *createLinkList(struct Node *headNode, struct Node *next)
{
    headNode->data=45;
    headNode->link=NULL;
    
    next->data=34;
    headNode->link=next;
    next=(struct node *)malloc(sizeof(struct Node));
    headNode->link->link=next;
    next->data=50;
    next=(struct node *)malloc(sizeof(struct Node));
    headNode->link->link->link=next;
    next->data=70;
    next->link=NULL;

    printf("Data: First '%d',  Last'%d' \n",headNode->data,next->data);
    return headNode;
}

// Treaverse a linked list and return number of nodes in the Linked list
// Time complexity is O(n) -> Since the loop is running "n" unit times, considering there are "n" items in linked List
int traverseLinkList(struct Node *firstNode)
{
    int count=0;
    if(firstNode==NULL){
        printf("Linked List is empty\n");
    }
    struct Node *ptr=NULL;
    ptr=firstNode;
    // printf("\n%dth Element of link List: %d\n",count,ptr->data);

    while(ptr!=NULL){
        
        printf("\n%dth Element of link List: %d\n",count,ptr->data);
        ptr=ptr->link;
        count++;
        
    }
    printf("\nCount is:%d\n",count);
    return count;
}

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

// Insert into already existing Node : TimeComplexity-> O(n)
void insertNewNodeEnd(struct Node *firstNode, int item)
{
    if(firstNode==NULL)
    {
        printf("Linked List is empty\n");
    }
    struct Node *start,*temp_ptr;
    start=firstNode;
    temp_ptr=(struct Node*)malloc(sizeof(struct Node *));
    temp_ptr->data=item;
    temp_ptr->link=NULL;

    while(start->link!=NULL)
    {
        start=start->link;
    }
    start->link=temp_ptr;
}


/*
void deleteNode(struct Node *firstNode, int item)
{
    if(firstNode==NULL){
        printf("Linked List is empty\n");
    }
    struct Node *ptr=NULL;
    struct Node *prev=NULL;
    ptr=firstNode;
    // printf("\n%dth Element of link List: %d\n",count,ptr->data);

    while(ptr!=NULL){
        prev=ptr;
        ptr=ptr->link;
        if((ptr->data)==item){
            printf("Delete the item from node: %d",item);
            // ptr=ptr->link->link;
        }
    }
}

*/

int main(){
        
        head=(struct Node *)malloc(sizeof(struct Node));
        current=(struct Node*)malloc(sizeof(struct Node));
        struct Node *currNode=(struct Node*)malloc(sizeof(struct Node));
        currNode=createLinkList(head,current);
        printf("First node in Linked list : %d\n",currNode->data);
        int nCount=traverseLinkList(currNode);
        // insertNewNodeEnd(currNode, 10);
        // insertNewNodeEnd(currNode, 20);
        currNode= insertNewNodeStart(currNode, 100);
        currNode= insertNewNodeStart(currNode, 100);

        printf("Linked List after inserting new Node\n");
        traverseLinkList(currNode);
        // printf("")
        return 0;

}
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createnode(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data =val;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

struct node* createDLL(int n){
    struct node* head = NULL;
       struct node* temp = NULL;
       for(int i=0;i<n;i++){
           int num;
           printf("Enter Linkedlist data: ");
           scanf("%d",&num);
           struct node* newnode = createnode(num);
           if(head == NULL){
                   head = newnode;
                   temp=head;        
           }    
           else{
                temp->next=newnode;
                newnode->prev = temp;
                temp = temp->next;     
           } 
       }
       return head;
}


int main(){
    int n;
    printf("Enter Linked list size: ");
    scanf("%d",&n);
    struct node* head = createDLL(n);
    struct node* temp=head;
    struct node* last = head;
    while(last->next!=NULL){
        last = last->next;
    }
    int even=0;
    if(n%2==0){
        even = 1;
    }
    struct node* slow=head;
    struct node* fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(even==1){
        slow = slow->next;
    }
    temp = head;
    while(temp!=slow){
        int val = temp->data;
        temp->data = last->data;
        last->data = val;
        temp=temp->next;
        last=last->prev;
    }

    temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
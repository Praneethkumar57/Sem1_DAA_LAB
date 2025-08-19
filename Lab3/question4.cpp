#include<stdio.h>
#include<stdlib.h>

struct node{
       int data;
       struct node* next;       
};

struct node* createnode(int val){
       struct node* currentnode = (struct node*)malloc(sizeof(struct node));
       currentnode->data = val;
       currentnode->next = NULL;
       return currentnode;     
}

struct node* createLL(int n){
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
                temp = temp->next;     
           } 
       }
       return head;
}



struct node* reverse(struct node* head){
       if(head->next == NULL){
              return head;
       }
       struct node* temp = reverse(head->next);
       head->next->next = head;
       head->next = NULL;
       return temp;
}

int main(){
    int n,i;
    printf("Enter no of elements in Linkedlist1: ");
    scanf("%d",&n);
    struct node* head = createLL(n);
    head = reverse(head);
    printf("Printing linked list after reversal: ");
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
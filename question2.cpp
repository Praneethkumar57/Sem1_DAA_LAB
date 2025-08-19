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
    struct node* head1 = createLL(n);
    printf("Enter no of elements in Linkedlist2: ");
    scanf("%d",&n);
    struct node* head2 = createLL(n);

    head1 = reverse(head1);
    head2 = reverse(head2);

    struct node* temp1 = head1;
    struct node* temp2 = head2;
    int carry =0;
//     while(temp!=NULL){
//        printf("%d ",temp->data);
//        temp=temp->next;
//     }

     // actual code starts from here
     struct node* res=NULL;
     struct node* temp=NULL;

     while(temp1!=NULL && temp2!=NULL){
              int sum = carry+temp1->data+temp2->data;
              int carry = sum/10;
              sum = sum%10;
              struct node* newnode = createnode(sum);
              if(res==NULL){
                     res=newnode;
                     temp = res;
              }
              else{
                     temp->next = newnode;
                     temp = temp->next;
              }
              temp1 = temp1->next;
              temp2 = temp2->next;
     }
     while(temp1!=NULL){
              int sum = carry+temp1->data;
              int carry = sum/10;
              sum = sum%10;
              struct node* newnode = createnode(sum);
              if(res==NULL){
                     res=newnode;
                     temp = res;
              }
              else{
                     temp->next = newnode;
                     temp = temp->next;
              }
              temp1 = temp1->next;
     }
     while(temp2!=NULL){
              int sum = carry+temp2->data;
              int carry = sum/10;
              sum = sum%10;
              struct node* newnode = createnode(sum);
              if(res==NULL){
                     res=newnode;
                     temp = res;
              }
              else{
                     temp->next = newnode;
                     temp = temp->next;
              }
              temp2 = temp2->next;
     }
     res = reverse(res);
     temp = res;
     while(temp!=NULL){
       printf("%d ",temp->data);
       temp=temp->next;
     }
    
}

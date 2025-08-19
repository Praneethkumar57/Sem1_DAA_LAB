#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node* next;
};

struct node* top=NULL;

void push(char c){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = c;
    newnode->next = top;
    top= newnode;
    return;
}

void pop(){
    if(top==NULL){
        printf("Stack underflow");
        return;
    }
    struct node* temp=top;
    top = top->next;
    printf("Popped element:%c",temp->data);
    free(temp);
    return;
}

int main(){
    push('A');
    push('B');
    push('C');
    pop();
}
#include<stdio.h>
#include<stdlib.h>
int mintop=-1;

int push(int val,int n,int top,int stack[],int minstack[]){
    if(top==n){
        printf("Overflow");
        return top;
    }
    stack[++top]=val;
    if(mintop==-1 || val<=minstack[mintop]){
        minstack[++mintop]=val;
    }
    return top;
}

int pop(int top,int stack[],int minstack[]){
    if(top==-1){
        printf("Underflow");
        return top;
    }
    if(minstack[mintop]==stack[top]){
        mintop--;
    }
    printf("Removed element: %d\n", stack[top]);
    top--;
    return top;
}

void topele(int top,int stack[]){
    if(top==-1){
        printf("No elements in stack");
        return;
    }
    printf("%d\n",stack[top]);
    return;
}

void minimum(int minstack[]){
    if(mintop==-1){
        printf("No elements in stack");
        return;
    }
    printf("%d \n",minstack[mintop]);
    return;
}

void show(int n,int stack[]){
    for(int i=0;i<=n;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
    return;
}
int main(){
    int n;
    printf("Enter maximum size of stack:");
    scanf("%d",&n);
    int stack[n];
    int minstack[n];
    int top=-1;
    
    top = push(5,n,top,stack,minstack);
    
    top = push(2,n,top,stack,minstack);
    top = push(10,n,top,stack,minstack);
    show(top,stack);
    topele(top,stack);
    minimum(minstack);
    
    top = pop(top,stack,minstack);
    top = pop(top,stack,minstack);

    topele(top,stack);
    minimum(minstack);

}
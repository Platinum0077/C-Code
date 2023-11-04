//stack using linked list



#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
}*top = NULL;


int isEmpty(){
    if(top == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(int n){
    struct node* new = malloc(sizeof(struct node));
    if(new == NULL){
        printf("Stack Overflow.");
        return;
    }
    new->data = n;
    new->link = top;
    top = new;
}


void traverse(){
    struct node* temp = top;
    if(isEmpty()){
        printf("Stack Underflow.");
        return;
    }
    printf("The Stack is : ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
}

void pop(){
    struct node* temp = top;
    if(isEmpty()){
        printf("Stack Underflow.");
        return;
    }
    top = top->link;
    free(temp);
    temp = NULL;
}

void peek(){
    if(isEmpty()){
        printf("Stack Underflow.");
        return;
    }
    printf("Top Element is : %d",top->data);
}

int main(){

    int choice,data;

    while(1){

        printf("\n  MENU  \n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Print top element\n");
        printf("4.Traverse\n");
        printf("5.Quit\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the Element to enter : ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                traverse();
                break;
            case 5:
                printf("Exiting Program.....\n");
                exit(1);
            default:
                printf("invalid Input\n");
        }
    }

}
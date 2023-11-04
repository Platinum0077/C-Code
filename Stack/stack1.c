//stack using array

//size of stack is defined by define max

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_arr[MAX];
int top = -1;

int isEmpty(){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(){
    if(top == MAX - 1){
        return 1;
    }else{
        return 0;
    }
}

void push(int n){
    if(isFull()){
        printf("Stack Overflow.\n");
        return;
    }
    top = top + 1;
    stack_arr[top] = n;
}

void pop(){
    if(isEmpty()){
        printf("Stack Underflow.\n");
        return;
    }
    top = top - 1;

}

void peek(){
    if(isEmpty()){
        printf("Stack Underflow.\n");
        return;
    }
    printf("the top element is : %d\n",stack_arr[top]);
}


void traverse(){
    if(isEmpty()){
        printf("Stack Underflow.\n");
        return;
    }
    printf("Stack : ");
    for(int i = top ; i >= 0 ; i--){
        printf("%d ",stack_arr[i]);
    }
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
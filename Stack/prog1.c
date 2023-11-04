//wap to implement a stack in an array stack_array[] stack_array[0] as the top element

//there is no need to take care of the top most elementas its fixed , we must take care of the first last element and make sure that it stays ata last


#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_arr[MAX];
int first = -1;

int isEmpty(){
    if(first == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(){
    if(first == MAX - 1){
        return 1;
    }else{
        return 0;
    }
}

void push(int n){
    int i;
    if(isFull()){
        printf("Stack Overflow.\n");
        return;
    }
    first += 1;
    for(i = first ; i > 0 ; i--){
        stack_arr[i] = stack_arr[i-1];
    }
    stack_arr[0] = n;
    

   
}

void pop(){
    if(isEmpty()){
        printf("Stack Underflow.\n");
        return;
    }
    int i;
    for(i = 0; i < first ; i++){
        stack_arr[i] = stack_arr[i+1];
    }
    first -= 1;


}

void peek(){
    if(isEmpty()){
        printf("Stack Underflow.\n");
        return;
    }
    printf("the top element is : %d\n",stack_arr[0]);
}


void traverse(){
    if(isEmpty()){
        printf("Stack Underflow.\n");
        return;
    }
    printf("Stack : ");
    for(int i = 0 ; i <= first ; i++){
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
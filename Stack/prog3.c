//decimal to binary

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack_arr[MAX];
int top = -1;

int isEmpty(){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}

void push(int n){
    
    top = top + 1;
    stack_arr[top] = n;
}

void dtb(int num){
    int i;
    while(num != 0){
        i = num % 2;
        num = num / 2;
        push(i);
    }

}

void traverse(){
    if(isEmpty()){
        printf("No. is Prime\n");
        return;
    }
    printf("Stack : ");
    for(int i = top ; i >= 0 ; i--){
        printf("%d ",stack_arr[i]);
    }
}

int main(){
    int element;
    printf("Enter the Element to enter : ");
    scanf("%d",&element);
    dtb(element);
    traverse();
                
}
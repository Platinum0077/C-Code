//WAP to print all the prime factors of a number in descending order using stack


#include<stdio.h>
#include<stdlib.h>
#define MAX 50

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

void prime_factor(int num){

    int i = 2;
    while(num != 1){
        while(num % i == 0){
            push(i);
            num = num/i;
        }
        i++;
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
    prime_factor(element);
    traverse();
                
}
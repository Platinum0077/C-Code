//check palindrome


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
        exit(1);
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

int pop(){
    struct node* temp = top;
    if(isEmpty()){
        printf("Stack Underflow.");
        exit(1);
    }
    int val = top->data;
    top = top->link;
    free(temp);
    temp = NULL;
    return val;
}

void palindrome_check(char* s){

    int i = 0;
    while(s[i] != 'X'){
        push(s[i]);
        i++;
    }
    i++;
    while(s[i]){
        if(isEmpty() || s[i] != pop()){
            printf("Not Palindrome");
            exit(1);
        }
        i++;
    }
    if(isEmpty()){
        printf("Palindrome");
    }else{
        printf("Palindrome");
    }
}

int main(){

    char s[100];
    printf("Enter the string");
    scanf("%s",s);

    palindrome_check(s);
    return 0;

}
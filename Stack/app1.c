// Nested Brackets

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack_arr[MAX];
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

int pop(){
    if(isEmpty()){
        printf("Stack Underflow.\n");
        exit(1);
    }
    int val = stack_arr[top];
    top = top - 1;
    return val;

}
int match(char a , char b){
    if(a == '[' && b == ']'){
        return 1;
    }
    if(a == '{' && b == '}'){
        return 1;
    }
    if(a == '(' && b == ')'){
        return 1;
    }
    return 0;
}


int check(char* s){

    int i;
    char temp;
    for(i = 0; i < strlen(s) ; i++){
        if(s[i] == '[' || s[i] == '{' || s[i] == '('){
            push(s[i]);
        }
        if(s[i] == ']' || s[i] == '}' || s[i] == ')'){
            if(isEmpty()){
                printf("Right brackets are more than left.");
                return 0;
            }
            else{
                temp = pop();
                if(!match(temp,s[i])){
                    printf("Mismatched Brackets.");
                    return 0;
                }
            }
        }
    } 
    if(isEmpty()){
        printf("Brackets are well balanced.");
        return 1;
    }
    else{
        printf("Left brackets are more than right.");
        return 0;
    }

}


int main(){

    char exp[MAX];
    int balanced;
    printf("Enter algebraic expression : ");
    gets(exp);

    balanced = check(exp);
    if(balanced){
        printf("the expression is valid");
    }else{
        printf("expression is invalid");
    }
    return 0;


}
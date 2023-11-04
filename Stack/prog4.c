//WAP to reverse the elements of the stack using two stacks

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};


int isEmpty(struct node** top){
    if(*top == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(int n,struct node** top){
    struct node* new = malloc(sizeof(struct node));
    if(new == NULL){
        printf("Stack Overflow.");
        exit(1) ;
    }
    new->data = n;
    new->link = *top;
    *top = new;
    
}

int pop(struct node** top){//edited to return the entire deleted node
    struct node* temp = *top;
    if(isEmpty(top)){
        printf("Stack Underflow.");
        exit(1);
    }
    int val;
    val = temp->data;
    *top = (*top)->link;
    free(temp);
    temp = NULL;
    return val;

}

void traverse(struct node** top){
    struct node* temp = *top;
    if(isEmpty(top)){
        printf("Stack Underflow.");
        exit(1);
    }
    printf("The Stack is : ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
}

void reverse_stack(struct node** top){
    struct node* top1 = NULL;
    struct node* top2 = NULL;

    //pushing from stack 1 to stack 2
    while(*top != NULL){
        push(pop(top),&top1);
    }

    //pushing from stack 2 to stack 3
    while(top1 != NULL){
        push(pop(&top1),&top2);
    }

    //pushing from stack 3 to stack 1
    while(top2 != NULL){
        push(pop(&top2),top);
    }
}


int main(){
    
    struct node* top = NULL;
    int choice,data;

    while(1){

        printf("\n  MENU  \n");
        printf("1.Push\n");
        printf("2.Print\n");
        printf("3.Reverse\n");
        printf("4.Quit\n");
        

        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the Element to enter : ");
                scanf("%d",&data);
                push(data,&top);
                break;
            case 2:
                traverse(&top);
                break;
            case 3:
                reverse_stack(&top);
                break;
            case 4:
                printf("Exiting Program.....\n");
                exit(1);
            default:
                printf("invalid Input\n");
        }
    }

     
    
}
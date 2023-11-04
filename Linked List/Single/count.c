#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *create(struct node *head){
    int n , element;
    struct node *new = NULL;
    printf("enter the number of nodes : ");
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++){

        printf("enter element : ");
        scanf("%d",&element);
        new = malloc(sizeof(struct node));
        new->data = element;
        new->link = NULL;

        if(head == NULL){
            head = new;
        }else{
            struct node *temp = head;
            while(temp->link != NULL){
                temp = temp->link;
            }
            temp->link = new;
        }
    }
    return head;
}

void count(struct node *head){

    struct node *temp = head;
    int count = 0;
    if(temp == NULL){
        printf("linked list is empty.\n");
    }
    while(temp != NULL){
        count++;
        temp = temp->link;
    }
    printf("no. of nodes : %d",count);  

}


int main(){
    struct node *head = NULL;
    
    head = create(head);

    count(head);

}
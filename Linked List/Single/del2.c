//delete at the end


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


void delete(struct node *head){
    if (head  == NULL){
        printf("List is already empty.");
    }else if(head->link == NULL){
        free(head);
        head = NULL;
    }else{
        struct node *temp = head;
        while(temp->link->link != NULL){
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
        /*
        second method:

        struct node *temp1 = head;
        struct node *temp2 = head;

        while(temp1->link != NULL){
            temp2 = temp1;
            temp1 = temp1->link; 
        }
        temp2->link = NULL;
        free(temp1);
        temp1 = NULL;

        */

    }
}

void print(struct node *head){
    printf("The linked list is as follows: ");
    if(head == NULL){
        printf("Linked List is Empty.");
    }
    struct node *ptr = head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
}


int main(){
    struct node *head = NULL;
    
    head = create(head);

    delete(head);

    print(head);   

}
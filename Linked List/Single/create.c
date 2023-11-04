#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    
    struct node *head = NULL;
    struct node *new = NULL;
    int n , element ;

    printf("Enter the no. of nodes :");
    scanf("%d",&n);

    struct node* temp = NULL;

    for(int i = 0; i < n ; i++){
        
        printf("Enter the element : ");
        scanf("%d",&element);
        new = malloc(sizeof(struct node));
        new->data = element;
        new->link = NULL;

        if(head == NULL){
            head = new;
            temp = head;//this is an or option
        }
        else{
            /*
            struct node *temp = head;
            while(temp->link != NULL){
                temp = temp->link;
            }
            temp->link=new;
            */
            temp->link = new;
            temp = new;

        }
    }
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
//insert anywhere


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




struct node *insert_beginning(struct node *head,int n){
    
    struct node *new = malloc(sizeof(struct node));
    new->data = n;
    new->link = head;
    head = new;
    return head;

}





struct node* insert(struct node *head){
    int n , pos;
    printf("enter the element to insert at any given position : ");
    scanf("%d",&n);

    printf("enter the position to insert the element : ");
    scanf("%d",&pos);

    if(pos < 1){
        printf("Invalid Position for insertion");
        return head;
    }

    
    if(pos == 1){

        head = insert_beginning(head,n);
        return head;
    } 
    

    struct node *new = malloc(sizeof(struct node));
    new->data = n;

    struct node *temp = head;
    
    int count = 1;

    while(temp != NULL && count < pos - 1){
        temp = temp->link;
        count++;
    }

    new->link = temp->link;
    temp->link = new;
    return head;
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

    head = insert(head);

    print(head);   

}
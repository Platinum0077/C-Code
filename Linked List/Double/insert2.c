// insert at end



#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* create(struct node* head,int n){

    struct node* temp = NULL;

    int element;

    for(int i = 0;i < n ; i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&element);
        struct node* new = malloc(sizeof(struct node));
        new->prev=NULL;
        new->data=element;
        new->next=NULL;

        if(head == NULL){
            head = new;
            temp = head;
        }else{
            temp->next = new;
            new->prev = temp;
            temp = new;
        }


    }
    return head;

}


struct node* insert(struct node* head){

    int element;
    printf("Enter the data to insert : ");
    scanf("%d",&element);


    struct node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    struct node* new = malloc(sizeof(struct node));
    new->prev = temp;
    new->data = element;
    new->next = NULL;
    temp->next = new;

    return head;

}


void print(struct node* head){
    struct node* temp = head;
    printf("The Double Linked List Is : ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}



int main(){

    int size;
    printf("Enter the size of Linked List : ");
    scanf("%d",&size);

    struct node* head = NULL;

    head = create( head,size);

    head = insert(head);

    print(head);


}

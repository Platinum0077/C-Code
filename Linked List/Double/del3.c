// delete anywhere

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


struct node* delete(struct node* head){

    int pos;
    printf("Enter the Position to delete the element from : ");
    scanf("%d",&pos);
    if(pos < 1){
        printf("Invalid Input.");
        return head;
    }else if(pos == 1){
        head = head->next;
        free(head->prev);
        head->prev = NULL;
        return head;
    }else{
        int count = 1;
        struct node* temp = head;
        while(temp != NULL && count < pos){
            temp = temp->next;
            count++;
        }
        struct node* temp2 = temp->prev;
        temp2->next = temp->next;
        if(temp->next!= NULL){
        temp->next->prev = temp2;
        }
        free(temp);
        return head;
    }


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

    head = delete(head);

    print(head);


}

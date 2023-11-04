// insert anywhere



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

    int element,pos;

    printf("Enter the data to insert : ");
    scanf("%d",&element);

    printf("Enter position to insert : ");
    scanf("%d",&pos);

    struct node* new = malloc(sizeof(struct node));
    new->prev = NULL;
    new->next = NULL;

    if(pos < 1){
        printf("Invalid input");
        return head;
    }else if(pos == 1){
        
        new->prev = NULL;
        new->data = element;
        new->next = head;
        head->prev = new;
        head = new;
        return head;
    }else{
        int count = 1;

        new->data = element;

        struct node* temp = head;
        struct node* temp2 = NULL;
        while(temp != NULL && count < pos - 1 ){
            /*here we will use pos-1 as we need to stop just before the place where we need to insert*/
            temp = temp->next;
            count++;
        }
        temp2 = temp->next;

        new->next = temp2;
        temp->next = new;
        new->prev = temp;
        if(temp2 != NULL){
            temp2->prev = new;
        }
               
    }
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

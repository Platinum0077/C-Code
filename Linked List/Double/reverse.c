#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};


struct node* create(struct node* head){
    int n , element;
    struct node* temp = NULL;
    struct node* new = NULL;

    printf("Enter the size of LL : ");
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++){
        printf("Enetr element : ");
        scanf("%d",&element);
        new = malloc(sizeof(struct node));
        new->prev = NULL;
        new->data = element;
        new->next = NULL;

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

void print(struct node* head){
    struct node* ptr = head;
    printf("the double LL is  : ");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

struct node* reverse(struct node* head){
    struct node* ptr1 = head; 
    struct node* ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while(ptr2 != NULL){
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    return head;

}

int main(){

    struct node* head = NULL;

    head = create(head);

    print(head);

    head = reverse(head);

    print(head);

}
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* create(struct node* head){
    int n , element;
    struct node* new = NULL;
    printf("Enter the size of LL : ");
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++){
        printf("Enter the element : ");
        scanf("%d",&element);
        new = malloc(sizeof(struct node));
        new->data = element;
        new->link = NULL;
        if(head == NULL){
            head = new;
        }
        else{
            struct node* temp = head;
            while(temp->link != NULL){
                temp = temp->link;
            }
            temp->link = new;
        }
    }
    return head;
}

void print(struct node* head){
    struct node* ptr = head;
    if(head == NULL){
        printf("The list is empty.");
        exit(1);
    }else{
        printf("The LL is : ");
        while(ptr != NULL){
            printf("%d ",ptr->data);
            ptr = ptr->link;
        }
    }
}


struct node* reverse(struct node* head){
    struct node* temp = NULL;
    struct node* temp2 = NULL;

    while(head != NULL){
        temp2 = head->link;
        head->link = temp;
        temp = head;
        head = temp2;
    }
    head = temp;
    return head;
}

int main(){

    struct node* head = NULL;

    head = create(head);

    print(head);

    head = reverse(head);

    print(head);
}
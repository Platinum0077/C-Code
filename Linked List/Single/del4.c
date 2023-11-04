//delete the entire linked list


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


struct node *delete(struct node *head){
    printf("\nDeleting the linked List\n");
    struct node* temp = head;
    while (temp != NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
    
    
    return head;
}

void print(struct node *head){
    printf("The linked list is as follows:\n ");
    if(head == NULL){
        printf("Linked List is Empty.\n");
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

    print(head);

    head = delete(head);

    print(head);   

}
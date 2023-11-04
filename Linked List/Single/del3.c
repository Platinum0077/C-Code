//delete anywhere


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


struct node* del_big(struct node *head){

    struct node* temp = head;
    head = head->link;
    free(temp);
    temp = NULL;
    return head;

}


struct node* delete(struct node *head){
    int pos;
    printf("Enter the Position:");
    scanf("%d",&pos);
    if (head  == NULL){
        printf("List is already empty.");
    }
    
    if(pos == 1){    
        //delete postion at beginning;

        head = del_big(head);
        return head;

    }
    
    
    struct node *temp1 = head;
    struct node *temp2 = head;
    // while(pos !=1){
    //     temp1 = temp2;
    //     temp2 = temp2->link;
    //     pos--;
    // }

    int count = 0;//or count = 1 and count < pos
    while(temp2 != NULL && count < pos - 1 ){
        temp1 = temp2;
        temp2 = temp2->link;
        count++;
    }
    temp1->link = temp2->link;
    free(temp2);
    temp2 = NULL;
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

    head = delete(head);

    print(head);   

}
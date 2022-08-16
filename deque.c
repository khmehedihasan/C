#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue *next;
};
typedef struct queue node;
node *start = NULL;
node *front = NULL;
node *rear = NULL;

node *getnode(){
    node *newnode;
    newnode = (node *) malloc(sizeof(node));
    printf("\n\nEnter data for node:");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    return(newnode);
}


void enqueue_rear(node *newnode){

    if(newnode == NULL){
        printf("\n\nQueue Full!");
    }else{
        if(start == NULL){

            start = newnode;
            front = newnode;
            rear = newnode;

            printf("\n\n%d: is inserted at rear.",newnode->data);
        }else{
            rear->next = newnode;
            rear = newnode;
            printf("\n\n%d: is inserted at rear.",newnode->data);
        }
    }
}


void enqueue_front(node *newnode){
    if(newnode == NULL){
        printf("\n\nQueue Full!");
    }else{
        if(start == NULL){

            start = newnode;
            front = newnode;
            rear = newnode;

            printf("\n\n%d: is inserted at front.",newnode->data);
        }else{
            front = newnode;
            front->next = start;
            start = newnode;

            printf("\n\n%d: is inserted at front.",newnode->data);
        }
    }
}


void dequeue_front(){
    node *temp;
    if(start == NULL){
        printf("\n\nQueue Empty!");
    }else{
        temp = start;
        start = start->next;
         front = start;
        printf("\n\n%d: is deleted from front.",temp->data);
        free(temp);
    }
}


void dequeue_rear(){
    node *temp;
    node *pre;
    if(start == NULL){
        printf("\n\nQueue Empty!");
    }else{
        temp = start;
        if(temp->next == NULL){
            printf("\n\n%d: is deleted from rear.",temp->data);
            free(temp);
            start = NULL;
            rear = NULL;
        }else{
            while(temp->next != NULL){
                pre = temp;
                temp = temp->next;
            }
            printf("\n\n%d: is deleted from rear.",temp->data);
            pre->next = NULL;
            rear = pre;
            free(temp);
        }

    }
}

void display(){
    node *temp;
    if(start == NULL){
        printf("\n\nQueue Empty!");
    }else{
        temp = start;
        printf("\n\nX->",temp->data);
        while(temp != NULL){
            printf("%d->",temp->data);
            temp = temp->next;
        }
         printf("X\n\n" );
    }
}

void menu(int option){
    node *newnode;
    switch(option){
        case 1:
            newnode = getnode();
            enqueue_front(newnode);
            break;
        case 2:
            newnode = getnode();
            enqueue_rear(newnode);
            break;
        case 3:
            dequeue_front();
            break;
        case 4:
            dequeue_rear();
            break;
        case 5:
            display();
            break;
        default:
            printf("Invalid option!");

    }

}

int main(){
    int option;
    do{
        if(option == 6){
            break;
        }else{
            printf("\n\n1.enqueue front");
            printf("\n\n2.enqueue rear");
            printf("\n\n3.dequeue front");
            printf("\n\n4.dequeue rear");
            printf("\n\n5.display");
            printf("\n\n6.exit");
            printf("\n\nPlease select a option:");
            scanf("%d",&option);
            menu(option);
        }
    }while(1);
return 0;
}

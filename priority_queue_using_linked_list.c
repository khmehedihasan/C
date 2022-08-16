#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    int priority;
    struct queue *next;
};

typedef struct queue node;

node *start = NULL;

node *getnode(){
    node *newnode;
    newnode = (node *) malloc(sizeof(node));
    printf("\n\nEnter data for node:");
    scanf("%d",&newnode->data);
    printf("Enter priority for the node:");
    scanf("%d",&newnode->priority);
    newnode->next = NULL;

    return newnode;

}

void enqueue(node *newnode){
    node *temp;
    if(newnode == NULL){
        printf("Queue Full!");
    }else{
        if(start == NULL){
            start = newnode;
             printf("\n\nInserted\t->Data:%d\n\t\t->Priority:%d", newnode->data, newnode->priority);
        }else{
            temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
            printf("\n\nInserted\t->Data:%d\n\t\t->Priority:%d", newnode->data, newnode->priority);
        }
    }

}

void dequeue(){
    node *temp, *temp2;
    node *pupable;
    node *last, *lastpree;
    int priority;
     if(start == NULL){
        printf("Empty Queue!");
     }else{
         temp = start;
         temp2 = start;
         priority = start->priority;
         pupable = start;

         while(temp != NULL){

            if(temp->priority < priority){
               pupable = temp;
               priority = temp->priority;

            }
            last = temp;
            temp = temp->next;
         }

         if(pupable == start){
            start = start->next;
            printf("\n\nPopped\t->Data:%d\n\t\t->Priority:%d", pupable->data, pupable->priority);
            free(pupable);
         }else{

            if(pupable == last){

                while(temp2->next != NULL){
                    lastpree = temp2;
                    temp2 = temp2->next;
                }
                printf("\n\nPree\t->Data:%d\n\t\t->Priority:%d", pupable->data, pupable->priority);
                lastpree->next = NULL;
                free(pupable);

            }else{
                while(temp2->next != pupable){
                    temp2 = temp2->next;
                }
                printf("\n\nPopped\t->Data:%d\n\t\t->Priority:%d", pupable->data, pupable->priority);
                temp2->next = pupable->next;
                free(pupable);
            }
         }

     }
}

void display(){
    node *temp;
    temp = start;
    if(start == NULL){
         printf("Empty Queue!");
    }else{
         printf("\t\t\t-------------------\n");
         printf("\t\t\t|Data\t|Priority:|\n");
         printf("\t\t\t---------------------\n");
        while(temp != NULL){
            printf("\t\t\t|%d\t|%d\t|\n", temp->data, temp->priority);
            printf("\t\t\t---------------------\n");
            temp = temp->next;
        }
    }

}

void manu(int option){
    node *nnode;
    switch(option){
    case 1:
        nnode = getnode();
        enqueue(nnode);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    default:
        printf("Invalid option!");
    }
}


int main(){

    do{
        int option;
        printf("\n\n1. enquue");
        printf("\n2. dequue");
        printf("\n3. display");
        printf("\n4. exit");
        printf("\n\nSelect a option:");
        scanf("%d",&option);
        printf("\n\n");

        if(option == 4){
            break;
        }else{
            manu(option);
        }
    }while(1);

    return 0;
}

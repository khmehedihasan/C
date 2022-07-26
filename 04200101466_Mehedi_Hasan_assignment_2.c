#include<stdio.h>
#include<stdlib.h>

struct stack{

    int data;
    struct stack *next;

};

typedef struct stack node;

node *start = NULL;
node *top = NULL;
int maxNode = 3;
int countNode = 0;

node* getnode(){
    node* newnode;
    newnode = (node*) malloc(sizeof(node));

    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    return newnode;

}

void push(){
    if(countNode == maxNode){
        printf("\n\n##Stack Overflow!##\n\n");
    }else{
        node *newnode;
        node *temp;
        newnode = getnode();

        if(start == NULL){
            start = newnode;
            top = newnode;
            printf("%d is added.", top->data);
            countNode++;
        }else{
            temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
            top = newnode;
            printf("%d is added.", top->data);
            countNode++;
        }
    }
}

void pop(){
    node *temp;
    if(top == NULL){
        printf("\n\n##Stack Underflow!##\n\n");
    }else{
        temp = start;
        if(start->next == NULL){
            printf("%d is deleted!",start->data);
            start = NULL;
            top = NULL;
            free(temp);
            countNode--;
        }else{
            while(temp->next != NULL){
                top = temp;
                temp = temp->next;
            }
            top->next = NULL;
            printf("%d is deleted!",temp->data);
            free(temp);
            countNode--;

        }
    }
}

void display(){
    node *temp;
    if(start == NULL){
         printf("\n\n##Empty Stack!##\n\n");
    }else{
        temp = start;
        while(temp != NULL){
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("x\n\n");
    }
}


int menu(){
    int option;
    printf("\n\n----Stack using linked list----\n");
    printf("\n\n1.Push");
    printf("\n\n2.Pop");
    printf("\n\n3.Display");
    printf("\n\n4.Exit\n\n");
    printf("\n\nSelect a option:");
    scanf("%d",&option);

    return option;

}

int main(){
    int option;

    do{
        option = menu();

        switch(option){

        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid option!");

        }
    }while(1);


    return 0;
}


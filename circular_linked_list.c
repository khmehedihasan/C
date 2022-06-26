
#include<stdio.h>
#include<stdlib.h>


struct list{
    int data;
    struct list *next;
};

typedef struct list node;

node *createNode(){
     node *newNode;

    printf("\nEnter data for node:");
    newNode = (node*) malloc(sizeof(node));
    scanf("%d",&newNode->data);

    newNode->next = NULL;

    return newNode;

}


node *start = NULL;

void createList(int n){

    node *temp;
    node *newNode;

    for(int i = 0; i < n ; i++){
        newNode = createNode();

        if(start == NULL){
            start = newNode;
        }else{
            temp = start;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    newNode->next = start;


}

void showList(){

    node *temp;

    temp = start;
    int i = 1;
    while(1 && i != 2){
        printf("%d-->", temp->data);
        temp = temp->next;
    if(temp->next == start->next){
         i++;
    }


    }
    printf("%d", temp->data);

}



int main(){


    createList(4);

    showList();

    return 0;
}

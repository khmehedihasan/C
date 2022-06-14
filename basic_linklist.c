#include<stdio.h>
#include<stdlib.h>


struct list{
    int data;
    struct list *next;
};

typedef struct list node;

node *start = NULL;

node *getNode(){
    node* newNode;

    newNode = (node*) malloc(sizeof(node));

    printf("\n Enter data:");

    scanf("%d", &newNode->data);

    newNode->next = NULL;

    return newNode;

}

void createList(int n){
    int i;
    node *newNode;
    node *temp;

    for(i=0; i<n; i++){

        newNode = getNode();

        if(start == NULL){
            start = newNode;
        }else{

            temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }


}

void showList(){
    int i = 1;

    node *lst = start;
    while(lst != NULL){
        printf("\n\nNode: %d --- Value: %d",i, lst->data);
        lst = lst->next;
        i++;
    }
}

int main(){


   // getNode();

    createList(2);

    showList();


    printf("\n\n\n\n");
    scanf("%d");
    return 0;
}

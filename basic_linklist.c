#include<stdio.h>
#include<stdlib.h>

// defining a struct
struct list{
    int data;
    struct list *next;
};

//converting "struct list" into node as data type
typedef struct list node;

//initializing start pointer as node data type
node *start = NULL;

//creating new node
node *getNode(){
    node* newNode;

    //allocating memory as size of node using malloc function
    newNode = (node*) malloc(sizeof(node));

    printf("\n Enter data:");

    scanf("%d", &newNode->data);

    newNode->next = NULL;

    return newNode;

}

//creating linklist
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

//showing linklist
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


    createList(2);

    insert_start();

    showList();


    printf("\n\n\n\n");
    scanf("%d");
    return 0;
}

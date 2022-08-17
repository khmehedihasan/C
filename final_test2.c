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
int max = 3;

node *getnode(){
    node *newnode;
    int flavor;
    newnode = (node *) malloc(sizeof(node));
    printf("\n\n1.Valilla");
    printf("\n\n2.Chocolate");
    printf("\n\n3.Butter");
    printf("\n\nPlease select a flavor:");
    scanf("%d", &flavor);

    if(flavor == 1){
        newnode->data = 1;
    }
    if(flavor == 2){
        newnode->data = 2;
    }
    if(flavor == 3){
        newnode->data = 3;
    }

    newnode->next = NULL;
    return(newnode);
}

int countnode(){
    node *temp;
    int count = 0;
    if(start == NULL){
        return(0);
    }else{
        temp = start;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return(count);
    }
}

void output(int option){
    if(option == 1){
        printf("Vanilla");
    }
    if(option == 2){
        printf("Chocolate");
    }
    if(option == 3){
        printf("Butter");
    }
}


void buy(){
    int count;
    count = countnode();
    if(count == 3){
        printf("\n\nQueue Full!");
    }else{
        node *newnode;
        newnode = getnode();
        printf("\n\n");
        output(newnode->data);
        printf("<-is added in queue\n\n");
        if(start == NULL){
            start = newnode;
            front = newnode;
            rear = newnode;
        }else{
            node *temp;
            temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
            rear = newnode;
        }
    }


}

void serve(){
    if(start == NULL){
        printf("\n\nQueue Empty!");
    }else{
        node *temp;
        int lastserve;

        if(start->next == NULL){
            temp = start;
            printf("\n\nserved->");
            output(temp->data);
            printf("\n\n");
            start = NULL;
            free(temp);
        }else{
            temp = start;
            lastserve = start->data;

            printf("\n\nserved->");
            output(temp->data);
            printf("\n\n");
            start = start->next;
            free(temp);
            while(1){
                if(lastserve != start->data){
                    break;
                }

                if(start->next == NULL){

                    temp = start;
                    lastserve = start->data;

                    printf("\n\nserved->");
                    output(temp->data);
                    printf("\n\n");
                    start = NULL;
                    free(temp);
                    break;
                }else{
                    temp = start;
                    lastserve = start->data;

                    printf("\n\nserved->");
                    output(temp->data);
                    printf("\n\n");
                    start = start->next;
                    free(temp);
                }


            }
        }

    }
}


void display(){
    if(start == NULL){
        printf("\n\nQueue Enpty!");
    }else{
        node *temp;
        temp = start;
        int i = 1;
        printf("\n\n----Queue order---\n ");
        while(temp != NULL){
            printf("%d.", i);
            output(temp->data);
            printf("\n\n");
            i++;
            temp = temp->next;
        }
    }
}

void menu(int option){
    switch(option){
    case 1:
        buy();
        break;
    case 2:
        serve();
        break;
    case 3:
        display();
        break;
    default:
        printf("\n\nInvalid option!");
    }
}


int main(){
    int option;
    while(1){
        if(option == 4){
            return 0;
        }else{
            printf("\n\n1.Buy ice cream");
            printf("\n\n2.Serve ice cream");
            printf("\n\n3.Display queue");
            printf("\n\n4.Exit");
            printf("\n\nPlease select a option:");
            scanf("%d", &option);
            menu(option);
        }

    }


    return 0;
}

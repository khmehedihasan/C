 #include<stdio.h>
 #include<stdlib.h>

 struct list{

    int data;
    struct list *next;

 };

 typedef struct list node;

 node *getNode(int n){

    node *newNode;
    newNode = (node*) malloc(sizeof(node));

    printf("Enter data for node%d:",n);
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    return newNode;

 }

 node *start = NULL;

 void createList( int n){
     node *newNode;
     node *temp;

     for(int i=0; i<n; i++){

        newNode = getNode(i+1);
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

 void insert_start(){
    node *newNode;
    node *temp;
    newNode = getNode(1);

    if(start == NULL){
        start == newNode;
    }else{
        temp = start;
        start = newNode;
        newNode->next = temp;
    }
 }

 void insert_middle(int pos){
    node *newNode;
    node *prev;
    node *temp;

    int i=1;


    newNode = getNode(pos);

    temp = start;
    while(i < pos){
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = newNode;
    newNode->next = temp;

 }

 void insert_end(int n){
    node *newNode;
    node *temp;
    newNode = getNode(n);

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

 void showList(){
    node *temp;
    temp = start;

    while(temp != NULL){
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("X\n\n\n");
 }

  int countNode(){
      int n = 0;
    node *temp;
    temp = start;

    while(temp != NULL){
        temp = temp->next;
        n++;
    }
    return n;
 }

 int main(){
     int n,mod;

     printf("\n\nMy id is 04200101466 and last digit of my id is 6.\n");
     mod= 6%4;
     n= 6+mod;
     printf("6 mod 4 = %d \t in my case number of nodes will be %d.\n\n",mod,n);

     printf("Enter data for %d nodes one by one:\n\n",n);
     createList(n);

     printf("\n\nlinked-list:\t");
     showList();

     int option;
     while(1){
        printf("\n\n\nEnter 1 to delete node form end:\n");
        printf("\nEnter 2 to insert node:\n");
        printf("\nEnter 0 to exit:\n");
        printf("\nOption:");
        scanf("%d",&option);

        if(option == 0){
            break;
        }

        int position,totalNodes;
        totalNodes = countNode();

        switch(option){
        case 1:
            printf("Option 1");

            break;

        case 2:
                printf("\nEnter a position to insert a node:");
                scanf("%d",&position);
                if(position%2 == 0){
                    printf("\nYou can not insert node at even position.Try again...\n");
                }else{
                    if(position <= totalNodes+1){
                        if(position == 1){
                            insert_start();
                            printf("\n\nlinked-list:\t");
                            showList();
                        }else if(position == totalNodes+1){
                           insert_end(position);
                           printf("\n\nlinked-list:\t");
                           showList();
                        }else{
                            insert_middle(position);
                            printf("\n\nlinked-list:\t");
                            showList();
                        }
                    }else{
                        printf("\nThere are %d nodes in this linked list you can only add node at 1 to %d position.\n",totalNodes, totalNodes+1);
                    }
                }
            break;
        default:
            printf("\nInvalid option!\n");
            break;
        }
     }


    //showList();

    return 0;
 }

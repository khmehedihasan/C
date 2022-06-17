 #include<stdio.h>
 #include<stdlib.h>

// defining a struct
 struct list{

    int data;
    struct list *next;

 };

//converting "struct list" into node as data type
 typedef struct list node;

//new node creating function
 node *getNode(int n){

    node *newNode;

//allocating memory as size of node using malloc function
    newNode = (node*) malloc(sizeof(node));

    printf("Enter data for node%d:",n);
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    return newNode;

 }

//initializing NULL to start pointer as node data type
 node *start = NULL;



//creating n number of linked list
 void createList( int n){
     node *newNode;
     node *temp;

     for(int i=0; i<n; i++){

        newNode = getNode(i+1);
        if(start == NULL){
            start = newNode;
        }else{
            temp = start;

            //finding last node
            while(temp->next != NULL){
                temp = temp->next;
            }
            //assigning new node address to  last node's next pointer
            temp->next = newNode;
        }

     }
 }




 //inserting node at first position
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


 // inserting node at required middle position
 void insert_middle(int pos){
    node *newNode;
    node *prev;
    node *temp;

    int i=1;


    newNode = getNode(pos);

    temp = start;

    // finding required middle position previous node
    while(i < pos){
        prev = temp;
        temp = temp->next;
        i++;
    }
    //assigning new node address to  required middle position previous node's next pointer
    prev->next = newNode;
    //assigning required middle position's address to new node's next pointer
    newNode->next = temp;

 }



 // inserting node at last position
 void insert_end(int n){
    node *newNode;
    node *temp;
    newNode = getNode(n);

    if(start == NULL){
        start = newNode;
    }else{
        temp = start;
        // finding last node
        while(temp->next != NULL){
            temp = temp->next;
        }
        //assigning new node address to  last node's next pointer
        temp->next = newNode;
    }


 }


 // deleting node at last position
 void delete_from_last(){

     node *temp;
     node *prev;

     if(start == NULL){
        printf("\nLinked list is empty!\n");
     }else{

        temp = start;
        // finding last node's previous node
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }

        //assigning NULL into last node's previous node's next pointer
        prev->next = NULL;

        //freeing allocated memory space
        free(temp);

        printf("\nLast node deleted\n");
     }

 }




//showing linked list
 void showList(){
    node *temp;
    temp = start;

//traversing until find last node and printing node one by one
    while(temp != NULL){
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("X\n\n\n");
 }




 // getting numbers of node in  linked list
  int countNode(){
      int n = 0;
    node *temp;
    temp = start;

//traversing until find last node and counting node
    while(temp != NULL){
        temp = temp->next;
        n++;
    }
    return n;
 }





 int main(){
     int n,mod;

//giving information to user

     printf("\n\nMy id is 04200101466 and last digit of my id is 6.\n");
     mod= 6%4;
     n= 6+mod;
     printf("6 mod 4 = %d \t in my case number of nodes will be %d.\n\n",mod,n);

//creating n number of linked list
     printf("Enter data for %d nodes one by one:\n\n",n);
     createList(n);

//showing n number of linked list
     printf("\n\nlinked-list:\t");
     showList();

     int option;
     while(1){
//giving some options to user to operate some actions
        printf("\n\n\nEnter 1 to delete node form end:\n");
        printf("\nEnter 2 to insert node:\n");
        printf("\nEnter 0 to exit:\n");
        printf("\nOption:");
//taking options from user
        scanf("%d",&option);

//breaking the infinite loop according to user option
        if(option == 0){
            break;
        }

        int position,totalNodes;
        totalNodes = countNode();

        switch(option){
        case 1:
//deleting last node and showing rest linked list
            delete_from_last();
            printf("\n\nlinked-list:\t");
            showList();
            break;

        case 2:
                //taking position from user to insert node
                printf("\nEnter a position to insert a node:");
                scanf("%d",&position);
                //checking given position is even number or not even number
                if(position%2 == 0){
                    printf("\nYou can not insert node at even position.Try again...\n");
                }else{
                    //checking given position is valid for insertion or not
                    if(position <= totalNodes+1){
                        if(position == 1){
                            //inserting new node to first position and showing new linked list
                            insert_start();
                            printf("\n\nlinked-list:\t");
                            showList();
                        }else if(position == totalNodes+1){
                            //inserting new node to last position and showing new linked list
                           insert_end(position);
                           printf("\n\nlinked-list:\t");
                           showList();
                        }else{
                             //inserting new node to middle position and showing new linked list
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


    return 0;
 }


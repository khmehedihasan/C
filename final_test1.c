#include <stdio.h>
#include <stdlib.h>

struct stack{
	int data;
	struct stack *next;
};

typedef struct stack node;

node *start = NULL;
node *top = NULL;

node *getnode(){

	node *newnode;
	newnode = (node *) malloc(sizeof(node));
	printf("\n\nEnter data for node:");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	return(newnode);

}

void push(node *newnode){
	if(newnode == NULL){
		printf("\n\nStack Overflow!");
	}else{
		if(start == NULL){
			start = newnode;
			top = newnode;
			printf("\n\n%d is pushed",newnode->data);
		}else{
			if(newnode->data % 2 ==0){
				//if even
				if(top->data % 2 == 0){
					// if top & newnode also even
					if(top == start){
						printf("\n\n%d is poped",top->data);
						start = newnode;
						top = newnode;
						printf("\n\n%d is pushed",newnode->data);
						}else{
							node *temp;
							temp = start;
							while(temp->next != top){
								temp = temp->next;
							}
							temp->next = newnode;

							printf("\n\n%d is poped",top->data);
							printf("\n\n%d is pushed",newnode->data);
							free(top);
							top = newnode;
						}
				}else{
					// if top odd & newnode even
					top->next = newnode;
					top = newnode;
					printf("\n\n%d is pushed",newnode->data);
				}
			}else{
				//if odd
				if(top->data % 2 != 0){
					// if top & newnode also odd
					if(top == start){
						printf("\n\n%d is poped",top->data);
						start = newnode;
						top = newnode;
						printf("\n\n%d is pushed",newnode->data);
						}else{
							node *temp;
							temp = start;
							while(temp->next != top){
								temp = temp->next;
							}
							temp->next = newnode;

							printf("\n\n%d is poped",top->data);
							printf("\n\n%d is pushed",newnode->data);
							free(top);
							top = newnode;
						}
				}else{
					// if top even & newnode odd
					top->next = newnode;
					top = newnode;
					printf("\n\n%d is pushed",newnode->data);
				}
			}
		}
	}

}

void display(){
	node *temp;
	if(start == NULL){
		printf("\n\nStack Underflow!");
	}
	temp = start;
	printf("\n\n");
	while(temp != NULL){
		printf("%d->",temp->data);
		temp = temp->next;
	}
}

void menu(int option){
	node *newnode;
	switch(option){
		case 1:
			newnode = getnode();
			push(newnode);
			break;
		case 2:
			display();
			break;
		case 3:
			break;
		default:
			printf("\n\nInvalid option!");
	}
}

int main(){

	int option;

		do{
			if(option == 3){
				return 0;
			}else{
				printf("\n\n1.Push");
				printf("\n\n2.Display");
				printf("\n\n3.Exit");
				printf("\n\nSelect a option:");
				scanf("%d",&option);
				menu(option);
			}
		}while(1);

}


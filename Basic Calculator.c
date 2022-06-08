#include<stdio.h>


void sum(){

    int num1, num2;

    printf("Enter number 1:");

    scanf("%d", &num1);

    printf("Enter number 2:");

    scanf("%d", &num2);

    printf("%d+%d = %d \n\n\n", num1,num2,num1+num2);

}

void sub(){

    int num1, num2;

    printf("Enter number 1:");

    scanf("%d", &num1);

    printf("Enter number 2:");

    scanf("%d", &num2);

    printf("%d-%d = %d \n\n\n", num1,num2,num1-num2);

}

void mult(){

    int num1, num2;

    printf("Enter number 1:");

    scanf("%d", &num1);

    printf("Enter number 2:");

    scanf("%d", &num2);

    printf("%dX%d = %d \n\n\n", num1,num2,num1*num2);

}

void div(){

    int num1, num2;
    float d ;

    printf("Enter number 1:");

    scanf("%d", &num1);

    printf("Enter number 2:");

    scanf("%d", &num2);

    d = num1/num2;


    printf("%d/%d = %f \n\n\n", num1,num2,d);

}

int main(){


    do{

        int operation;

        printf("Select an operation:\n\n");

        printf("For sum enter  1:\n");
        printf("For sub enter  2:\n");
        printf("For mult enter 3:\n");
        printf("For div enter  4:\n\n");

        scanf("%d",&operation);



        switch(operation){

        case 1:
            sum();
            break;
        case 2:
            sub();
            break;
        case 3:
            mult();
            break;
        case 4:
            div();
            break;

        default :
            printf("Wronng");

        }

        int q;

        printf("Enter 0 to quit.\n");
        printf("Enter 1 to calculate again.\n");

        scanf("%d", &q);

        if(q == 0){
            break;
        }

    }while(1);





return 0;
}

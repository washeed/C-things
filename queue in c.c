#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#define MAX 5
/*
makenull(); make empty
enqueue();  add data
dequeue();  remove data
isfull();   checks if full
isempty();  check if empty
display();  display
front();    returns the value of element of the front
rear();     returns value of rear
*/

typedef struct queue{
int head;
int rear;
int count;
int DATA[MAX];
} QUEUE;

QUEUE Q;

void makenull(){
    Q.head=-1;
    Q.rear=0;
    Q.count=0;
}

int isempty(){
return(Q.count==0);
}

int isfull(){
return(Q.count==MAX);
}

void enqueue(int x){
    if (Q.head==-1){Q.head=0;}
    if (isfull()){printf("queue is full"); getch();}
    else{
        Q.DATA[Q.rear]=x;
        printf("The Element in Rear is %d\n",rear());
        Q.rear=(Q.rear+1)%MAX;
        Q.count++;
        system("pause");

        }

}

void dequeue(){

    if (isempty()){printf("queue is empty");}
    else{
            printf("%d is dequeued\n",front());

            Q.head=(Q.head+1)%MAX;
            Q.count--;

        system("pause");
        }

}

void front(){
int x=Q.DATA[Q.head];
return (x);
}

void rear(){
int x=Q.DATA[Q.rear];
return (x);
}

void display(){
int j,i;
if (isempty()){printf("Queue is empty");}
    else
        {
            j=Q.head;
            for (i=0;i<Q.count;i++)
            {
            printf("%d. [%d] %d\n",i+1,j,Q.DATA[j]);
            j=(j+1)%MAX;

            }

        }

}

int main (){
int choice;
int input;
while(1){
system("cls");
printf("1.) Enqueue\n2.) Dequeue\n3.) Display\n4.) Exit\n");
scanf ("%d",&choice);

    switch(choice)
        {
        case 1:
            system("cls");
            printf("input number: ");
            scanf("%d",&input);
            enqueue(input);
            break;
        case 2:
            dequeue();
            system("cls");
            break;
        case 3:
            system("cls");
            display();
            system("pause");
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("1-4 only");
            break;
    }
}
}


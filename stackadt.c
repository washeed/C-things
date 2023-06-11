#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 5
typedef struct stack {
   int S[MAX];
   int top;
}STACK;
STACK S;
void makenull();
void push(int x);
void pop();
int top();
int isfull();
int isempty();
void display();
int menu();

int main(){
int v;
makenull();
while(1){
    system("cls");
    switch(menu()){
    case 1 : system("cls"); printf("Input x: ");scanf("%d",&v);push(v);break;
    case 2 : system("cls"); printf("%d was popped.\n",top());pop();getch();break;
    case 3 : display();break;
    case 4 : exit(0);break;
    default: printf("1-4 only.");getch();
    }

  }
}
void makenull(){
 S.top = MAX;
}
void push(int x){
if (isfull()){
    printf("Stack overflow.");
    getch();
    }
else{
    S.top--;
    S.S[S.top]=x;
  }

}
void pop(){
if (isempty()){
    printf("Stack is empty.");
    getch();
    }
else
    S.top++;
}
int top(){
 if(isempty())
    return -1;
 else
   return(S.S[S.top]);
}
int isfull(){
  return(S.top==0);
}
int isempty(){
  return(S.top==MAX);
}
int menu(){
int op;
system("cls");
printf("Menu\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("\nSelect(1-4): ");
scanf("%d",&op);
return(op);
}
void display(){
int i,j=1;
system("cls");
printf("The Stack contains...\n");
for (i=S.top;i<MAX;i++)
    printf("%d.) %d\n",j++,S.S[i]);
getch();
}

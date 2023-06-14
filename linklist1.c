// C implementation of Linked List of integers
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

/*typedef struct node {
   int id_num;
   char name[31];
   int q1,q2,q3;
   struct node* nxt;
} LIST;*/

typedef struct node {
   int data;
   struct node* nxt;
} LIST;
LIST *L;

void makenull(){
    L = NULL;
}
void insert(int x){
LIST *p, *q, *temp;
p=q=L;

temp = (LIST*) ((malloc(sizeof(LIST))));
temp->data = x;
while (p!=NULL && x>p->data ){
    q=p;
    p=p->nxt;
}
if (p==L)//first element
    L=temp;
else
    q->nxt = temp;
temp->nxt = p;
}
void del (int x){
LIST *p, *q;
p=q=L;
while(p!=NULL && p->data!=x){
    q=p;
    p=p->nxt;
}
if (p==NULL){
    printf("Not found.");
    getch();
}
else{
    if (p==L)//if first element
       L=p->nxt;
    else
       q->nxt=p->nxt;
    free(p);
    }
}
void display(){
LIST *p;
int i = 1;
p=L;
system("cls");
printf("The list contains...\n");
while (p!=NULL){
    printf("%d.) %d\n",i++,p->data);
    p=p->nxt;
 }
 system("pause");
}
int menu(){
int op;
system("cls");
printf("Menu\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Select(1-4): ");
scanf("%d",&op);
return(op);

}
int main(){
int x;
makenull();//initialize the list L
while(1){
    switch(menu()){
    case 1 : system("cls");printf("Insert Mode\n");
             printf("Input x: ");scanf("%d",&x);insert(x);break;
    case 2 : system("cls");printf("Delete Mode\n");
             printf("Input x: ");scanf("%d",&x);del(x);break;
    case 3 : display();break;
    case 4 : exit(0);
    default:printf("1 to 4 only.");getch();
    }
  }
}

//Header Files
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define MAX 100

typedef struct {
char n[31];
int q1;
int q2;
int q3;
} REC;

typedef struct {
REC st[MAX];
int last;
} LIST;

//Global declaration for LIST
LIST L;

//Function Prototypes
void makenull();
void save();
void retrieve();
void insert(char name[31],int quiz1,int quiz2,int quiz3);
void del(char name[31]);
void display();
int isfull();
int isempty();
int locate(char name[31]);

int menu();

int main(){
    makenull();
    retrieve();

    int ans;
    printf("\n\n\tWELCOME TO STUDENT GRADE MANAGEMENT!");
    printf("\n\n\tPress any key to continue...");
    getch();
    system ("cls");
        while (1) {
        ans= menu();
        switch (ans){
        char name [31];
        int quiz1,quiz2,quiz3;

        case 1:
        system ("cls");
        printf ("Insert mode\n");
        printf("\nEnter your name: ");
        scanf(" %[^\n]s",name);
        printf("Please input your score in\n");
        printf("QUIZ 1: ");
        scanf("%d", &quiz1);
        printf("QUIZ 2: ");
        scanf("%d",&quiz2);
        printf("QUIZ 3: ");
        scanf("%d",&quiz3);
        printf("\n");
        insert (name,quiz1,quiz2,quiz3);
        break;

        case 2:
        system ("cls");
        printf ("Delete mode\n");
        display ();
        printf("Enter the student's name: ");
        scanf("%s",name);
        del (name);
        break;

        case 3:
        display ();
        getch() ;
        break;

        case 4:
            save ();
            exit (0);

        default:
        printf("1-4 only."); getch ();
        }
}
}

void makenull()
{
    L.last = -1;}

void insert(char name[31],int quiz1,int quiz2,int quiz3)
{   int i;
        if (isfull ()){
            printf("List is full.");
            getch();
        }
        else{
            L.last++;
               strcpy(L.st[L.last].n, name);
               L.st[L.last].q1 = quiz1;
               L.st[L.last].q2 = quiz2;
               L.st[L.last].q3 = quiz3;}
}

void del(char name[31])
{
    int p;
    if(isempty()){
        printf("List is empty.");
        getch();
    }else{
        p= locate(name);
    if (p<0){
        printf("Not found.");
        getch();
    }else{
        for (int i = p;i<L.last;i++){
        strcpy(L.st[i].n,L.st[i+1].n);
        L.st[i].q1 = L.st[i+1].q1;
        L.st[i].q2 = L.st[i+1].q2;
        L.st[i].q3 = L.st[i+1].q3;
        }
    L.last--;
        }
    }
}
int isfull()
{
    return (L.last == MAX-1);
}

int isempty()
{
    return (L.last == -1);
}

int locate(char name[31]){

    for (int i = 0; i<= L.last; i++)
         if (strcmp(L.st[i].n, name)==0)
                return (i);
    return(-1);
}

void display()
{
    int i;
    float ave;

    system("cls"); //clears our screen
    printf("\tNAME\t\tQUIZ 1\tQUIZ 2\tQUIZ 3\t AVERAGE   REMARKS\n");
    printf("===================================================================\n");
    for(i=0; i<L.last + 1;i++){
    ave =(float)(L.st[i].q1 + L.st[i].q2 + L.st[i].q3)/3;  //calculate the average
    printf(" %d.)\t%s\t\t  %d\t  %d\t %d\t %6.2f\t   %s\n",i+1,L.st[i].n, L.st[i].q1, L.st[i].q2, L.st[i].q3,ave,ave>=75.0 ? "PASSED":"FAILED");}
}

int menu (){
int i, opt;
char *m[] = {"Insert","Delete","Display","Exit"};
system ("cls");
printf("MENU\n");
for (i=0; i<4;i++ )
    printf("%d.) %s\n", i+1, m[i]);
    printf("\n Select (1-4): ");
    scanf(" %d",&opt);
    return (opt);
}

void save (){
FILE *fp;
int i;
float ave;
fp= fopen ("record.dbf", "w+");
for (i=0;i<=L.last;i++)
{
    fprintf(fp,"\n%s\t\t  %d\t  %d\t %d\t",L.st[i].n, L.st[i].q1, L.st[i].q2, L.st[i].q3); // prints the elements of list in the file
}
fclose(fp);
}
void retrieve (){ // function retrieve
//variables
FILE *fp;
//opens file in read and write mode
if ((fp= fopen("record.dbf", "r"))!=NULL){
        for( int i=0; i< MAX; i++){
                if(feof(fp)){
                    break;
                }
             fscanf(fp,"%s %d %d %d\n", L.st[i].n,&L.st[i].q1,&L.st[i].q2,&L.st[i].q3);
             if (strcmp(L.st[i].n, "")!=0){
                L.last++;
             }
            }
        } else {
          fp=fopen ("record.dbf","w");
        }
fclose(fp);
}

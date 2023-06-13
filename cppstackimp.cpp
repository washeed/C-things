#include <iostream>
#define MAX 5

using namespace std;

class MyStack{
private:
    int S[MAX];
    int top;
    bool isfull();
    bool isempty();
public:
    void makenull();
    void push(int x);
    void pop();
    void display();
};
void MyStack::makenull(){
   top = MAX;
}
void MyStack::push(int x){
   if (isfull()){
    cout <<"Stack Overflow.\n";
    system("pause");
   }
   else {
    top--;
    S[top] = x;
   }
}
void MyStack::pop(){
if (isempty()){
    cout <<"Stack is empty.\n";
    system("pause");
}

else {
    top++;
}
}
void MyStack::display(){
int i;
system("cls");
cout <<"The stack contains...\n";
for (i=top;i<MAX;i++){
    cout <<i+1<<".) "<<S[i]<<endl;
}
system("pause");
}
bool MyStack::isfull(){
    return(top==0);
}
bool MyStack::isempty(){
    return (top==MAX);
}
int menu(){
int opt;
system("cls");
cout <<"MENU\n";
cout <<"1. Push\n";
cout <<"2. Pop\n";
cout <<"3. Display\n";
cout <<"4. Exit\n";
cout <<"Select(1-4): ";
cin >> opt;
return(opt);

}

int main(){
int x;
MyStack st;
st.makenull();
while (true){
    switch (menu()){
        case 1: cout <<"Input x to push: "; cin >> x; st.push(x);break;
        case 2: st.pop();break;
        case 3: st.display();break;
        case 4: exit(0);
        default: cout <<"Invalid input.\n";system("pause");
    }
  }
}




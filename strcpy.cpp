#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    string src[5];
    string dest;
    /* Large enough to store content of src */
 for (int i =0;i<3;i++){
   cout<< "input name: ";

   getline(cin,dest);
   //cin >> dest;
     src[i].assign(dest);
 }
 for (int i = 0;i<3;i++)
    cout <<i+1<<".) "<<src[i]<<endl;
 return 0;
 }



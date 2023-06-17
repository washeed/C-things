#include <stdio.h>
#include <string.h>

typedef unsigned char BYTE; // the identifier BYTE can be used as an abbreviation for the type unsigned char
void string2ByteArray(char* input, BYTE* output) // basically a function na nag cconvert ng ascii to BYTE which is naka parameter passing
{
    int loop;
    int i;

    loop = 0;
    i = 0;

    while(input[loop] != '\0')
    {
        output[i++] = input[loop++];
    }
}

int main(){
    FILE* ascii;
    ascii=fopen("ascii.txt","w");// opened it on write file
    fprintf(ascii, "hello");//try changing kasi dito mapapalitan laman nung file
    fclose(ascii);
    ascii=fopen("ascii.txt","r");//then ni open sa read file tho feel ko pwede rb+


    char ascii_str[50];
    while (fgets(ascii_str,50, ascii)!= NULL);//binasa laman ng file then ni save sa array
    int len = strlen(ascii_str);//binibilang laman nung array ko after mabasa para alam kung hanggang saan ipprint
    BYTE arr[len];//used to declare the arr variable in bytes which is unsigned char
    int i;


    string2ByteArray(ascii_str, arr);//called the function

    printf("inside the file is: %s\n", ascii_str); //print na lang from here onwards
    printf("byte array is...\n");
    for(i=0; i<len; i++)
    {
        printf("%c - %d\n", ascii_str[i], arr[i]);
    }
    printf("\n");

    return 0;
}

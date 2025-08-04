#include<stdio.h>
#include<string.h>

int main(){
    char C[6]="Hello";
    char *c1;
    printf("Size of c1 is %d bytes.\n",sizeof(c1)); // 8 bytes
    c1=C; //C is same as &C[0]. We cannot use &C.
    printf("%c\n",c1[1]); //"e"
    c1[0]='A';
    printf("%s",c1);

    return 0;
}
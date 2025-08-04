#include<stdio.h>
#include<string.h> //  important!!

int main(){
    char C[]="Mia and Ting"; 
    printf("Size of C is %d bytes.\n",sizeof(C)); // There is a '\0' in the last to be the end of the string. Ans:13
    int len=strlen(C);
    printf("Length of C is %d.\n",len); // Just calculate the amount of character. Ans:12
    printf("%s\n",C);

    return 0;
}

#include<stdio.h>
#include<string.h>

void print(char *C){
    printf("%s\n",C);

    int i=0;

    while(C[i]!= '\0'){
        printf("%c",*(C+i)); //same as C[i]
        i++;
    }
    printf("\n");
}

int main(){
    char C[6]="Hello";
    print(C); 
    return 0;
}
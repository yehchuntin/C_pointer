#include<stdio.h>
int Add(int a,int b){
    return a+b;
}

void PrintHello(char* name){
    printf("Hello %s\n",name);
}

int main(){
    int (*p)(int,int);
    p=&Add; // same as p=Add;
    int sum=p(3,5);
    printf("%d\n",sum);

    void (*ptr)(char*);
    ptr=PrintHello;
    ptr("Mia");

    return 0;
}
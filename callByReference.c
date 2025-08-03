#include<stdio.h>

void increase(int a){
    a++;
    printf("Address of a in function: %d\n",&a);

}

int main(){
    int a=10;
    printf("Address of a in main: %d\n",&a);
    increase(a);
    printf("%d\n",a); //a still would be 10.

    return 0;
}
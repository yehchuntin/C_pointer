#include<stdio.h>

int sum(int A[]){
    int sum=0;
    int size=sizeof(A)/sizeof(A[0]); 
    //int指標大小（在 64 位元系統通常是 8 bytes）
    printf("In the function,size of A: %d bytes. Size of A[0]: %d bytes\n",sizeof(A),sizeof(A[0]));
    for(int i=0;i<size;i++){
        sum+=A[i];
    }

    return sum;
}

int main(){
    int A[]={1,2,3,4,5};
    printf("In the main,size of A: %d bytes. Size of A[0]: %d bytes\n",sizeof(A),sizeof(A[0]));

    printf("Total of A is %d\n",sum(A));

    return 0;
}
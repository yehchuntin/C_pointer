#include<stdio.h>

int compare(int first,int second){
    if(first>second) return 1;
    else return -1; // 可以更改回傳值邏輯來決定升冪或降冪
}

void BubbleSort(int *A,int size,int (*compare)(int,int)){ // 參數接收 callback function
    int i,j,temp;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-1-i;j++){
            if( (compare(A[j],A[j+1]) > 0) ){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

int main(){
    int A[]={3,2,1,5,6,4};
   
    BubbleSort(A,6,compare); // 傳入函式指標（callback function）
    for(int i=0;i<6;i++) printf("%d ",A[i]);

    return 0;
}
#include<stdio.h>
#include<math.h>

int absolute_compare(int first,int second){
    if(abs(first)>abs(second)) return 1;
    else return -1; // we can change the return value to select increasing order or decreasing order
}

void BubbleSort(int *A,int size,int (*compare)(int,int)){ // remember to put the callback function pointer into arguement
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
    int A[]={-31,22,-1,50,-6,4}; // => {-1 4 -6 22 -31 50}
   
    BubbleSort(A,6,absolute_compare); // here ,we should also add the callback function into the argument
    for(int i=0;i<6;i++) printf("%d ",A[i]);

    return 0;
}
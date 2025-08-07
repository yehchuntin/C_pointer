#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the amount of array:");
    scanf("%d",&n);
    int *A=(int*)malloc(n*sizeof(int)); // 在 heap 配置記憶體

    for(int i=0;i<n;i++){
        A[i]=i+1;
    }
   
    free(A); // 釋放 heap 空間
    A[2]=6;   // ❗仍然修改 A[2]
    // A=NULL; 

    for(int i=0;i<n;i++){  // ❗讀取已釋放記憶體
        printf("%d ",A[i]);
        
    }

    return 0;
}

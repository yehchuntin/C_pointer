#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the amount of array:");
    scanf("%d",&n);
    int *A=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        A[i]=i+1;
    }
    int *B=(int*)realloc(A,(n/2)*sizeof(int)); 
    
    printf("%d\n",A);
    printf("%d\n",B);

    // B=(int*)realloc(A,0); same as free(A)
    // int *B=(int*)realloc(NULL,n*sizeof(int)); same as malloc

    for(int i=0;i<n;i++){ 
        printf("%d ",B[i]);
        
    }

    return 0;
}

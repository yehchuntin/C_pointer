#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the amount of array:");
    scanf("%d",&n);

    // 1️⃣ malloc：先在 Heap 配置 n 個 int
    int *A = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        A[i] = i + 1; // 初始化資料
    }

    // 2️⃣ realloc：嘗試縮小成 n/2 個 int
    int *B = (int*)realloc(A, (n/2) * sizeof(int)); 
    
    printf("%p\n", A); // 原來的位置
    printf("%p\n", B); // realloc 之後的位置

    // 3️⃣ 特殊情況：
    // B = realloc(A, 0);             // 等同 free(A)
    // int *B = realloc(NULL, n * sizeof(int)); // 等同 malloc

    // 4️⃣ 讀取目前的資料（⚠ 注意，縮小後超過的資料不可再用）
    for(int i = 0; i < n; i++){ 
        printf("%d ", B[i]);
    }

    return 0;
}

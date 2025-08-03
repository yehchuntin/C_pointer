#include<stdio.h>

int sum(int* A, int size) { // int *A 同等於 int A[]
    int sum = 0;
    // 這裡的 A 是指標，因此 sizeof(A) 會回傳指標大小（64 位元系統通常為 8 bytes）
    printf("In the function, size of A: %d bytes. Size of A[0]: %d bytes\n",
           sizeof(A), sizeof(A[0]));

    for (int i = 0; i < size; i++) {
        sum += *(A + i); // *(A + i) 等同於 A[i]
    }

    return sum;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};

    // 在 main() 中，A 是陣列，因此 sizeof(A) 會計算整個陣列大小（5 × 4 = 20 bytes）
    printf("In the main, size of A: %d bytes. Size of A[0]: %d bytes\n",
           sizeof(A), sizeof(A[0]));

    // 計算陣列元素個數
    int size = sizeof(A) / sizeof(A[0]); 

    // 將陣列首位址 &A[0] 和大小 size 傳入函式
    printf("Total of A is %d\n", sum(&A[0], size));

    return 0;
}

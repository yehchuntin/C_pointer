#include<stdio.h>

// 函式：計算陣列元素總和
int sum(int A[]) {
    int sum = 0;
    
    // ⚠️ sizeof(A) 這裡的 A 是「指標」，不是完整陣列
    // 因此 sizeof(A) 會回傳指標大小（在 64 位元系統通常是 8 bytes）
    // 而不是陣列的總大小
    int size = sizeof(A) / sizeof(A[0]); 
    
    // 印出在函式內的 A 大小
    printf("In the function, size of A: %d bytes. Size of A[0]: %d bytes\n", sizeof(A), sizeof(A[0]));

    // 用迴圈累加陣列元素
    for (int i = 0; i < size; i++) {
        sum += A[i];
    }

    return sum; // 回傳總和
}

int main() {
    // 宣告並初始化陣列 A
    int A[] = {1, 2, 3, 4, 5};

    // 在 main 中計算陣列大小
    // sizeof(A) → 整個陣列的大小（5 × 4 bytes = 20 bytes）
    // sizeof(A[0]) → 陣列單一元素大小（int = 4 bytes）
    printf("In the main, size of A: %d bytes. Size of A[0]: %d bytes\n", sizeof(A), sizeof(A[0]));

    // 呼叫 sum 函式計算總和並輸出結果
    printf("Total of A is %d\n", sum(A));

    return 0;
}

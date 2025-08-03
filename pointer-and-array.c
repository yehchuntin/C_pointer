#include <stdio.h>

// 函式：顯示陣列所有元素
// 參數：p → 指向陣列開頭的指標
//      size → 陣列大小
void show(int *p, int size) {
    for (int i = 0; i < size; i++) {
        // *(p+i) 等價於 p[i]，透過指標位移存取陣列元素
        printf("%d\t", *(p + i));
    }
}

int main() {
    int A[5] = {2, 4, 7, 6, 9};  // 宣告陣列 A 並初始化
    int *p;                      // 宣告指標 p

    // 方式 1：將 p 指向 A[0] 的位址
    p = &A[0];
    printf("%d\n", p);   // 印出 p (A[0] 的位址)
    printf("%d\n", *p);  // 印出 *p (A[0] 的值)

    printf("\n");

    // 方式 2：直接將 p 指向陣列 A (陣列名稱可當指標)
    p = A;
    printf("%d\n", A);        // 印出 A (陣列的基底位址)
    printf("%d\n", *A);       // 印出 *A (A[0] 的值)
    printf("%d\n", *(A + 1)); // 印出 *(A+1) (A[1] 的值)

    printf("\n");

    // 呼叫 show 函式，透過指標列印陣列所有元素
    show(p, 5);

    return 0;
}

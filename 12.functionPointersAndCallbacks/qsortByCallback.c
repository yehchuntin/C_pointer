#include<stdio.h>   // printf() 用
#include<math.h>    // abs() 等數學函式（這裡其實沒用到）
#include<stdlib.h>  // qsort() 用

// 比較函式，供 qsort 呼叫
// 參數 a, b 是「陣列元素的位址」，型態是 const void*（泛型指標）
// qsort 不知道元素型態，所以用 void*，我們必須自行轉型
int compare(const void* a, const void* b){
    // 1. 先把泛型指標轉成 int*，表示它實際上指向整數
    // 2. 再用 * 取出該位址上的整數值
    int A = *((int*)a);
    int B = *((int*)b);

    // 回傳 A - B
    // qsort 規則：
    // >0 → A 應排在 B 後面
    // <0 → A 應排在 B 前面
    // =0 → A 與 B 視為相等
    return A - B; // 這裡代表升冪排序
}

int main(){
    // 原始陣列
    int A[] = {-31, 22, -1, 50, -6, 4};

    // 呼叫 qsort 進行排序
    // qsort(
    //   陣列起始位址,
    //   陣列元素數量,
    //   單一元素大小（位元組數）,
    //   比較函式指標
    // )
    qsort(A, 6, sizeof(int), compare);

    // 輸出排序後的陣列
    for(int i = 0; i < 6; i++)
        printf("%d ", A[i]);
    // 輸出結果: -31 -6 -1 4 22 50

    return 0;
}

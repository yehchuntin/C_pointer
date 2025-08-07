#include<stdio.h>
#include<stdlib.h>

// 這個函式會透過指標 a、b 來計算總和，並回傳一個堆積區(Heap)的指標
int *addByPointer(int *a,int *b){
    printf("Use the pointer: \n");
    printf("Address of a in func is %p\n",&a); // 參數 a (指標變數) 本身在函式的 Stack frame 位置
    printf("Value's address of a in func is %p\n",a); // a 變數裡的值 → 指向 main() 裡變數 a 的位址

    // 在 Heap 配置一個 int 空間，生命週期不受這個函式結束影響
    int *c = (int*)malloc(sizeof(int));

    // 將 a 與 b 指向的整數相加，結果寫進 Heap 配置的空間
    *c = (*a) + (*b);

    return c; // 回傳 Heap 記憶體的地址，這樣離開函式後仍然可用
}

/*
// 若使用 Stack 區域變數 (如下)，結果會不安全
int *addInStack(int a,int b){
    printf("Address of a in func(upper stack) is %p",&a);
    int c = a + b;       // c 在 Stack 上，函式離開時被釋放
    return &c;           // ❌ 危險：回傳區域變數地址，可能被覆蓋或已失效
}
*/

int main(){
    int a = 2, b = 4;
    printf("Address of a in main is %p\n",&a); // main 裡的變數 a 在 main 的 Stack frame

    // 這裡原本 malloc 的空間馬上被下一行覆蓋掉指標位址 → 第一塊空間會洩漏
    int *ptr = (int*)malloc(sizeof(int));

    // 呼叫 addByPointer()，得到的是 Heap 空間的位址
    ptr = addByPointer(&a, &b);

    // 安全存取：ptr 指向的空間在 Heap，因此函式結束後仍有效
    printf("Sum is %d", *ptr);

    // ⚠ 用完記得 free，否則會造成記憶體洩漏
    free(ptr);

    return 0;
}

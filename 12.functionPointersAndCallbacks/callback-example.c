#include<stdio.h>

void A(){ // 回呼函式 (Callback Function)
    printf("Hello\n");
}

void B(void (*ptr)()){ // 參數是函式指標，指向回傳 void、無參數的函式
    ptr(); // 呼叫 ptr 所指向的函式
}

int main(){
    void (*p)() = A; // 宣告函式指標 p，指向 A（儲存的是 A 的位址）
    B(p);  // 等同於 B(A)，因為 p 和 A 都是函式位址

    return 0;
}

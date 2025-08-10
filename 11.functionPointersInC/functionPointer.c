#include <stdio.h>

// 一個普通的函式，計算兩整數的和
int Add(int a, int b) {
    return a + b;
}

// 一個普通的函式，印出 Hello + 名字
void PrintHello(char* name) {
    printf("Hello %s\n", name);
}

int main() {
    // 宣告一個函式指標 p，可指向「參數為 (int, int)，回傳 int」的函式
    int (*p)(int, int);

    // 將 Add 函式的位址指定給 p
    // &Add 與 Add 寫法等價，都代表函式的起始位址
    p = &Add; // same as p = Add;

    // 使用函式指標呼叫 Add(3,5)，並將回傳值存入 sum
    int sum = p(3, 5); //也可用(*p)(3,5)

    // 印出計算結果
    printf("%d\n", sum);

    // 宣告一個函式指標 ptr，可指向「參數為 (char*)，回傳 void」的函式
    void (*ptr)(char*);

    // 將 PrintHello 函式的位址指定給 ptr
    ptr = PrintHello; //same as ptr = &PrintHello;

    // 使用函式指標呼叫 PrintHello("Mia")
    ptr("Mia");

    return 0;
}

#include <stdio.h>

int main(void) {
    int a = 1025;
    int *p = &a;

    printf("size of integer is %zu bytes\n", sizeof(int));
    printf("Address (p)   = %p,  value (*p)   = %d\n", (void*)p, *p);
    printf("Address (p+1) = %p,  value *(p+1) = %d  // 注意：跨 1 個 int\n",
           (void*)(p + 1), *(p + 1)); // 讀到的是「下一格 int」的值（不可預期）

    // 以 1 byte 為單位檢視 a
    char *p0 = (char*)p; // type casting
    printf("size of char is %zu bytes\n", sizeof(char));
    printf("Address (p0)   = %p, value (*p0)   = %d  // 第 0 個 byte\n", (void*)p0, *p0);
    printf("Address (p0+1) = %p, value *(p0+1) = %d  // 第 1 個 byte\n", (void*)(p0 + 1), *(p0 + 1));

    // 參考：在常見 little-endian 上，1025 的 bytes 通常是：01 04 00 00
    return 0;
}

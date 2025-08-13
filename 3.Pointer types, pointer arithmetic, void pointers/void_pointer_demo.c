#include <stdio.h>

int main(void) {
    int a = 1025;
    int *p = &a;

    printf("size of integer is %zu bytes\n", sizeof(int));
    printf("Address (p) = %p, value (*p) = %d\n", (void*)p, *p);

    // Void pointer — 泛型位址容器，不能直接解參考
    void *p0 = p;
    printf("Address (p0 as void*) = %p\n", p0);

    // 需要轉回具體型別才能解參考
    printf("value via (int*)p0 = %d\n", *(int*)p0);

    // 也可以轉成 char* 逐位元組查看
    printf("first byte via (char*)p0 = %d\n", *(char*)p0);

    return 0;
}

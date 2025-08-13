// pointer_to_pointer_demo.c
#include <stdio.h>

int main(void) {
    int  x = 5;        // 一般整數
    int *p = &x;       // p 指向 x
    *p = 6;            // 透過 p 改 x → x = 6

    int **q = &p;      // q 指向 p
    int ***r = &q;     // r 指向 q

    printf("x     = %d\n", x);
    printf("&x    = %p\n", (void*)&x);

    printf("p     = %p  (should equal &x)\n", (void*)p);
    printf("&p    = %p\n", (void*)&p);
    printf("*p    = %d  (value of x)\n\n", *p);

    printf("q     = %p  (should equal &p)\n", (void*)q);
    printf("&q    = %p\n", (void*)&q);
    printf("*q    = %p  (should equal p)\n", (void*)*q);
    printf("**q   = %d  (value of x via q)\n\n", **q);

    printf("r     = %p  (should equal &q)\n", (void*)r);
    printf("&r    = %p\n", (void*)&r);
    printf("*r    = %p  (should equal q)\n", (void*)*r);
    printf("**r   = %p  (should equal p)\n", (void*)**r);
    printf("***r  = %d  (value of x via r)\n\n", ***r);

    // 透過 r 直接改到 x
    ***r = 10;
    printf("after ***r = 10 -> x = %d\n", x);

    // 透過 q 計算並寫回 x
    **q = *p + 2;  // x = 12
    printf("after **q = *p + 2 -> x = %d\n", x);

    return 0;
}

#include <stdio.h>

int main() {
    int a = 1025; // 二進位 00000000 00000000 00000100 00000001 
    char* p = (char*)&a;

    printf("a = %d (0x%08x)\n", a, a);
    printf("p[0] = 0x%02x, p[1] = 0x%02x, p[2] = 0x%02x, p[3] = 0x%02x\n",
           (unsigned char)p[0], (unsigned char)p[1],
           (unsigned char)p[2], (unsigned char)p[3]);
}

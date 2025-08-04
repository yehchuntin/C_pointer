#include <stdio.h>
#include <string.h>

void print(char *C) {       // 以指標接收字串
    printf("%s\n", C);      // 印出整個字串

    int i = 0;
    while (C[i] != '\0') {  // 逐字元列印
        printf("%c", *(C+i)); // same as C[i]
        i++;
    }
    printf("\n");
}

int main() {
    char C[6] = "Hello";
    print(C);               // 傳入字元陣列 → 自動退化為指標
    return 0;
}

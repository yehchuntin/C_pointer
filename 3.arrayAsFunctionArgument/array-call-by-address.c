#include<stdio.h>
#include<math.h>
void twotimes(int* A, int size) { // int *A 同等於 int A[]
    for (int i = 0; i < size; i++) {
        *(A+i)=pow(*(A+i),2); // *(A + i) 等同於 A[i]
    }
}

void show(int *p, int size) {
    for (int i = 0; i < size; i++) {
        // *(p+i) 等價於 p[i]，透過指標位移存取陣列元素
        printf("%d\t", *(p + i));
    }
}

int main() {
    int A[] = {1, 2, 3, 4, 5};

    // 計算陣列元素個數
    int size = sizeof(A) / sizeof(A[0]); 
    twotimes(&A[0], size);
    show(&A[0],size);
    
    return 0;
}

#include <stdio.h>
#include <math.h>

int compare_normal_asc(int a, int b) {
    return a - b; // 正常值升冪
}

int compare_normal_desc(int a, int b) {
    return b - a; // 正常值降冪
}

int compare_abs_asc(int a, int b) {
    return abs(a) - abs(b); // 絕對值升冪
}

int compare_abs_desc(int a, int b) {
    return abs(b) - abs(a); // 絕對值降冪
}

void BubbleSort(int *A, int size, int (*compare)(int, int)) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (compare(A[j], A[j + 1]) > 0) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main() {
    int A[] = {-31, 22, -1, 50, -6, 4};
    int n = sizeof(A) / sizeof(A[0]);
    int choice;

    printf("選擇排序方式:\n");
    printf("1: 正常值升冪\n");
    printf("2: 正常值降冪\n");
    printf("3: 絕對值升冪\n");
    printf("4: 絕對值降冪\n");
    printf("輸入選項 (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            BubbleSort(A, n, compare_normal_asc);
            break;
        case 2:
            BubbleSort(A, n, compare_normal_desc);
            break;
        case 3:
            BubbleSort(A, n, compare_abs_asc);
            break;
        case 4:
            BubbleSort(A, n, compare_abs_desc);
            break;
        default:
            printf("選項錯誤\n");
            return 1;
    }

    printf("排序結果: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

#include <stdio.h>
#include <math.h>

int compare_normal_asc(int a, int b) {
    return a - b; // ���`�Ȥɾ�
}

int compare_normal_desc(int a, int b) {
    return b - a; // ���`�ȭ���
}

int compare_abs_asc(int a, int b) {
    return abs(a) - abs(b); // ����Ȥɾ�
}

int compare_abs_desc(int a, int b) {
    return abs(b) - abs(a); // ����ȭ���
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

    printf("��ܱƧǤ覡:\n");
    printf("1: ���`�Ȥɾ�\n");
    printf("2: ���`�ȭ���\n");
    printf("3: ����Ȥɾ�\n");
    printf("4: ����ȭ���\n");
    printf("��J�ﶵ (1-4): ");
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
            printf("�ﶵ���~\n");
            return 1;
    }

    printf("�Ƨǵ��G: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

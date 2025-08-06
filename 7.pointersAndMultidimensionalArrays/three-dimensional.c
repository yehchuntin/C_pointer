#include<stdio.h>

void Funcfor1D(int *A){
    for(int i=0;i<3;i++){
        printf("%d ",*(A+i));
    }
    printf("\n");
}

void Funcfor2D(int (*B)[4]){
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            printf("%d ",*(*(B+i)+j));
        }
        printf("\n");
    }
}

void Funcfor3D(int (*C)[2][2]){
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                printf("%d ",*(*(*(C+i)+j)+k));
            }
            printf("\t");
        }
        printf("\n");
    }
}

int main(){
    int A[3]={5,8,9};
    int B[2][4]={{1,3,5,7},
                 {2,4,6,8}
                };
    int C[3][2][2]={{{2,5},{7,9}},
                    {{3,4},{6,1}},
                    {{0,8},{11,13}}};

    printf("%d %d %d %d\n",C, *C, C[0], C[0][0]); //都是第一個元素的位址
    printf("Valule of address(%d) is %d\n",C[0][0]+1,*(C[0][0]+1)); // same as C[0][0][1]
                                        //&C[0][0][1]  C[0][0][1]
    
    printf("1D:\n");
    Funcfor1D(A);
    printf("2D:\n");
    Funcfor2D(B);
    printf("3D:\n");
    Funcfor3D(C);

    return 0;
}
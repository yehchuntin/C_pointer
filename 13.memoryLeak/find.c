#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100;

void Play(int bet){
    // -----------------------------
    // Case 1 : 陣列在 Stack
    // char C[3] = {'K','Q','J'};
    // -----------------------------

    // -----------------------------
    // Case 2 : 陣列在 Heap（動態配置）
    char *C = malloc(10000 * sizeof(char)); // ❗ 未 free 則記憶體會一直佔用
    C[0] = 'K'; C[1] = 'Q'; C[2] = 'J';
    // -----------------------------

    printf("Shuffling ..... \n");
    srand(time(NULL));  // ⚠ 建議只在 main() 呼叫一次

    int i, guess;
    for (i = 0; i < 5; i++) {
        int x = rand() % 3; // 0~2 之間的隨機整數
        int y = rand() % 3; // 0~2 之間的隨機整數
        char temp = C[x];
        C[x] = C[y];
        C[y] = temp;
    }

    printf("Where is the Position of Queen? Guess (1,2,3): ");
    scanf("%d", &guess);

    if (C[guess - 1] == 'Q') {
        cash += bet;
        printf("You're correct. The result is \"%c %c %c\". You remain $%d\n", C[0], C[1], C[2], cash);
    } else {
        cash -= bet;
        printf("You're wrong. The result is \"%c %c %c\". You remain $%d\n", C[0], C[1], C[2], cash);
    }

    // free(C); // Case 2 才需要釋放，否則會造成記憶體洩漏
}

int main(void){
    srand((unsigned)time(NULL)); // ✅ 正確做法：程式啟動時 seed 一次
    int bet;
    while (cash > 0) {
        printf("What's your bet? $");
        scanf("%d", &bet);
        if (bet == 0 || bet > cash) break;
        Play(bet);
        printf("*******************************\n");
    }
    return 0;
}

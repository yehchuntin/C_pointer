#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int cash = 100;

void Play(int bet){
    char C[3] = {'J','Q','K'};
    printf("Shuffling ..... \n");
    srand(time(NULL));
    int i,guess;
    char temp;
    for(i = 0;i < 5 ;i++){
        int x = rand()%3;
        int y = rand()%3;
        temp=C[x];
        C[x]=C[y];
        C[y]=C[temp];
    }
    printf("where is the Poition of Queen? Guess (1,2,3) :");
    scanf("%d",&guess);
    if(C[guess-1] == 'Q'){
        cash+=bet;
        printf("You're correct. The result is %c %c %c. You remain $%d\n",C[0],C[1],C[2],cash);
    }
    else{
        cash-=bet;
        printf("You're wrong. The result is %c %c %c. You remain $%d\n",C[0],C[1],C[2],cash);
    }
}

int main(){
    int bet;
    while(cash > 0){
        printf("What's your bet? $");
        scanf("%d",&bet);
        if(bet == 0 || bet > cash) break;
        Play(bet);
    }

    return 0;
}
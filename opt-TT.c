#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "opt.h"

/* いろんなプロトタイプ宣言をここに書く*/

void backtrack(int i, int *C);

double calThroughput(int i, int j);


int main() {
    /* 変数定義をここに書く */
    int C[NSTA];
    /* この変数に各 STA が最適解で選択している AP の番号を格納 */

    prepare_input();
    printf("Input prepared\n");
    for (int i = 0; i < NSTA; i++) {
    }
    backtrack(0, C);

    /* ここで、最適解を計算する関数を書き、その接続を配列Cに格納するとともに全てのSTAのスループットの和を出力 */
    /*back track*/

    printf("Connections for the throughput: \n");
    for (int i = 0; i < NSTA; i++)
        printf("STA%d -> AP%d\n", i, C[i]);
    exit(0);
}

/*以下は関数定義など */

void backtrack(int i, int *C) {
    if (i == NSTA ) {
    } else {

        provisional = calThroughput(i, 3);

        if (calThroughput(i, 0) >= provisional) {
            C[i] = 0;
            backtrack(i + 1, C);
        } else if (calThroughput(i, 1) >= provisional) {
            C[i] = 1;
            backtrack(i + 1, C);
        } else if (calThroughput(i, 2) >= provisional) {
            C[i] = 2;
            backtrack(i + 1, C);
        } else if (calThroughput(i, 3) >= provisional) {
            C[i] = 3;
            backtrack(i + 1, C);
        }
    }
}

double calThroughput(int i, int j) {
    /*Nを計算*/
    N = sizeof(P[i]);
    /*throughputを計算*/
    throughput[i][j] = (1 - P[i][j]) / N;
    return throughput[i][j];
}

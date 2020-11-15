#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "opt.h"

/* いろんなプロトタイプ宣言をここに書く*/

void backtrack(double P[][NAP], int *C);

int main() {
    /* 変数定義をここに書く */
    int C[NSTA];
    /* この変数に各 STA が最適解で選択している AP の番号を格納 */

    prepare_input();
    printf("Input prepared\n");

    /* ここで、最適解を計算する関数を書き、その接続を配列Cに格納するとともに全てのSTAのスループットの和を出力 */
    /*back track*/
    backtrack(P, C);

    printf("Connections for the throughput: \n");
    for (int i = 0; i < NSTA; i++)
        printf("STA%d -> AP%d\n", i, C[i]);
    exit(0);
}

/*以下は関数定義など */

void backtrack(double P[][NAP], int *C) {
    int j = 0;
    double N = 0;
    int optimal;
    double throughput[NSTA][NAP];

    for (int i = 0; i < NSTA; i++) {
        while (P[i][j] == 0) {/*Nを求める*/
            N++;
            j++;
        }
        j = 0;
        throughput[i][j] = (1 - P[i][j]) / N;

        if (throughput[i][j] < throughput[i][j + 1]) {
            optimal = j + 1;
            j++;
        } else {
            backtrack(P, C);/*再帰*/
        }
        C[i] = optimal;
    }
}



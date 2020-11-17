#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "opt.h"

/* いろんなプロトタイプ宣言をここに書く*/

void backtrack(double P[][NAP], int *C, int next);

int main() {
    /* 変数定義をここに書く */
    int C[NSTA];
    /* この変数に各 STA が最適解で選択している AP の番号を格納 */

    prepare_input();
    printf("Input prepared\n");

    /* ここで、最適解を計算する関数を書き、その接続を配列Cに格納するとともに全てのSTAのスループットの和を出力 */
    /*back track*/
    backtrack(P, C, 0);

    printf("Connections for the throughput: \n");
    for (int i = 0; i < NSTA; i++)
        printf("STA%d -> AP%d\n", i, C[i]);
    exit(0);
}

/*以下は関数定義など */

void backtrack(double P[][NAP], int *C, int next) {
    double N = 0;
    double throughput[NSTA][NAP];

    int temp = 0;
    if (next != 0) {
        temp = next;
    }

    for (int i = 0; i < NSTA; i++) {
        int k;
        while (P[i][k] == 0) {/*Nを求める*/
            N++;
            throughput[i][k] = (1 - P[i][k]);
            k++;
        }
        for (int k = 0; k < N; ++k) {
            throughput[i][k] = throughput[i][k] / N;
        }
    }


    for (int i = 0; i < NSTA; i++) {
        for (int j = temp; j < N; j++) {
            if (throughput[i][j] < throughput[i][j + 1]) {
                C[i] = j + 1;
            } else {
                int next = j;
                backtrack(P, C, next);/*再帰*/
            }
        }

    }

}



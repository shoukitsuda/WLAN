#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "opt.h"

/* いろんなプロトタイプ宣言をここに書く*/

void backtrack(double P[][NAP], int *C, int next);

int countN(double P[][NAP]);

int main() {
    /* 変数定義をここに書く */
    int C[NSTA];
    /* この変数に各 STA が最適解で選択している AP の番号を格納 */

    prepare_input();
    printf("Input prepared\n");

    /* ここで、最適解を計算する関数を書き、その接続を配列Cに格納するとともに全てのSTAのスループットの和を出力 */
    /*back track*/
    printf("a");
    backtrack(P, C, 0);
    printf("b");

    printf("Connections for the throughput: \n");
    for (int i = 0; i < NSTA; i++)
        printf("STA%d -> AP%d\n", i, C[i]);
    exit(0);
}

/*以下は関数定義など */
void backtrack(double P[][NAP], int *C, int next) {
    printf("c");
    double N;
    double throughput[NSTA][NAP];

    int temp = 0;
    if (next != 0) {
        temp = next;
    }

    for (int i = 0; i < NSTA; i++) {
        N = sizeof(P[i]);
        for (int j = temp; j < NAP; j++) {
            throughput[i][j] = (1 - P[i][j]) / N;
        }
        for (int j = temp; j < NAP; j++) {
            if (throughput[i][j] < throughput[i][j + 1]) {
                C[i] = j + 1;
            } else {
                temp += 1;
            }

        }
//        if (i == 1) {
//            exit(0);
//        } else {
//            backtrack(P, C, temp);/*再帰*/
//        }
    }
}

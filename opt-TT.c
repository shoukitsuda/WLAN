#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "opt.h"

/* いろんなプロトタイプ宣言をここに書く*/

void branch(int i, int *C, double sumThroughput);

double calThroughput(int i, int j);

int main() {
    /* 変数定義をここに書く */
    int C[NSTA];

    /* この変数に各 STA が最適解で選択している AP の番号を格納 */
    prepare_input();
    printf("Input prepared\n");

    /* ここで、最適解を計算する関数を書き、その接続を配列Cに格納するとともに全てのSTAのスループットの和を出力 */
    /*back track*/
    branch(0, C, 0);

    printf("Connections for the throughput: \n");
    for (int i = 0; i < NSTA; i++)
        printf("STA%d -> AP%d\n", i, C[i]);
    exit(0);
}

/*以下は関数定義など */
void branch(int i, int *C, double sumThroughput) {
    if (i == NSTA) {
        printf("Sum of Throughput = %lf \n", sumThroughput);
        return;
    } else {
        double provisional = 0.0;

        if (calThroughput(i, 0) >= provisional) {
            C[i] = 0;
            provisional = calThroughput(i, 0);

        }
        if (calThroughput(i, 1) >= provisional) {
            C[i] = 1;
            provisional = calThroughput(i, 1);
        }
        if (calThroughput(i, 2) >= provisional) {
            C[i] = 2;
            provisional = calThroughput(i, 2);
        }
        if (calThroughput(i, 3) >= provisional) {
            C[i] = 3;
        }

        sumThroughput += calThroughput(i, C[i]);
        branch(i + 1, C, sumThroughput);
    }
}

double calThroughput(int i, int j) {
    double throughput = 0.0;
    double PER = P[i][j];
    double N = 0.0;

    for (int k = 0; k < NAP; k++) {
        if (P[k][j] == 0) break;
        N++;
    }

    throughput = (1 - PER) / N;
    return throughput;
}
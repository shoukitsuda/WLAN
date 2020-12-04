#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "opt.h"

/* いろんなプロトタイプ宣言をここに書く*/

void branch(int i, int *C, double sumThroughput, double provisional);

double calThroughput(int i, int j);

int main() {
    /* 変数定義をここに書く */
    int C[NSTA];
    double sumThroughput;
    double provisional;

    /* この変数に各 STA が最適解で選択している AP の番号を格納 */
    prepare_input();
    printf("Input prepared\n");

    /* ここで、最適解を計算する関数を書き、その接続を配列Cに格納するとともに全てのSTAのスループットの和を出力 */
    /*back track*/
    branch(0, C, 0, 0);

    printf("Connections for the throughput: \n");
    for (int i = 0; i < NSTA; i++)
        printf("STA%d -> AP%d\n", i, C[i]);
    exit(0);
}

/*以下は関数定義など */
void branch(int i, int *C, double sumThroughput, double provisional) {
    if (i == NSTA) {
        printf("Sum of Throughput = %lf \n", sumThroughput);
        return;
    } else {
        provisional = calThroughput(i, 3);

        if (calThroughput(i, 0) >= provisional) {
            C[i] = 0;
            sumThroughput += calThroughput(i, 0);
            branch(i + 1, C, sumThroughput, provisional);

        } else if (calThroughput(i, 1) >= provisional) {
            C[i] = 1;
            sumThroughput += calThroughput(i, 1);
            branch(i + 1, C, sumThroughput, provisional);


        } else if (calThroughput(i, 2) >= provisional) {
            C[i] = 2;
            sumThroughput += calThroughput(i, 2);
            branch(i + 1, C, sumThroughput, provisional);

        } else if (calThroughput(i, 3) >= provisional) {
            C[i] = 3;
            sumThroughput += calThroughput(i, 3);
            branch(i + 1, C, sumThroughput, provisional);
        }
    }
}

double calThroughput(int i, int j) {
    double throughput[NSTA][NAP];
    /*Nを計算*/

    N = sizeof(P[i]) / sizeof(double);
    /*throughputを計算*/
    throughput[i][j] = (1 - P[i][j]) / N;
    return throughput[i][j];
}



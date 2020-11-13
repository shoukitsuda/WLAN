#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "opt.h"

/* いろんなプロトタイプ宣言をここに書く*/


main() {
    /* 変数定義をここに書く */
    int C[NSTA];
    /* この変数に各 STA が最適解で選択している AP の番号を格納 */

    prepare_input();
    printf("Input prepered.\n");

    /* ここで、最適解を計算する関数を書き、その接続を配列Cに格納するとともに全てのSTAのスループットの和を出力 */

    printf("Connections for the throughput: \n");
    for (i = 0; i < NSTA; i++)
        printf("STA%d -> AP%d\n", i, C[i]);

    exit(0);
}

/*以下は関数定義など */
/*バックトラック*/
void backtrack(){
    if(終了条件){
        return;
    }
    backtrack();/*再帰*/
}

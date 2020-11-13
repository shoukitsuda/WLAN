#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "opt.h"

#define x_max 30
#define y_max 30

void prepare_input(void);
void prepare_PreT(void);
double get_P(double dist);

typedef struct AccessPoint_SPOT {
  double X, Y;
} AP_SPOT;


void prepare_input(void) {
  extern double P[NSTA][NAP];
  
  AP_SPOT ap_spot[NAP];

  int i,j;
  double k1,k2,distance;
  
  ap_spot[0].X = 25.0;    ap_spot[0].Y = 0.0;
  ap_spot[1].X = 50.0;    ap_spot[1].Y = 25.0;
  ap_spot[2].X = 25.0;    ap_spot[2].Y = 50.0;
  ap_spot[3].X = 0.0;    ap_spot[3].Y = 25.0;
  
  for (i=0; i<NSTA; i++) {
    double x = (double)(lrand48()%(int)(x_max+1));
    double y = (double)(lrand48()%(int)(y_max+1));
    
    for (j=0; j<NAP; j++) {
      //fprintf(stderr, "STA_%d : x=%lf, y=%lf, to AP_%d ", i, x, y, j);
      distance = sqrt(pow((ap_spot[j].X) - x, 2) + pow((ap_spot[j].Y) - y, 2));
      P[i][j] = get_P(distance);
      //      k1=(double )rand()/RAND_MAX;
      //      p[i][j]=modf(k1,&k2);
      //fprintf(stderr,"distance=%lf, PER=%lf\n", distance, P[i][j]);
      if(P[i][j] < 0){
        fprintf(stderr, "The Range of PER is in the wrong\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}



/*高速化のため, 全ての想定スループットの組を前もって計算しておく */

void prepare_PreT(void) {  
  extern double P[NSTA][NAP];
  extern double PreT[NSTA][NAP][NSTA+1];

  int i,j,k;
  
  for (i=0; i<NSTA; i++) {
    for (j=0; j<NAP; j++) {
      for (k=0; k<NSTA+1; k++) {
	PreT[i][j][k]=(1-P[i][j])/k;
      }
    }
  }
}




double get_P(double dist){
  double p[100];
  p[0] = 0;
  p[1] = 0;
  p[2] = 0.00154745529573597;
  p[3] = 0.00137551581843198;
  p[4] = 0.00249312242090771;
  p[5] = 0.00455639614855574;
  p[6] = 0.000171939477303984;
  p[7] = 0.00275103163686385;
  p[8] = 0.00146148555708392;
  p[9] = 0.00318088033012387;
  p[10] = 0.0028370013755159;
  p[11] = 0.00232118294360384;
  p[12] = 0.0079092159559836;
  p[13] = 0.0106602475928473;
  p[14] = 0.0162482806052269;
  p[15] = 0.0205467675378267;
  p[16] = 0.0305192572214581;
  p[17] = 0.0452200825309491;
  p[18] = 0.0587173314993122;
  p[19] = 0.0822730398899588;
  p[20] = 0.103765474552957;
  p[21] = 0.136433975240715;
  p[22] = 0.166179504814305;
  p[23] = 0.195409215955984;
  p[24] = 0.227991746905089;
  p[25] = 0.270288858321871;
  p[26] = 0.306138239339752;
  p[27] = 0.354453232462173;
  p[28] = 0.389099037138927;
  p[29] = 0.436468363136176;
  p[30] = 0.481086657496561;
  p[31] = 0.517279917469051;
  p[32] = 0.564907152682256;
  p[33] = 0.589838376891334;
  p[34] = 0.639614855570839;
  p[35] = 0.678301237964237;
  p[36] = 0.709594222833563;
  p[37] = 0.741059147180193;
  p[38] = 0.760144429160935;
  p[39] = 0.796853507565337;
  p[40] = 0.824621733149931;
  p[41] = 0.84396492434663;
  p[42] = 0.867864511691884;
  p[43] = 0.909645804676754;
  p[44] = 0.918586657496561;
  p[45] = 0.987102246675837;
  p[46] = 0.989423429619441;
  p[47] = 0.999914030261348;
  p[48] = 0.999395919303072;
  p[49] = 0.99973979825768;
  p[50] = 0.99183287482806;
  p[51] = 0.999995414947272;
  p[52] = 0.998538514442916;
  p[53] = 1;
  p[54] = 1;
  p[55] = 1;
  p[56] = 1;
  p[57] = 1;
  p[58] = 1;
  p[59] = 1;
  p[60] = 1;

  return p[(int)dist];
}

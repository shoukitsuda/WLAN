#define NAP 4
#define NSTA 10 
/*各APとSTAについてPERが定義されている*/
/*データは用意されている*/
double P[NSTA][NAP];
double N;
double throughput[NSTA][NAP];
double provisional = 0;


void prepare_input(void);

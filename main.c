#include <stdio.h>
#include "stat.h"

int main() {
    float result_corr_coeffs[FRAME_SIZE];
    float result_lpc_coeffs[FRAME_SIZE];
    float past_coeffs[FRAME_SIZE];
    FILE *fp;
    fp=fopen("LPCResult.txt","w+");
    auto_corr_arr(input_arr,result_corr_coeffs,201,FRAME_SIZE);
    ldr_lpc_coeff(result_corr_coeffs,result_lpc_coeffs,past_coeffs, 201 );
    for(int i = 0;i<FRAME_SIZE;i++) {
        fprintf(fp, "%f\n", result_lpc_coeffs[i]);
    }
    fclose(fp);
    return 0;
}



#include <stdio.h>
#include "stat.h"

int main() {
    int i;
    float result_corr_coeffs[FRAME_SIZE];
    float result_lpc_coeffs[FRAME_SIZE];
    float past_coeffs[FRAME_SIZE];
    auto_corr_arr(input_arr,result_corr_coeffs,201,FRAME_SIZE);
    ldr_lpc_coeff(result_corr_coeffs,result_lpc_coeffs,past_coeffs, 201 );
    for(i=0 ; i < FRAME_SIZE; i++ )
        printf("%f",result_lpc_coeffs[i]);
    return 0;
}





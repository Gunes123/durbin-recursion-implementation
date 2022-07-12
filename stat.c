#include "stat.h"

#define MAX(a,b) \
            (a > b ? a : b )

void auto_corr_arr(const float* arr,float* result,int N,int order)
{
    for (int i = 0; i < order; i++)
    {
        result[i] = auto_corr_coeff(arr,N,i);
    }
}

float auto_corr_coeff(const float* arr,int N,int lag)
{
    float sum = 0;
    if(!arr)
        return 0.0;
    float avg = average(arr, N);
    float var = variance(arr,N);
    for (int i = 0; i < N; i++)
    {
        float diff1 = arr[i] - avg;
        float diff2 = arr[(i + lag) % N] - avg;
        sum = sum + diff1 * diff2;
    }
    float coeff = sum/N;
    if(var > 0.001)
        coeff /= var;
    return coeff;
}
float variance(const float* arr,const int N)
{
    float sum = 0;
    if(!arr)
        return 0.0;
    float avg = average(arr,N);
    for (int i = 0; i < N; i++)
    {
        float diff = arr[i] - avg;
        float sqDiff = diff * diff;
        sum = sum + sqDiff;
    }
    return sum/N;
}

float average(const float* arr,const int N)
{
    float sum = 0;
    if(!arr)
        return 0.0;
    for (int i = 0; i < N; i++)
    {
        sum= sum + arr[i];
    }
    return sum/N;
}

void ldr_lpc_coeff(const float* auto_corr_arr,float* lpc,float* past_coeff,int N){
    int num_coeffs = N-1;

    float energy = auto_corr_arr[0];
    for (int i = 0; i < num_coeffs; i++)
    {
        int j;
        for (j = 0; j < i; j++)
            past_coeff[j] = lpc[j];
        float ref_coef = auto_corr_arr[i + 1];
        for (j = 0; j < i; j++)
            ref_coef -= past_coeff[j] * auto_corr_arr[i - j];
        ref_coef /= energy;
        lpc[i] = ref_coef;
        for (j = 0; j < i; j++)
        {
            lpc[j] = past_coeff[j] - ref_coef * past_coeff[i - j - 1];
        }
        float newError = 1.0 - ref_coef * ref_coef;
        newError = MAX(newError, 0.00001);
        energy *= newError;
    }
}





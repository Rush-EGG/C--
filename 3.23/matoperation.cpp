#include <iostream>
#include "matoperation.hpp"

#ifdef WITH_AVX2
#include <immintrin.h>
#endif

#ifdef WITH_NEON
#include <arm_neon.h>
#endif

#ifdef _OPENMP
#include <omp.h>
#endif

float dotproduct(const float *p1, const float *p2, size_t n){
    float sum = 0.f;
    for(size_t i = 0; i < n; i++){
        sum += (p1[i] * p2[i]);
    }

    return sum;
}

float dotproduct_unloop(const float *p1, const float *p2, size_t n){
    if(n % 8 !=0){
        std::cerr << "The size n must be a multiple of 8." << std::endl;

        return 0.f;
    }

    float sum = 0.f;
    for(size_t i = 0; i < n; i+=8){
        sum += (p1[i] * p2[i]);
        sum += (p1[i+1] * p2[i+1]);
        sum += (p1[i+2] * p2[i+2]);
        sum += (p1[i+3] * p2[i+3]);
        sum += (p1[i+4] * p2[i+4]);
        sum += (p1[i+5] * p2[i+5]);
        sum += (p1[i+6] * p2[i+6]);
        sum += (p1[i+7] * p2[i+7]);
    }

    return sum;
}

float dotproduct_avx2(const float *p1, const float *p2, size_t n){
#ifdef WITH_AVX2
    if(n % 8 !=0){
        std::cerr << "The size n must be a multiple of 8." << std::endl;

        return 0.f;
    }

    float sum[8] = {0};
    // 定义两个256位的寄存器
    __m256 a, b;
    // c寄存器的初始值为全零
    __m256 c = _mm256_setzero_ps();

    for(size_t i = 0; i < n; i+=8){
        // 装载元素
        a = _mm256_load_ps(p1+i);
        b = _mm256_load_ps(p2+i);
        c = _mm256_add_ps(c, _mm256_mul_ps(a, b));
    }
    _mm256_store_ps(sum, c);
    return (sum[0]+sum[1]+sum[2]+sum[3]+sum[4]+sum[5]+sum[6]+sum[7]);
#else
    std::cerr << "AVX2 is not supported" << std::endl;
    return 0.f;
#endif

}

float dotproduct_avx2_omp(const float *p1, const float *p2, size_t n){
#ifdef WITH_AVX2
    if(n % 8 !=0){
        std::cerr << "The size n must be a multiple of 8." << std::endl;

        return 0.f;
    }

    float sum[8] = {0};
    // 定义两个256位的寄存器
    __m256 a, b;
    // c寄存器的初始值为全零
    __m256 c = _mm256_setzero_ps();

    #pragma omp parallel for
    for(size_t i = 0; i < n; i+=8){
        // 装载元素
        a = _mm256_load_ps(p1+i);
        b = _mm256_load_ps(p2+i);
        c = _mm256_add_ps(c, _mm256_mul_ps(a, b));
    }
    _mm256_store_ps(sum, c);
    return (sum[0]+sum[1]+sum[2]+sum[3]+sum[4]+sum[5]+sum[6]+sum[7]);
#else
    std::cerr << "AVX2 is not supported" << std::endl;
    return 0.f;
#endif

}

float dotproduct_neon(const float *p1, const float *p2, size_t n){


    return ;
}

float dotproduct_neon_omp(const float *p1, const float *p2, size_t n){


    return ;
}
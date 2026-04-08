#include<bits/stdc++.h>
#include "rng/rng_base.hpp"
#include "rng/mersenne.hpp"
#include "rng/pcg.hpp"
#include "rng/xor.hpp"

int main(){
    const int num_iterations = 1000000;

    // Benchmark Mersenne Twister
    MersenneTwister mt_rng;
    long long mt_sum = 0;
    mt_rng.seed(12345);
    auto start_mt = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < num_iterations; ++i){
        mt_sum += mt_rng.next();
        // mt_rng.next();
    }
    auto end_mt = std::chrono::high_resolution_clock::now();
    std::cout << "Mersenne Twister sum: " << mt_sum << std::endl;

    std::chrono::duration<double> duration_mt = end_mt - start_mt;
    std::cout << "Mersenne Twister time: " << duration_mt.count() << " seconds" << std::endl;

    // Benchmark PCG
    PCG pcg_rng;
    pcg_rng.seed(67890);
    long long pcg_sum = 0;
    auto start_pcg = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < num_iterations; ++i){
        pcg_sum += pcg_rng.next();
    }
    auto end_pcg = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_pcg = end_pcg - start_pcg;
    std::cout << "PCG sum: " << pcg_sum << std::endl;
    std::cout << "PCG time: " << duration_pcg.count() << " seconds" << std::endl;

    // Benchmark XORShift
    XORShift xor_rng;
    xor_rng.seed(13579);
    long long xor_sum = 0;
    auto start_xor = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < num_iterations; ++i){
        xor_sum += xor_rng.next();
    }
    auto end_xor = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_xor = end_xor - start_xor;
    std::cout << "XORShift sum: " << xor_sum << std::endl;
    std::cout << "XORShift time: " << duration_xor.count() << " seconds" << std::endl;

    std::cout <<"Benchmark Complete" << std::endl;

    return 0;
}
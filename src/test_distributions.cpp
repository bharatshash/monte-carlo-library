#include <iostream>
#include<cmath>
#include <vector>
#include "rng/rng_base.hpp"
#include "rng/mersenne.hpp"
#include "rng/pcg.hpp"
#include "rng/xor.hpp"
#include "distributions/normal.hpp"
#include "distributions/exponential.hpp"

template <typename RNGBase>
bool validate_normal(RNGBase& rng){
    // MersenneTwister rng();
    NormalDistribution<RNGBase> dist(rng,0.0,1.0);
    constexpr int N = 1000000;

    double sum = 0.0;
    // For loop for all samples

    std::vector<double> samples(N);

    for(int i = 0; i < N; ++i){
        samples[i] = dist.next();
        sum += samples[i];
    }

    double mean = sum / N;

    
    double variance_sum = 0.0;

    for(int i = 0; i < N; ++i){
        variance_sum += (samples[i] - mean) * (samples[i] - mean);
    }
    
    double variance = variance_sum / N;

    double mean_tolerance = 0.003; // Adjust as needed
    double variance_tolerance = 0.005; // Adjust as needed

    bool mean_test = std::abs(mean - 0.0) < mean_tolerance;
    bool variance_test = std::abs(variance - 1.0) < variance_tolerance;


    return mean_test && variance_test;

}

template <typename RNGBase>
bool validate_exponential(RNGBase& rng){

    double lambda = 2.0;
    ExponentialDistribution<RNGBase> dist(rng,lambda);
    constexpr int N = 1000000;

    double sum = 0.0;
    std::vector<double> samples(N);

    for(int i = 0; i < N; ++i){
        samples[i] = dist.next();
        sum += samples[i];
    }

    double mean = sum / N;

    
    double variance_sum = 0.0;

    for(int i = 0; i < N; ++i){
        variance_sum += (samples[i] - mean) * (samples[i] - mean);
    }
    
    double variance = variance_sum / N;

    double mean_tolerance = 0.003; // Adjust as needed
    double variance_tolerance = 0.005; // Adjust as needed

    double expected_mean = 1.0 / lambda;
    double expected_variance = 1.0 / (lambda * lambda);

    bool mean_test = std::abs(mean - expected_mean) < mean_tolerance;
    bool variance_test = std::abs(variance - expected_variance) < variance_tolerance;

    return mean_test && variance_test;
}

int main() {

    MersenneTwister rng;
    bool normal_ok      = validate_normal(rng);
    bool exponential_ok = validate_exponential(rng);

    std::cout << "\nOverall: " << ((normal_ok && exponential_ok) ? "ALL PASS" : "SOME FAILED") << "\n";

    return (normal_ok && exponential_ok) ? 0 : 1;
}
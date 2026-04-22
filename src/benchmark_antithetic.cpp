#include <iostream>
#include<cmath>
#include <vector>
#include "rng/rng_base.hpp"
#include "rng/mersenne.hpp"
#include "rng/pcg.hpp"
#include "rng/xor.hpp"
#include "distributions/normal.hpp"
#include "distributions/exponential.hpp"
#include "simulations/pi_estimator.hpp"
#include <fstream>

int  main(){
    MersenneTwister rng;
    PiEstimator<MersenneTwister> estimator(rng);

    std::ofstream output_file("results/pi_estimations_antithetic.csv", std::ios::out|std::ios::app);

    output_file << "Sample Size,Estimated PI,Absolute Error\n";
    std::vector<int> sample_sizes = {100, 316, 1000, 3162, 10000, 31623, 100000, 316228, 1000000};
    for(int n : sample_sizes){
        double pi_estimate = estimator.estimate_pi(n);
        std::cout << "Estimated PI with " << n << " samples: " << pi_estimate << std::endl;
        output_file << n << "," << pi_estimate <<","<<abs(pi_estimate - PI)<<"\n";

    }
    output_file.close();
}
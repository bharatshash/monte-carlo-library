#include<bits/stdc++.h>
#include "rng/rng_base.hpp"
#include "rng/mersenne.hpp"
#include "rng/pcg.hpp"

int main(){
    // MersenneTwister rng;
    // rng.seed(12345);
    // std::cout << "Generating 10 random numbers using Mersenne Twister:" << std::endl;
    // for(int i = 0; i < 10; ++i){
    //     std::cout << rng.next() << std::endl;
    // }

    std::cout << "Generating 10 random numbers using PCG:" << std::endl;
    PCG pcg_rng;
    pcg_rng.seed(67890);
    for(int i = 0; i < 10; ++i){
        std::cout << pcg_rng.next() << std::endl;
    }
    return 0;
}
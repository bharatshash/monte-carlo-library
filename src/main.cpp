#include<bits/stdc++.h>
#include "rng/rng_base.hpp"
#include "rng/mersenne.hpp"

int main(){
    MersenneTwister rng;
    rng.seed(12345);
    for(int i = 0; i < 10; ++i){
        std::cout << rng.next() << std::endl;
    }
    return 0;
}
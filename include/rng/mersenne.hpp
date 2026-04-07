#ifndef MERSENNE_HPP
#define MERSENNE_HPP
#include "rng_base.hpp"
#include <random>

class MersenneTwister : public RNGBase{
    public: 
        MersenneTwister(uint64_t seed = std::random_device{}()) : engine_(seed), dist_(0.0, 1.0) {
        }

        ~MersenneTwister() = default;

    
        double next() override{
            return dist_(engine_);
        }
        void seed(uint64_t seed) override{
            engine_.seed(seed);
        }

    private:
        std::mt19937_64 engine_;
        std::uniform_real_distribution<double> dist_;

};

#endif // MERSENNE_HPP
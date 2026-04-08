#ifndef PCG_HPP
#define PCG_HPP
#include "rng_base.hpp"
#include <random>

class PCG: public RNGBase{
    public:
        PCG(uint64_t seed = std::random_device{}()) {
            this->seed (seed);
        }

        ~PCG() = default;

        double next() override{
            uint64_t multiplier = 6364136223846793005ULL;
            uint64_t increment = 1442695040888963407ULL;
            state_ = state_ * multiplier + increment;

            uint32_t output = state_ >> (29 - (state_ >> 59));

            return output / static_cast<double>(UINT32_MAX);

        }
        void seed(uint64_t seed) override{
            if(seed ==0){
                seed = 1; // Avoid zero state
            }
            state_  = 0;
            state_ += seed;
        }

    private:
    uint64_t state_;
    uint64_t inc_;
    std::uniform_real_distribution<double> dist_;
        
};
#endif // PCG_HPP
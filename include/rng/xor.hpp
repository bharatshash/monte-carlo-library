#ifndef XOR_HPP
#define XOR_HPP
#include "rng_base.hpp"

class XORShift : public RNGBase {
    private:
        uint64_t state_;
    public:
        XORShift(uint64_t seed = 88172645463325252ULL) {
            this->seed(seed);
        }
        ~XORShift() = default;

        double next() override {
            uint64_t x = state_;
            x ^= x << 13;
            x ^= x >> 7;
            x ^= x << 17;
            state_ = x;
            return static_cast<double>(x) / static_cast<double>(UINT64_MAX);
        }
        void seed(uint64_t seed) override {
            if (seed == 0) {
                seed = 88172645463325252ULL; // Default non-zero seed
            }
            state_ = seed;
        }

};

#endif // XOR_HPP
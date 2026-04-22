#ifndef ANTITHETIC_HPP
#define ANTITHETIC_HPP
#include "rng/rng_base.hpp"


template <typename RNGBase>
class Antithetic{

    public:
    Antithetic(RNGBase& rng) : rng_(rng), use_cached_(false), cached_value_(0.0) {}

    ~Antithetic() = default;

    double next(){
        if(use_cached_){
            use_cached_ = false;
            return cached_value_;
        } else {
            double value = rng_.next();
            cached_value_ = 1.0 - value; // Assuming the original RNG generates values in [0, 1]
            use_cached_ = true;
            return value;
        }
    }

    private: 
    RNG &rng_;
    bool use_cached_;
    double cached_value_;
};
#ifndef EXPONENTIAL_DISTRIBUTION_HPP
#define EXPONENTIAL_DISTRIBUTION_HPP
#include "rng/rng_base.hpp"
#include <cmath>

template <typename RNGBase>
class ExponentialDistribution{
    private:
        RNGBase &rng;
        double lambda;

    public:
        ExponentialDistribution(RNGBase &rng, double lambda = 1.0) : rng(rng), lambda(lambda) {}

        ~ExponentialDistribution() = default;

        double next(){
            double u;
            do{
                u = rng.next();
            }while(u <= 0.0); // Avoid log(0)
            return -log(u) / lambda;
        }
};

#endif // EXPONENTIAL_DISTRIBUTION_HPP
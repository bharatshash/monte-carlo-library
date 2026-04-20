#ifndef NORMAL_DISTRIBUTION_HPP
#define NORMAL_DISTRIBUTION_HPP
#include "rng/rng_base.hpp"
#include <cmath>
#include <cstdlib>
#include <math.h>


constexpr double PI = 3.14159265358979323846;


template <typename RNGBase>
class NormalDistribution{
    private:
    
    RNGBase &rng;
    double mean;
    double stddev;
    bool hasSpare;
    double spare;

    public:

    NormalDistribution(RNGBase &rng, double mean = 0.0, double stddev = 1.0) : rng(rng), mean(mean), stddev(stddev), hasSpare(false) {}

    ~NormalDistribution() = default;

    double next(){
        if(hasSpare){
            hasSpare = false;
            return spare * stddev + mean;
        }
        double u, v, s;

        do{
            u = rng.next();
        }while(u == 0.0); // Avoid log(0)
        v = rng.next();

        double mag = sqrt(-2.0 * log(u));
        double ange = 2.0 * PI * v;

        double z0 = mag * cos(ange);
        double z1 = mag * sin(ange);
        spare = z1;
        hasSpare = true;

        return z0 * stddev + mean;

    }


};


#endif // NORMAL_DISTRIBUTION_HPP

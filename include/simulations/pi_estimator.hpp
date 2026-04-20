#ifndef PI_ESTIMATOR_HPP
#define PI_ESTIMATOR_HPP
#include "rng/rng_base.hpp"


template <typename RNGBase>
class PiEstimator{
    public:
    //Estimate values of PI by taking N pair samples and using the ratio of points inside the unit circle to total points to estimate PI.
    PiEstimator(RNGBase& rng) : rng_(rng) {}


    //Take N as a parameter and return the estimated value of PI.
    double estimate_pi(int n){
        int inside_circle = 0;

        // NormalDistribution<RNGBase> dist(rng_,0.0,1.0);

        for(int i =0;i<n;i++){
            double x = rng_.next();
            double y = rng_.next();

            if(x*x + y*y <= 1.0){
                inside_circle++;
            }
        }
        return 4.0 * inside_circle / n;

    }

    private:
    RNGBase& rng_;
};

#endif // PI_ESTIMATOR_HPP
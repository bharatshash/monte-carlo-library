#ifndef RNG_BASE_HPP
#define RNG_BASE_HPP
#include<cstdint>

class RNGBase{
    public:
        virtual ~RNGBase() = default;
        virtual double next() = 0;
        virtual void seed(uint64_t s) = 0;
};


#endif // RNG_BASE_HPP
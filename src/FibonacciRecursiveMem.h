
#pragma once
#include "FiboBase.h"

struct FibonacciRecursiveMem: FiboBase
{	    
	std::unique_ptr<ITask> Clone() override
 	{
	    return std::make_unique<FibonacciRecursiveMem>();
	}

 private:
    
    mpz_class FibonacciImpl(std::size_t N) override
    {
        if(!N)
        {
            return 0;
        }

  	if(N <= 2)
        {
            return 1;
        }

        v.resize(N);
        v[0] = 1;
        v[1] = 1;

        return RecursiveFibonacci(N);
    }


    mpz_class RecursiveFibonacci(std::size_t member)
    {
        auto index = member - 1;

            if (v[index] == 0) 
	    {
                v[index] = RecursiveFibonacci(member - 1) + RecursiveFibonacci(member - 2);
            }

        return v[index];
    }

 	std::vector<mpz_class> v;
};



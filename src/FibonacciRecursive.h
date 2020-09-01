
#pragma once
#include "FiboBase.h"

struct FibonacciRecursive: FiboBase
{   
    std::unique_ptr<ITask> Clone() override
    {
    
    	return std::make_unique<FibonacciRecursive>();
    }
    
private:

    mpz_class FibonacciImpl(std::size_t N) override
    {
	if(N <= 2)
	{
		return 1;
	}
	else
	{
		return FibonacciImpl(N - 1) + FibonacciImpl(N - 2);
	}
    }
};



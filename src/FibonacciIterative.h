
#pragma once
#include "FiboBase.h"

struct FibonacciIterative: FiboBase
{
	
	std::unique_ptr<ITask> Clone() override
	{
		return std::make_unique<FibonacciIterative>();
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

	mpz_class prev = 1;
	mpz_class curr = 1;
	mpz_class temp_curr{};

	N -= 2;
	while(N)
	{
	temp_curr = curr;
	curr += prev;
	prev = temp_curr;

	--N;
	}

	return curr;
     }

};



#pragma once
#include<gmpxx.h>
#include "Task.h"

struct FibonacciRecursive: ITask
{
   std::string Run(const std::vector<std::string>& In) override
    {
    	auto PassN = std::stoi(In[0]);
    	mpz_class value = 0;
    	if(PassN)
    	{	
    		value = FibonacciImpl(PassN);
    	}
    	
    	return value.get_str();
    }
    
    
    std::unique_ptr<ITask> Clone() override
    {
    
    	return std::make_unique<FibonacciRecursive>();
    }
    
private:
    mpz_class FibonacciImpl(mpz_class N)
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



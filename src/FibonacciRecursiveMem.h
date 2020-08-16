
#pragma once
#include "Task.h"
#include<gmpxx.h>

struct FibonacciRecursiveMem: ITask
{
	std::string Run(const std::vector<std::string>& In) override
	{
	    auto PassN = std::stoi(In[0]);
    	    mpz_class value = 0;
    	    
    	    if(PassN)
    	    {
	    	value = FibonacciImpl(std::stoi(In[0]));
	    }
	    	    	
	    return value.get_str();
	}
	    
	    
	std::unique_ptr<ITask> Clone() override
 	{
	    return std::make_unique<FibonacciRecursiveMem>();
	}

 private:

	mpz_class FibonacciImpl(mpz_class N)
	{
		if(!N)
		{
			return 0;
		}
	
		v.resize(N.get_ui());
		v[0] = 1;
		v[1] = 1;

		return RecursiveFibonacci(N);
	}
	
	mpz_class RecursiveFibonacci(mpz_class member)
	{
	auto index = member.get_ui() - 1;

	if(v[index] == 0)
	{
	   v[index] = RecursiveFibonacci(member - 1) + RecursiveFibonacci(member - 2);
	}

	return v[index];
	}

 	std::vector<mpz_class> v;
};



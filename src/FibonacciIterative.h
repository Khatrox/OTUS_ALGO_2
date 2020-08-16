
#pragma once
#include "Task.h"
#include<gmpxx.h>

struct FibonacciIterative: ITask
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
	    return std::make_unique<FibonacciIterative>();
	}

private:

    mpz_class FibonacciImpl(mpz_class N)
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



#pragma once
#include "Task.h"
#include <iostream>
#include <gmpxx.h>

struct FiboBase: ITask
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

 private:

    virtual mpz_class FibonacciImpl(std::size_t N) = 0;

};




#pragma once

#include "Task.h"
#include<gmpxx.h>
#include <cmath>

struct FibonacciGoldenRatio: ITask
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
    
    	return std::make_unique<FibonacciGoldenRatio>();
    }
    

private:
    
    mpz_class FibonacciImpl(mpz_class N)
    {   	
	double f = (1 + sqrt(5)) / 2;
	auto f_in_N = std::pow(f,N.get_ui());
	f_in_N /= sqrt(5);
	f_in_N += 0.5;

	return f_in_N;
     }
};


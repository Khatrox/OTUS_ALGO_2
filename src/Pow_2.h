//
// Created by xMellox on 04-Aug-20.
//

#pragma once
#include "Task.h"
#include <gmpxx.h>
#include <sstream>

struct Pow_2: ITask
{
    std::string Run(const std::vector<std::string>& In) override
    {
    	auto value = Pow_Impl(std::stoi(In[0]),std::stoi(In[1]));
    	std::stringstream ss;
    	ss << value;
    	return ss.str();
    }
    
    
    std::unique_ptr<ITask> Clone() override
    {
    
    	return std::make_unique<Pow_2>();
    }
    
    private:
    
    mpf_class Pow_Impl(mpf_class x, uint64_t y)
    {
	if(y == 0)
    	{
    		return 1;
    	}
    	
	auto r{x};

	for(std::size_t CurrN{1}; CurrN != y;)
	{
		if((CurrN * 2) < y)
		{
			r *= r;
			CurrN *= 2;
		}
		else
		{
			r *= x;
			++CurrN;
		}
	}

	return r;
     }

};


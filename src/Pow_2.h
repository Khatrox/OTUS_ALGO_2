//
// Created by xMellox on 04-Aug-20.
//

#pragma once
#include "PowBase.h"
#include <gmpxx.h>

struct Pow_2: PowBase
{   
    std::unique_ptr<ITask> Clone() override
    {
    	return std::make_unique<Pow_2>();
    }
    
    private:
    
    mpf_class Pow_Impl(mpf_class x, uint64_t y) override
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


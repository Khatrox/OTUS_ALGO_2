//
// Created by xMellox on 04-Aug-20.
//

#pragma once
#include "PowBase.h"
#include <gmpxx.h>

struct Pow_3: PowBase
{   
    std::unique_ptr<ITask> Clone() override
    {
    	return std::make_unique<Pow_3>();
    }
    
    private:
    
    mpf_class Pow_Impl(mpf_class x, uint64_t y) override
    {
	mpf_class res = 1;

	while(y > 0)
	{
		if(y % 2 == 1)
		{
		    res *= x;
		    if(y == 1)
		    {
			break;
		    }
		}

		y /= 2;
		x *= x;
	}

	return res;
     }

};


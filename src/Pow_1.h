//
// Created by xMellox on 04-Aug-20.
//

#pragma once
#include "PowBase.h"

struct Pow_1: PowBase
{   
    std::unique_ptr<ITask> Clone() override
    {
    	return std::make_unique<Pow_1>();
    }
    
    private:
    
    mpf_class Pow_Impl(mpf_class x, uint64_t y) override
    {
	
       mpf_class r = 1;

       while(y--)
       {
         r *=  x;
       }

       return r;
    }
     

};


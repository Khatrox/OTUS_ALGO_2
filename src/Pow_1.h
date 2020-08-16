//
// Created by xMellox on 04-Aug-20.
//

#pragma once
#include "Task.h"
#include <gmpxx.h>
#include <sstream>

struct Pow_1: ITask
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
    
    	return std::make_unique<Pow_1>();
    }
    
    private:
    
    mpf_class Pow_Impl(mpf_class x, uint64_t y)
    {
	
       mpf_class r = 1;

       while(y)
       {
         r *=  x;
         
         --y;
	}

       return r;
    }
     

};


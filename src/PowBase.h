//
// Created by xMellox on 04-Aug-20.
//

#pragma once
#include "Task.h"
#include <gmpxx.h>

struct PowBase: ITask
{
    std::string Run(const std::vector<std::string>& In) override
    {
    	auto value = Pow_Impl(std::stod(In[0]),std::stoul(In[1]));
    	return std::to_string(value.get_d());
    }
    
    private:
    
    virtual mpf_class Pow_Impl(mpf_class x, uint64_t y) = 0;

};



#pragma once
#include "Task.h"

struct PrimesBase: ITask
{   

   std::string Run(const std::vector<std::string>& In) override
   {
      auto arg = std::stoull(In[0]);
      
      auto r = GetPrimes_Impl(arg);
      
      return std::to_string(r);
   }

    virtual std::size_t GetPrimes_Impl(std::size_t N) = 0;  

};


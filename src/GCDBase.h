
#pragma once

#include "Task.h"
#include "gmpxx.h"
#include "gmp.h"

struct GCDBase : ITask
{
    std::string Run(const std::vector<std::string>& In) override
    {
        mpz_class first{In[0]};
	mpz_class second{In[1]};
	mpz_class r = GCD_Impl(first,second);
	
	return r.get_str();
    }

   virtual mpz_class GCD_Impl(mpz_class a, mpz_class b) = 0;
};

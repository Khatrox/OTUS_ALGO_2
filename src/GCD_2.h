
#pragma once
#include "GCDBase.h"

struct GCD_2: GCDBase
{   
    std::unique_ptr<ITask> Clone() override
    {
    	return std::make_unique<GCD_2>();
    }
    
    mpz_class GCD_Impl(mpz_class a, mpz_class b) override
    {
    	    a %= b;
    	    while(a not_eq 0)
   	    {
       		 a.swap(b);
      		 a %= b;
    	    }

    		return b;
    }
     

};


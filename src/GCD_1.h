
#pragma once
#include "GCDBase.h"

struct GCD_1: GCDBase
{   
    std::unique_ptr<ITask> Clone() override
    {
    	return std::make_unique<GCD_1>();
    }
    
    mpz_class GCD_Impl(mpz_class a, mpz_class b) override
    {
	 if(a < b)
    	 {
            a.swap(b);
         }
	
          while(a > b)
    	  {
        	a -= b;

      		while (b > a)
                {
                   b -= a;
                }
          }

          return a;
    }
     

};


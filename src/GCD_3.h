
#pragma once
#include "GCDBase.h"

struct GCD_3: GCDBase
{   
    std::unique_ptr<ITask> Clone() override
    {
    	return std::make_unique<GCD_3>();
    }
    
    mpz_class GCD_Impl(mpz_class a, mpz_class b) override
    {
    	   mpz_class r_gcd{1};

          while((a bitand 1) == 0 and (b bitand 1) == 0)
          {
             a >>= 1;
             b >>= 1;
             r_gcd *= 2;
          }

          while(a not_eq b)
          {
              while((a bitand 1) == 0 xor (b bitand 1) == 0)
              {
                 if ((a bitand 1) == 0)
                 {
                    a >>= 1;
                 }

                 if ((b bitand 1) == 0)
                 {
                   b >>= 1;
                 }
              }

             if (((a bitand 1) == 1) and ((b bitand 1) == 1))
             {
                if (a > b)
                {
                    a -= b;
                }
                else if (b > a)
                {
                    b -= a;
                }
                else
                {
                  r_gcd *= a;
                }
             }

          }
 
       return r_gcd;
    }
     

};




#pragma once
#include "PrimesBase.h"
#include <list>
#include <iostream>

struct Primes_Opt_3: PrimesBase
{   
          std::unique_ptr<ITask> Clone() override
          {
                    return std::make_unique<Primes_Opt_3>();
          }


       std::size_t GetPrimes_Impl(std::size_t num) override
       {

          for(std::size_t i{2}; i <= num; ++i)
          {
                    if(IsPrime(i))
                    {
                        primes.push_back(i);
                    }
          }

          auto r = primes.size();
          primes.clear();

          return r;
        }

private:

    [[nodiscard]] bool IsPrime(std::size_t val) const noexcept
    {
        std::size_t sq_root_val = sqrt(val);
        for(auto it = primes.cbegin(); (it != std::end(primes)) and (*it <= sq_root_val); ++it)
        {
            if((val % *it) == 0)
            {
                return false;
            }
        }

        return true;
    }

    std::list<std::size_t> primes;
};
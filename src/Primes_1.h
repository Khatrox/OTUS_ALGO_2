
#pragma once
#include "PrimesBase.h"

struct Primes_1: PrimesBase
{   
          std::unique_ptr<ITask> Clone() override
          {
                    return std::make_unique<Primes_1>();
          }
          
          private:
          
          std::size_t GetPrimes_Impl(std::size_t N) override
          {
                    std::size_t r{};

                    for(std::size_t num{2}; num <= N; ++num)
                    {
                              if(IsPrime(num))
                              {
                                        ++r;
                              }
                    }

                    return r;
          }
                    
          
          bool IsPrime(std::size_t num) noexcept
          {

                    for(std::size_t val{2}; val < num; ++val)
                    {
                              if(num % val == 0)
                              {
                                        return false;
                              }
                    }

                    return true;
          }
};

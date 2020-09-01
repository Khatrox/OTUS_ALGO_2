

#pragma once
#include "PrimesBase.h"
#include <list>
#include <iostream>

struct Sieve_1: PrimesBase
{   
          using byte = unsigned char;

          std::unique_ptr<ITask> Clone() override
          {
                    return std::make_unique<Sieve_1>();
          }


         std::size_t GetPrimes_Impl(std::size_t N) override
         {
           if(!N || N == 1) return 0;
           else if(N == 2) return 1;
           else if(N == 3) return 2;
           else if(N == 5) return 3;

           std::vector<byte> v;
           v.resize(N);

           auto sq_root = sqrt(N);

          for(std::size_t i{2}; i <= sq_root; ++i)
          {
                    if(v[i] == 0)
                    {
                              for (std::size_t j{i * i}; j < v.size(); j += i)
                              {
                                         v[j] = 1;
                              }
                    }
          }

          std::size_t r{};
           
          ExcludeZeroAndOne(v);

          for(const auto i : v)
          {
                    if(i == 0)
                    {
                              r += 1;
                    }
          }

          return r;
        }


        void ExcludeZeroAndOne(std::vector<byte>& v)
        {
                    v[0] = 1;
                    v[1] = 1;
        }

};
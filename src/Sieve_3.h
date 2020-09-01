
#pragma once
#include "PrimesBase.h"
#include <list>

struct Sieve_3: PrimesBase
{   
          std::unique_ptr<ITask> Clone() override
          {
                    return std::make_unique<Sieve_3>();
          }

    std::size_t GetPrimes_Impl(std::size_t N) override
    {
        std::vector<std::size_t> v_lp;
        std::vector<std::size_t> v_pr;

        v_lp.resize(N + 1);
        v_pr.reserve(N / 2);

        for(std::size_t i{2}; i <= N; ++i)
        {
            if(v_lp[i] == 0)
            {
                v_lp[i] = i;
                v_pr.push_back(i);
            }

            for(std::size_t p{}; p < v_pr.size() and (v_pr[p] <= v_lp[i]) and ((v_pr[p] * i) <= N); ++p)
            {
               v_lp[v_pr[p] * i] = v_pr[p];
            }
        }

        return v_pr.size();
    }
};

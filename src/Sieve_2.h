

#pragma once
#include "PrimesBase.h"
#include <list>
#include <iostream>

struct Sieve_2: PrimesBase
{   
    using Elem = uint32_t;

          std::unique_ptr<ITask> Clone() override
          {
                    return std::make_unique<Sieve_2>();
          }

    std::size_t GetPrimes_Impl(std::size_t N) override
    {
        until_bit = N % elem_bit_size;
        auto resize_to = N / elem_bit_size;

        if (resize_to && !until_bit)
        {
            until_bit = elem_bit_size;
        }
        else
        {
            resize_to += 1;
        }

        v.resize(resize_to);

        std::size_t sq_root_N = sqrt(N);
        for(std::size_t i{2}; i <= sq_root_N; ++i)
        {
            if(IsZeroBit(i))
            {
                for (std::size_t j{i * i}; j <= N; j += i)
                {
                    SetNum(j);
                }
            }
        }

        return GetZeroBits() - 1;
    }

    [[nodiscard]] bool IsZeroBit(std::size_t num) const noexcept
    {
        const auto [bit, index] = GetBitAndIndexOf(num);
        
        const auto value = v[index];
        
        return (value bitand bit) == 0;
    }

    void SetNum(std::size_t num) noexcept
    {
        const auto [bit, index] = GetBitAndIndexOf(num);

        auto& val = v[index];

        val = val bitor bit;
    }

    std::pair<std::size_t,std::size_t> GetBitAndIndexOf(std::size_t num) const noexcept
    {
        std::pair<std::size_t,std::size_t> bit_index;
        bit_index.second = num / elem_bit_size;
        bit_index.first = num % elem_bit_size;

        if(bit_index.first == 0)
        {
            bit_index.second -= 1;
            bit_index.first = elem_bit_size;
        }

        bit_index.first -= 1;

        std::size_t v_bit{1};
        v_bit <<= bit_index.first;

        bit_index.first = v_bit;

        return bit_index;
    }
    

    [[nodiscard]]std::size_t GetZeroBits() const noexcept
    {
        std::size_t r{};
        std::size_t until_bites = elem_bit_size;

        for(std::size_t i{}; i < v.size(); ++i)
        {
            if(i == (v.size() - 1))
            {
                until_bites = until_bit;
            }

            for(std::size_t j{1}, bit_i{1}; j <= until_bites; j += 1, bit_i <<= 1)
            {
                if((v[i] bitand bit_i) == 0)
                {
                    r += 1;
                }
            }
        }

        return r;
    }


private:
    static constexpr std::size_t elem_bit_size = sizeof(Elem) * 8;
    std::vector<Elem> v;
    std::size_t until_bit;
};

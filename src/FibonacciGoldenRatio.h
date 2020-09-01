
#pragma once

#include "FiboBase.h"

struct FibonacciGoldenRatio: FiboBase
{   
    std::unique_ptr<ITask> Clone() override
    {
    
    	return std::make_unique<FibonacciGoldenRatio>();
    }
    
private:
    
    mpz_class FibonacciImpl(std::size_t N) override
    {   	
	mpf_class sqrt_5{5,500};
    	mpf_sqrt(sqrt_5.__get_mp(),sqrt_5.__get_mp());
  	mpf_class f{0, 500};
    	f = sqrt_5;
    	f += 1;
    	f /= 2;
    	mpf_class f_in_N{f,500};
    	mpf_pow_ui(f_in_N.__get_mp(), f_in_N.__get_mp(), N);
    	f_in_N /= sqrt_5;
    	f_in_N += 0.5;
    	mpf_floor(f_in_N.__get_mp(),f_in_N.__get_mp());
	mp_exp_t exp;
    	auto string = f_in_N.get_str(exp,10,100000);
    	mpz_class fibo_member{string};	

    	return fibo_member;
     }
};


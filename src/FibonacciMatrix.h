
#pragma once
#include "Task.h"
#include<gmpxx.h>
#include <iostream>

using MatrixRow = std::array<mpz_class,2>;
using Matrix_2x2 = std::array<MatrixRow,2>;

Matrix_2x2 MultiplySymmetricMatrix(const Matrix_2x2& left, const Matrix_2x2& right)
{
Matrix_2x2 r;
mpz_class result{};

result += left[0][0] * right[0][0];
result += left[0][1] * right[1][0];
r[0][0] = result;

result = 0;

result += left[0][0] * right[0][1];
result += left[0][1] * right[1][1];

r[0][1] = result;
r[1][0] = result;

result = 0;

result += left[1][0] * right[0][1];
result += left[1][1] * right[1][1];
r[1][1] = result;

return r;
}

struct FibonacciMatrix : ITask
{

	 std::string Run(const std::vector<std::string>& In) override
	 {
		   auto PassN = std::stoi(In[0]);
	    	    mpz_class value = 0;
	    	    
	    	    if(PassN)
	    	    {
		    	value = FibonacciImpl(std::stoi(In[0]));
		    }
		    	    	
		    return value.get_str();
	}
	    
	    
	std::unique_ptr<ITask> Clone() override
 	{
	    return std::make_unique<FibonacciIterative>();
	}
	
	
private:
    mpz_class FibonacciImpl(mpz_class n)
    {

	if(n == 0)
	{
	   return 0;
	}

	//because of relation in formula {1,1}^N = {Fn+1; Fn}
	// {1,0} {Fn; Fn-1}
	//We can make less operations but get same results if substract 1
	// {1,1}^N-1 = {Fn; Fn-1}
	// {1,0} {Fn-1; Fn-2}

	--n;

	Matrix_2x2 FibonacciMatrix{MatrixRow{1,1}, MatrixRow{1,0}};
	Matrix_2x2 r_Matrix{MatrixRow{1,0}, MatrixRow{0,1}};

	while(n > 0)
	{
	std::cout << n << '\n';
		if((n % 2) == 1)
		{
			r_Matrix = MultiplySymmetricMatrix(r_Matrix,FibonacciMatrix);
			if(n == 1)
			{
				break;
			}
		}

		n /= 2;
		FibonacciMatrix = MultiplySymmetricMatrix(FibonacciMatrix,FibonacciMatrix);
	}

	return r_Matrix[0][0];
     }

};


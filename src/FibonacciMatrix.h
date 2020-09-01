
#pragma once
#include "FiboBase.h"

using MatrixRow = std::array<mpz_class,2>;
using Matrix_2x2 = std::array<MatrixRow,2>;

Matrix_2x2 MultiplySymmetricMatrix(const Matrix_2x2& left, const Matrix_2x2& right)
{
    Matrix_2x2 r;

    r[0][0] = left[0][0] * right[0][0] + left[0][1] * right[1][0];
    r[0][1] = left[0][0] * right[0][1] +  left[0][1] * right[1][1];
    r[1][0] = r[0][1];
    r[1][1] = left[1][0] * right[0][1] + left[1][1] * right[1][1];

    return r;
}

struct FibonacciMatrix : FiboBase
{	    	    
	std::unique_ptr<ITask> Clone() override
 	{
	    return std::make_unique<FibonacciMatrix>();
	}
	
	
private:
    mpz_class FibonacciImpl(std::size_t n) override
    {
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


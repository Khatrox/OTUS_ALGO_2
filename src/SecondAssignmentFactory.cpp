//
// Created by xMellox on 11-Aug-20.
//

#include "SecondAssignmentFactory.h"
#include "Pow_1.h"
#include "Pow_2.h"
#include "Pow_3.h"
#include "GCD_1.h"
#include "GCD_2.h"
#include "GCD_3.h"
#include "Primes_1.h"
#include "Primes_Opt_1.h"
#include "Primes_Opt_2.h"
#include "Primes_Opt_3.h"
#include "Sieve_1.h"
#include "Sieve_2.h"
#include "Sieve_3.h"
#include "FibonacciRecursive.h"
#include "FibonacciRecursiveMem.h"
#include "FibonacciIterative.h"
#include "FibonacciGoldenRatio.h"
#include "FibonacciMatrix.h"

SecondAssignmentFactory::SecondAssignmentFactory()
{
	m_tasks.insert(std::make_pair("Pow_1", std::make_unique<Pow_1>()));
	m_tasks.insert(std::make_pair("Pow_2", std::make_unique<Pow_2>()));
	m_tasks.insert(std::make_pair("Pow_3", std::make_unique<Pow_3>()));
          m_tasks.insert(std::make_pair("GCD_1", std::make_unique<GCD_1>()));
	m_tasks.insert(std::make_pair("GCD_2", std::make_unique<GCD_2>()));
          m_tasks.insert(std::make_pair("GCD_3", std::make_unique<GCD_3>()));
	m_tasks.insert(std::make_pair("Primes_1", std::make_unique<Primes_1>()));
	m_tasks.insert(std::make_pair("Primes_Opt_1", std::make_unique<Primes_Opt_1>()));
	m_tasks.insert(std::make_pair("Primes_Opt_2", std::make_unique<Primes_Opt_2>()));
	m_tasks.insert(std::make_pair("Primes_Opt_3", std::make_unique<Primes_Opt_3>()));
	m_tasks.insert(std::make_pair("Sieve_1", std::make_unique<Sieve_1>()));
	m_tasks.insert(std::make_pair("Sieve_2", std::make_unique<Sieve_2>()));
	m_tasks.insert(std::make_pair("Sieve_3", std::make_unique<Sieve_3>()));
	m_tasks.insert(std::make_pair("FibonacciRecursive", std::make_unique<FibonacciRecursive>()));
	m_tasks.insert(std::make_pair("FibonacciRecursiveMem", std::make_unique<FibonacciRecursiveMem>()));
	m_tasks.insert(std::make_pair("FibonacciIterative", std::make_unique<FibonacciIterative>()));
	m_tasks.insert(std::make_pair("FibonacciGoldenRatio", std::make_unique<FibonacciGoldenRatio>()));
	m_tasks.insert(std::make_pair("FibonacciMatrix", std::make_unique<FibonacciMatrix>()));
}


std::unique_ptr<ITask> SecondAssignmentFactory::CreateTask(const std::string &TaskName)
{
    std::unique_ptr<ITask> r{};
    
    auto it = m_tasks.find(TaskName);    
    
    if(it != std::end(m_tasks))
    {
	r = it->second->Clone();    
    }

    return r;
}


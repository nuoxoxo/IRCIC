#pragma once
#ifndef __STACK_HPP__
# define __STACK_HPP__

# include "iostream"
# include "colors.hpp"
# include "typeinfo" // - typeid

namespace	ft
{
	// to be stuffed
}

template<typename T>
void	printer_cleaner_stack(T & st)
{
	std::cout << "(size : " << GREEN << st.size() << RESET << ") \n";
	while ( !st.empty())
	{
		std::cout << ' ' << st.top() << '\n';
		// std::cout << typeid(st.top()).name() << '\n';
		st.pop();
	}
	std::cout << "(size : " << GREEN << st.size() << RESET << ") \n\n";
}

// tests to call in main

/********************************************
*  the main should test the following shit  *
*********************************************/

// = . assign value to container adaptor
//  empty
//  size
//  top
//  push
//  pop
// Member objects: Container C . underlying container
//  ==
//  != 
//  < . <=
//  > . >=
//  emplace . constructs element in-place at the top . XXX

# include "stack"
void	stack_test(void)
{
	std::cout << GREEN "\npush pop empty size" nl2reset;

	int	i = -1;

	std::cout << LOWKEY "\nTest " << ++i << " :: stack<int>"nl2reset;
	{
		std::stack<int>	S;
		S.push(41);
		S.push(42);
		S.push(43);
		printer_cleaner_stack(S);
		// S.pop(); // ----> should segfault with std::stack
	}
	std::cout << LOWKEY "\nTest " << ++i << " :: stack<string>"nl2reset;
	{
		std::stack<std::string>	S;
		S.push("= = = = = = = = = = = = = world");
		S.push("= = = = = = = = = = hello ");
		S.push("= = = = = = =");
		S.push("= = = =");
		S.push("= ");
		printer_cleaner_stack(S);
	}
	std::cout << LOWKEY "\nTest " << ++i << " :: stack<double>"nl2reset;
	{
		std::stack<double>	S;
		S.push(21.21);
		S.push(42.43);
		S.push(196.883);
		printer_cleaner_stack(S);
	}
}



#endif

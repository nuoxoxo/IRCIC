#pragma once
#ifndef __STACK_HPP__
# define __STACK_HPP__

/// #include "vector.hpp"
# include "vector"

# include "iostream"
# include "colors.hpp"
# include "typeinfo" // - typeid

namespace	ft
{
	// TODO
	template < typename T, typename Container = std::vector<T> > // std
	class	Stack
	{
	protected:
		Container	C;
	public:
		// Canon // TODO
		/*
		pair() : first(), second() {}
		~pair() {}

		pair(const T_1 & l, const T_2 & r) : first(l), second(r) {}

		template<typename L, typename R>
		pair(const pair<L, R> & p) : first(p.first), second(p.second) {}
		*/

		// operator // TODO
	}

	// non-member func // TODO
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


// :D

/****************************************************
*      the main should test the following shit      *
****************************************************/

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
# include "stdexcept"

void	stack_test(bool isft)
{
	if (isft) return ;

	std::cout << YELLOW "\n ::: Stack ::: push pop empty size :::" nlreset;

	int	i = -1;

	std::cout << LOWKEY "\nTest " << ++i << " :: stack<int>"nl2reset;
	{
		std::stack<int>	S;
		S.push(41);
		S.push(42);
		S.push(43);
		printer_cleaner_stack(S);
		// S.pop(); // ----> should segfault with std::stack
		// ----> to config in ft::stack
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

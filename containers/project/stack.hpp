#pragma once
#ifndef __STACK_HPP__
# define __STACK_HPP__

# include "iostream"
# include "colors.hpp"
# include "typeinfo" // - typeid

namespace	ft
{
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

#endif

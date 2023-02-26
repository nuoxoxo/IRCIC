#pragma once
#ifndef __PAIR_HPP__
# define __PAIR_HPP__

# include "iostream"

namespace	ft
{
}

template<typename T>
void	printer_cleaner_stack(T & st)
{
	while ( !st.empty())
	{
		cout << st.top() << '\n';
		st.pop();
	}
}

#endif

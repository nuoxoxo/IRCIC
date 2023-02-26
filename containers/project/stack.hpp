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
	template < typename T, typename Container = std::vector<T> > // std //XXX
	class	stack
	{
	protected:
		Container	C;

	public:

		// canon
		explicit stack( const Container & C = Container() );
		// explicit stack( const Container & C = Container() ) : C(C) {}
		~stack();


		stack & operator = (const stack & dummy)
		{
			if (this != & dummy)
				C = dummy.C;
			return (*this);
		}


		// the only accessor : top
		T const	& top() const { return C.back(); }
		T	& top()	{ return C.back(); }


		// size
		bool	empty() const { return C.empty(); }
		size_t	size() const { return C.size(); }


		// operation
		void	push(const T & item) { C.push_back(item); }
		void	pop(void) { C.pop_back(); }


		// friend
		friend bool operator == (const stack &, const stack &);
		friend bool operator != (const stack &, const stack &);
		friend bool operator < (const stack &, const stack &);
		friend bool operator <= (const stack &, const stack &);
		friend bool operator > (const stack &, const stack &);
		friend bool operator >= (const stack&, const stack &);
	};/*

	// define friend func
	friend bool operator == (const stack & L, const stack & R)
	{
		return (L == R);
	}
	friend bool operator != (const stack & L, const stack & R)
	friend bool operator < (const stack & L, const stack & R)
	friend bool operator <= (const stack & L, const stack & R)
	friend bool operator > (const stack & L, const stack & R)
	friend bool operator >= (const stack & L, const stack & R)
*/
};

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

void	stack_test(bool isft)
{
	if (isft) return ;

	std::cout << YELLOW "\n ::: stack ::: push pop empty size :::" nlreset;

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
	std::cout << LOWKEY "\nTest " << ++i << " :: comparison " nl2reset;
	{
		std::stack<double>	S, T;
		S.push(21.21);
		S.push(42.43);
		S.push(196.883);
		T.push(21.21);
		T.push(42.43);
		T.push(196.883);
		

		std::cout << std::boolalpha
		<< (S == T) << " ==, " 
		<< (S != T) << " !=, "
		<< (S < T) << " <, "
		<< (S > T) << " > " << std::noboolalpha << nl2;
		printer_cleaner_stack(S);
		printer_cleaner_stack(T);
	}
	std::cout << LOWKEY "\nTest " << ++i << " :: comparison :: 2˚ "nl2reset;
	{
		std::stack<double>	S, T;
		S.push(21.21);
		S.push(42.43);
		S.push(196.883);
		T.push(21.21);
		T.push(42.43);
		T.push(196.883);

		S.top() = 0;

		std::cout << std::boolalpha
		<< (S == T) << " ==, " 
		<< (S != T) << " !=, "
		<< (S < T) << " <, "
		<< (S > T) << " > " << std::noboolalpha << nl2;
		printer_cleaner_stack(S);
		printer_cleaner_stack(T);
	}
	std::cout << LOWKEY "\nTest " << ++i << " :: comparison :: 3˚ "nl2reset;
	{
		std::stack<double>	S, T;

		S.push(21.21);
		S.push(42.43);
		S.top() = 1000;
		S.push(196.883);

		T.push(21.21);
		T.push(42.43);
		T.push(196.883);


		std::cout << std::boolalpha
		<< (S == T) << " ==, " 
		<< (S != T) << " !=, "
		<< (S < T) << " <, "
		<< (S > T) << " > " << std::noboolalpha << nl2;
		printer_cleaner_stack(S);
		printer_cleaner_stack(T);
	}
}

#endif

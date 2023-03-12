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
		// explicit stack( const Container & C = Container() ); // qx
		// explicit stack( const Container & C = Container() ) {} // mine
		explicit stack( const Container & C = Container() ) : C(C) {}
		~stack() {}


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


		// friend . 1st way

		friend bool operator == (const stack & L, const stack & R)
		{
			return (L.C == R.C);
			// compare the m_C otherwise warning "all paths call itself"
		}

		friend bool operator != (const stack & L, const stack & R)
		{
			return (L.C != R.C);
		}

		friend bool operator < (const stack & L, const stack & R)
		{
			return (L.C < R.C);
		}

		friend bool operator <= (const stack & L, const stack & R)
		{
			return (L.C <= R.C);
		}

		friend bool operator > (const stack & L, const stack & R)
		{
			return (L.C > R.C);
		}

		friend bool operator >= (const stack & L, const stack & R)
		{
			return (L.C >= R.C);
		}

		// friend . 2nd way (1/2)

		/*
		friend bool operator == (const stack &, const stack &);
		friend bool operator != (const stack &, const stack &);
		friend bool operator < (const stack &, const stack &);
		friend bool operator <= (const stack &, const stack &);
		friend bool operator > (const stack &, const stack &);
		friend bool operator >= (const stack &, const stack &);
		*/

	};


	// friend . 2nd way (2/2)

	/*
	// define friend func
	template<typename T>
	bool operator == (const stack<T> & L, const stack<T> & R)
	{
		return (L == R);
	}

	template<typename T>
	bool operator != (const stack<T> & L, const stack<T> & R)
	{
		return (L != R);
	}

	template<typename T>
	bool operator < (const stack<T> & L, const stack<T> & R)
	{
		return (L < R);
	}

	template<typename T>
	bool operator <= (const stack<T> & L, const stack<T> & R)
	{
		return (L <= R);
	}

	template<typename T>
	bool operator > (const stack<T> & L, const stack<T> & R)
	{
		return (L > R);
	}

	template<typename T>
	bool operator >= (const stack<T> & L, const stack<T> & R)
	{
		return (L >= R);
	}
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

template<typename T>
void	printer_compare_boolalpha(const T & s, const T & t)
{
	std::cout << std::boolalpha
	<< (s == t) << " ==, " 
	<< (s != t) << " !=, "
	<< (s < t) << " <, "
	<< (s > t) << " > " << std::noboolalpha << nl2;
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


void	stack_test_isstd()
{
	int	i = -1;

	std::cout << LOWKEY "\nTest " << ++i << " :: std::stack<int>"nl2reset;
	{
		std::stack<int>	S;
		S.push(41);
		S.push(42);
		S.push(43);
		printer_cleaner_stack(S);
		// S.pop(); // ----> should segfault with std::stack
		// ----> to config in ft::stack
	}
	std::cout << LOWKEY "\nTest " << ++i << " :: std::stack<string>"nl2reset;
	{
		std::stack<std::string>	S;
		S.push("= = = = = = = = = = = = = world");
		S.push("= = = = = = = = = = hello ");
		S.push("= = = = = = =");
		S.push("= = = =");
		S.push("= ");
		printer_cleaner_stack(S);
	}
	std::cout << LOWKEY "\nTest " << ++i << " :: std::stack<double>"nl2reset;
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

		printer_compare_boolalpha(S, T);
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

		printer_compare_boolalpha(S, T);
		printer_cleaner_stack(S);
		printer_cleaner_stack(T);
	}
}



void	stack_test_isft()
{
	int	i = -1;

	std::cout << LOWKEY "\nTest " << ++i << " ::  ft::stack<int>"nl2reset;
	
	ft::stack<int>	S;

	{
		ft::stack<int>	S;
		S.push(41);
		S.push(42);
		S.push(43);
		printer_cleaner_stack(S);
		// S.pop(); // ----> should segfault with std::stack
		// ----> to config in ft::stack
	}
	std::cout << LOWKEY "\nTest " << ++i << " ::  ft::stack<string>"nl2reset;
	{
		ft::stack<std::string>	S;
		S.push("= = = = = = = = = = = = = world");
		S.push("= = = = = = = = = = hello ");
		S.push("= = = = = = =");
		S.push("= = = =");
		S.push("= ");
		printer_cleaner_stack(S);
	}
	std::cout << LOWKEY "\nTest " << ++i << " ::  ft::stack<double>"nl2reset;
	{
		ft::stack<double>	S;
		S.push(21.21);
		S.push(42.43);
		S.push(196.883);
		printer_cleaner_stack(S);
	}
	std::cout << LOWKEY "\nTest " << ++i << " :: comparison " nl2reset;
	{
		ft::stack<double>	S, T;
		S.push(21.21);
		S.push(42.43);
		S.push(196.883);
		T.push(21.21);
		T.push(42.43);
		T.push(196.883);
		

		printer_compare_boolalpha(S, T);
		printer_cleaner_stack(S);
		printer_cleaner_stack(T);
	}
	std::cout << LOWKEY "\nTest " << ++i << " :: comparison :: 2˚ "nl2reset;
	{
		ft::stack<double>	S, T;
		S.push(21.21);
		S.push(42.43);
		S.push(196.883);
		T.push(21.21);
		T.push(42.43);
		T.push(196.883);

		S.top() = 0;

		printer_compare_boolalpha(S, T);
		printer_cleaner_stack(S);
		printer_cleaner_stack(T);
	}
	std::cout << LOWKEY "\nTest " << ++i << " :: comparison :: 3˚ "nl2reset;
	{
		ft::stack<double>	S, T;

		S.push(21.21);
		S.push(42.43);
		S.top() = 1000;
		S.push(196.883);

		T.push(21.21);
		T.push(42.43);
		T.push(196.883);


		printer_compare_boolalpha(S, T);
		printer_cleaner_stack(S);
		printer_cleaner_stack(T);
	}
}



void	stack_test(bool isft)
{
	if (isft)
	{
		std::cout
		<< YELLOW "\n ::: ft::stack ::: push pop empty size :::" nlreset;
		stack_test_isft();
		return ;
	}

	std::cout
	<< YELLOW "\n ::: std::stack ::: push pop empty size :::" nlreset;
	stack_test_isstd();
}



#endif

#include "iostream"
#include "colors.hpp"
#include "pair.hpp"
#include "stack.hpp"
#include "stack" // - to delete

int	main()
{
	// {pair_test();} // hey
	{
		std::stack<int>	S;
		S.push(41);
		S.push(42);
		S.push(43);
		printer_cleaner_stack(S);
	}
}

/********************************************
*  the main should test the following shit  *
*********************************************/

/* stack */

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


/* pair */

// = . assign contents
// make_pair()
//  ==
//  != 
//  < . <=
//  > . >=



#ifndef __EQUAL_HPP__
# define __EQUAL_HPP__

namespace ft
{
	template<typename InputIt1, typename InputIt2>
	bool    equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		while (first1 != last1)
		{
			if ( !(* first1 == * first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	}

	template<typename InputIt1, typename InputIt2, typename BinaryPredicate>
	bool    equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate bp)
	{
		while (first1 != last1)
		{
			if ( !bp(* first1, * first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	}
}

#endif


#include "iostream"
#include "algorithm"
#include "vector"
#include "iterator"


/* 
 * 
 * doesn't work this way 
 *
 */

int	main()
{
	std::vector<int> v = { 10, 20, 30, 40, 50 };

	auto it = v.begin(); // it points to the 1st element of v
	std::cout << *it << "\n";

	std::advance(it, 3); // it now points to the 4th element of v
	std::cout << *it << "\n";

	/// advance Impl. of std::advance
	/*

	auto iter = v.begin();

	advance_impl(iter, 3, std::random_access_iterator_tag tag);
	std::cout << *it << "\n";

	*/
	/* doesn't work this way */
}

// below : not part of the above

template<typename Iterator, typename Distance>
void	advance_impl(Iterator & it, Distance n, std::forward_iterator_tag)
{
	while (--n > -1)
		++it;
}

template<typename Iterator, typename Distance>
void	advance_impl(Iterator & it, Distance n, std::random_access_iterator_tag)
{
	it += n;
}

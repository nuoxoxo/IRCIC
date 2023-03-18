#include "iostream"
#include "PmergeMe.hpp"


int	main(int c, char *v[])
{
	std::vector<int>	a;
	std::deque<int>		d, dd;
	struct timeval		tv_start, tv_end;

	int		i;
	int		n;
	long long	start, end, diff_1, diff_2, diff_3;


	if (c < 2)
		return (_usage_("no number given. exit now."), 1);


	if (gettimeofday( & tv_start, NULL)) // timing data mgmt :: head
		return (1);
	i = 0;
	while (++i < c)
	{
		if ( !isnumeric(v[i]))
			return (_usage_("non numeric value detected. exit now."), 1);
		std::stringstream(v[i]) >> n;
		if ( !n)
			return (_usage_("we have a zero here. exit now."), 1);
		a.push_back(n);
		d.push_back(n);
		dd.push_back(n);
	}
	if (gettimeofday( & tv_end, NULL)) // timing data mgmt :: tail
		return (1);

	start = tv_start.tv_usec;
	end = tv_end.tv_usec;
	diff_1 = end - start;
	diff_2 = diff_1;
	diff_3 = diff_2;


	print_vector(a, BEFORE);// print unsorted list


	// sort std::vector
	if (gettimeofday( & tv_start, NULL))
		return (1);
	merge_sort(a);
	if (gettimeofday( & tv_end, NULL))
		return (1);
	start = tv_start.tv_usec;
	end = tv_end.tv_usec;
	diff_1 += end - start;


	// sort std::deque - generic
	if (gettimeofday( & tv_start, NULL))
		return (1);
	merge_sort(d, USE_DIY);
	if (gettimeofday( & tv_end, NULL))
		return (1);
	start = tv_start.tv_usec;
	end = tv_end.tv_usec;
	diff_2 += end - start;


	// sort std::deque - STL
	if (gettimeofday( & tv_start, NULL))
		return (1);
	merge_sort(dd, USE_STL);
	if (gettimeofday( & tv_end, NULL))
		return (1);
	start = tv_start.tv_usec;
	end = tv_end.tv_usec;
	diff_3 += end - start;


	print_vector(a, AFTER);// print sorted list


	// compare delta time
	std::cout
	<< "Time to process a range of " << CYAN << a.size() << "\t" RESET
	<< " elements with std::vector :\t" << diff_1 << " us\n";

	std::cout
	<< "Time to process a range of " << CYAN << d.size() << "\t" RESET
	<< " elements with std::deque :\t" << diff_2 << " us (generic)\n";

	std::cout
	<< "Time to process a range of " << CYAN << d.size() << "\t" RESET
	<< " elements with std::deque :\t" << diff_3 << " us (STL)\n";

}


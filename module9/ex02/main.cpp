#include "iostream"
#include "PmergeMe.hpp"

int	main(int c, char *v[])
{
	std::vector<long long>	a, aa;
	std::deque<long long>	d, dd;
	struct timeval		tv_start, tv_end;

	unsigned long long	temp;
	long long		start, end, diff_1, diff_2, diff_3, diff_4;
	long long		n;
	int			i;

	if (c < 2)
		return (_usage_("no number given. exit now."), 1);


	// ::: START - timing spent on Data Mgmt ::: //
	if (gettimeofday( & tv_start, NULL))
		return (1);

	i = 0;
	while (++i < c)
	{
		if ( !isnumeric(v[i]))
			return (_usage_("non numeric value detected. exit now."), 1);
		std::stringstream(v[i]) >> temp;
		if (temp > 9223372036854775807 /* 2147483647 */)
			return (_usage_("integer too big. exit now."), 1);
		if (!temp)
			return (_usage_("we have a zero here. exit now."), 1);
		n = (long long) temp;

		a.push_back(n);
		aa.push_back(n);

		d.push_back(n);
		dd.push_back(n);
	}

	if (gettimeofday( & tv_end, NULL))
		return (1);

	start = tv_start.tv_usec; // time spent on data mgmt
	end = tv_end.tv_usec;
	diff_1 = end - start;
	diff_2 = diff_1;
	diff_3 = diff_2;
	diff_4 = diff_3;
	// ::: END ::: //


	print_container(a, BEFORE);// print unsorted list


	// ::: START - generic sort on Vector ::: //
	if (gettimeofday( & tv_start, NULL))
		return (1);

	merge_sort(a, DIY);

	if (gettimeofday( & tv_end, NULL))
		return (1);

	start = tv_start.tv_usec;
	end = tv_end.tv_usec;

	diff_1 += end - start;
	// ::: END ::: //


	// ::: START - generic sort on Deque ::: //
	if (gettimeofday( & tv_start, NULL))
		return (1);
	merge_sort(d, DIY);
	if (gettimeofday( & tv_end, NULL))
		return (1);
	start = tv_start.tv_usec;
	end = tv_end.tv_usec;
	diff_2 += end - start;
	// ::: END ::: //


	// ::: START - STL sort on Vector ::: //
	if (gettimeofday( & tv_start, NULL))
		return (1);
	merge_sort(aa, STL);
	if (gettimeofday( & tv_end, NULL))
		return (1);
	start = tv_start.tv_usec;
	end = tv_end.tv_usec;
	diff_3 += end - start;
	// ::: END ::: //


	// ::: START - STL sort on Deque ::: //
	if (gettimeofday( & tv_start, NULL))
		return (1);
	merge_sort(dd, STL);
	if (gettimeofday( & tv_end, NULL))
		return (1);
	start = tv_start.tv_usec;
	end = tv_end.tv_usec;
	diff_4 += end - start;
	// ::: END ::: //


	print_container(a, AFTER);// print sorted list
	// print_container(aa, AFTER);// print sorted list
	// print_container(d, AFTER);// print sorted list
	// print_container(dd, AFTER);// print sorted list


	// Print delta time
	std::cout
	<< "Time to process a range of " << CYAN << a.size() << "\t" RESET
	<< " elements with std::vector :\t" << diff_1 << " us" nl;

	std::cout
	<< "Time to process a range of " << CYAN << d.size() << "\t" RESET
	<< " elements with std::deque :\t" << diff_2 << " us" nl;

	//std::cout << nl;

	std::cout
	<< "Time to process a range of " << CYAN << aa.size() << "\t" RESET
	<< " elements with std::vector :\t" GREEN << diff_3 << RESET " us (STL)" nl;

	std::cout
	<< "Time to process a range of " << CYAN << dd.size() << "\t" RESET
	<< " elements with std::deque :\t" GREEN << diff_4 << RESET " us (STL)" nl;

}


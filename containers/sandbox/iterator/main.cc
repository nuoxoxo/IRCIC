#include "iostream"
#include "iterator" // iterator_tag
#include "cstddef"  // ptrdiff_t
#include "algorithm" // fill

#define SIZE 12

class	Integers
{
private:
	int	m_data[ SIZE ];
public:
	Integers() { for (int i = 0; i < SIZE; i++) m_data[i] = 0; }
	// class Iterator
	struct	Iterator
	{
		using iterator_category	= std::forward_iterator_tag;
		using difference_type	= std::ptrdiff_t;
		using value_type	= int;
		using pointer           = int*;
		using reference		= int &;

		Iterator(pointer ptr) : m_ptr(ptr) {}

		/*
		// wrapper method 1: begin
		Iterator begin()
		{ return Iterator( & m_data[0] ); }

		// wrapper method 2: end
		Iterator end()
		{ return Iterator( & m_data[ SIZE ] ); } // 1st invalid memory zone
		*//* FIXME :: (major fix) */

		// accessor dereferencer
		reference operator * () const { return (*m_ptr); }
		pointer operator -> () { return (m_ptr); }

		// pre ++
		Iterator & operator ++ () { m_ptr++; return (*this); }

		// post ++
		Iterator operator ++ (int)
		{ Iterator tmp = *this; ++(*this); return (tmp); }

		// friend == 
		friend bool operator == (const Iterator & l, const Iterator & r)
		{ return (l.m_ptr == r.m_ptr); }

		// friend !=
		friend bool operator != (const Iterator & l, const Iterator & r)
		{ return (l.m_ptr != r.m_ptr); }


	private:
		pointer	m_ptr;

	};

	// wrapper method 1: begin
	Iterator begin()
	{ return Iterator( & m_data[0] ); }

	// wrapper method 2: end
	Iterator end()
	{ return Iterator( & m_data[ SIZE ] ); } // 1st invalid memory zone
};

template<class T>
void	FILL(T &);

int	main()
{
	Integers	integers;

	// print object using auto
	for (auto i: integers)	std::cout << i << "\n";
	std::cout << "\n";

	// print object using begin/end
	for (auto it = integers.begin(), end = integers.end(); it != end; ++it) {
		const auto i = *it;
		std::cout << i << "\n";
	}

	// print an object filled with 42
	std::cout << "\n";
	srand(time(0));
	std::fill(integers.begin(), integers.end(), 42);
	for (auto i: integers)	std::cout << i << "\n";

	// print an object with random integers
	std::cout << "\n";
	srand(time(0));
	FILL(integers);
	for (auto i: integers)	std::cout << i << "\n";
}

template<class T>
void	FILL(T & m)
{
	for (auto it = m.begin(); it != m.end(); ++it)
		*it = rand() % 100;
}

